// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	UE_LOG(LogTemp, Warning, TEXT("UTankTrack"));
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::BeginPlay()
{
	PrimaryComponentTick.bCanEverTick = true;
	FString canTickString = PrimaryComponentTick.bCanEverTick ? "true" : "false";
	UE_LOG(LogTemp, Warning, TEXT("BeginPLay, bCanEverTick: %s"), *canTickString);

	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	bool isInContact = false; // wrong level of abstraction here
	
	// below has side-effects, it's not jsut asking a question, it's already applied the force
	isInContact |= ApplySpringForce(DeltaTime, SpringSideOffset * GetRightVector() + SpringHeightOffset * GetUpVector() + SpringFrontOffset * GetForwardVector());
	isInContact |= ApplySpringForce(DeltaTime, SpringSideOffset * GetRightVector() + SpringHeightOffset * GetUpVector() + SpringRearOffset * GetForwardVector());
   
	if (isInContact) { // If any are in contact, but only those that are shoud apply forces
		// ApplySuspensionForce();
		ApplyDrivingForce();
		ApplySidewaysForce();
	}
}

bool UTankTrack::ApplySpringForce(float DeltaTime, FVector LocalOffset)
{
	auto Start = GetComponentLocation() + LocalOffset;
	auto End = Start - (SpringLength + SpringStop) * GetUpVector(); // TODO clamp?

	FHitResult OutHit;
	auto bTrackIsInContact = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility);
	DrawDebugPoint(GetWorld(), OutHit.ImpactPoint, 2, FColor::Blue, false, 0, 232);

	if (bTrackIsInContact) {
		auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

		auto Displacement = SpringLength - (OutHit.Distance - SpringStop);
		Displacement = FMath::Clamp<float>(Displacement, 0, SpringLength);
		auto DeltaDisplacement = Displacement - PreviousDisplacement;
		PreviousDisplacement = Displacement;

		auto Speed = DeltaDisplacement / DeltaTime;
		auto ForceMagnitude = SpringForce * Displacement - SpringDamping * Speed;
		auto Force = ForceMagnitude * GetUpVector();
		TankRoot->AddForceAtLocation(Force, Start);

		DrawDebugLine(GetWorld(), Start, Start + Force/SpringForce, FColor(255,0,255), false, 0, -10, 2);
		return true; // EEeew
	}
	return false;
}

void UTankTrack::ApplySidewaysForce()
{
	// Work-out the required acceleration this frame to correct
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	// Calculate and apply sideways F = m a
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Two tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
}

void UTankTrack::ApplyDrivingForce()
{
	UE_LOG(LogTemp, Warning, TEXT("Applying Drive force: %f"), CurrentThrottle * TrackMaxDrivingForce);

	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	CurrentThrottle = 0; // "consume" throttle input
}
