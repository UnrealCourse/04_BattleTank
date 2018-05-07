// Copyright EmbraceIT Ltd.

#include "BattleTank.h"
#include "Wheel.h"

#include "PhysicsEngine/PhysicsConstraintComponent.h"


FConstraintInstance NewSpring(float Stiffness, float Damping)
{
	FConstraintInstance Spring;
	Spring.SetLinearZLimit(ELinearConstraintMotion::LCM_Free, 0);
	Spring.SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 0);
	Spring.SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked, 0);
	Spring.SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, 0);
	Spring.SetLinearPositionDrive(false, false, true);
	Spring.SetLinearVelocityDrive(false, false, true);
	Spring.SetLinearDriveParams(Stiffness, Damping, 0);
	return Spring;
}

FConstraintInstance NewAxel()
{
	FConstraintInstance Axel;
	Axel.SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 0);
	Axel.SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Free, 0);
	Axel.SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, 0);
	return Axel;
}

// Sets default values for this component's properties
UWheel::UWheel()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = TG_PostPhysics;

	// Set mass to 1kg
	SetMassOverrideInKg(NAME_None, 1, true);
	SetCollisionProfileName(TEXT("PhysicsActor"));
	SetSimulatePhysics(true);
}

void UWheel::AddForwardForce(float Force)
{
	RequestedForce += Force;
}

// Called when the game starts
void UWheel::BeginPlay()
{
	Super::BeginPlay();

	SetupAxle();

	SetNotifyRigidBodyCollision(true);
	OnComponentHit.AddDynamic(this, &UWheel::OnHit);

	auto RootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (RootComponent)
	{
		SuspensionConstraint = NewConstraint(RootComponent, NewSpring(Stiffness, Damping), RootComponent, Axle);
		AxleConstraint = NewConstraint(RootComponent, NewAxel(), Axle, this);
	}
}

void UWheel::SetupAxle()
{
	Axle = NewObject<USphereComponent>(this);
	Axle->RegisterComponent();

	Axle->SetWorldLocation(GetComponentLocation());
	Axle->SetSimulatePhysics(true);
	Axle->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	Axle->SetMassOverrideInKg(NAME_None, 1, true);
}

UPhysicsConstraintComponent* UWheel::NewConstraint(
	UPrimitiveComponent* RootComponent,
	const FConstraintInstance& ConstraintSetup,
	UPrimitiveComponent* Component1,
	UPrimitiveComponent* Component2) 
{
	auto Constraint = NewObject<UPhysicsConstraintComponent>(this);
	Constraint->RegisterComponent();

	Constraint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Constraint->SetWorldLocation(GetComponentLocation());

	Constraint->ConstraintInstance = ConstraintSetup;

	Constraint->SetConstrainedComponents(Component1, NAME_None, Component2, NAME_None);
	return Constraint;
}


void UWheel::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	float MaxForce = DrivingFriction * NormalImpulse.Size();
	float CappedForce = FMath::Clamp(RequestedForce, -MaxForce, MaxForce);
	AddForce(Axle->GetRightVector() ^ Hit.Normal * CappedForce);
}

void UWheel::TickComponent
(
	float DeltaTime,
	enum ELevelTick TickType,
	FActorComponentTickFunction * ThisTickFunction
)
{
	if (GetWorld()->TickGroup == TG_PostPhysics)
	{
		RequestedForce = 0;
	}
}