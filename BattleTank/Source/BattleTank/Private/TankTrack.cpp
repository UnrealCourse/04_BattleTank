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
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0;
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    UE_LOG(LogTemp, Warning, TEXT("TickComponent"));
    auto Start = GetComponentLocation() + GetForwardVector() * SpringOffset + GetUpVector() * SpringLength;
    auto End = Start - SpringLength * GetUpVector();
    DrawDebugLine(GetWorld(), Start, End, FColor(255,0,255), false, 2, 10, 2);
    FHitResult OutHit;
    UE_LOG(LogTemp, Warning, TEXT("Start: %s, End: %s"), *Start.ToString(), *End.ToString());
    if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility)) {
        auto HitString = OutHit.Component->GetName();
        UE_LOG(LogTemp, Warning, TEXT("Trace hit: %s"), *HitString);
        auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
        
        auto Displacement = SpringLength * 2 - OutHit.Distance;
        auto DeltaDisplacement = Displacement - PreviousDisplacement;
        PreviousDisplacement = Displacement;
        UE_LOG(LogTemp, Warning, TEXT("Displacement: %f"), Displacement);
        auto Speed = DeltaDisplacement/DeltaTime;
        UE_LOG(LogTemp, Warning, TEXT("Speed: %f"), Speed);
        auto ForceMagnitude = SpringForce * Displacement - SpringDamping * Speed;
        TankRoot->AddForceAtLocation(ForceMagnitude * GetUpVector(), Start);
    }
}

void UTankTrack::ApplySidewaysForce()
{
// Work-out the required acceleration this frame to correct
auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
auto DeltaTime = GetWorld()->GetDeltaSeconds();
auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

// Calculate and apply sideways (F = m a)
auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Two tracks
TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
}

void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
