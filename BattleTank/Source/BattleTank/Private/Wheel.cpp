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
AWheel::AWheel()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PostPhysics;

	// Set mass to 1kg
	Wheel = CreateDefaultSubobject<USphereComponent>(TEXT("Wheel"));
	Wheel->SetMassOverrideInKg(NAME_None, 1, true);
	Wheel->SetCollisionProfileName(TEXT("PhysicsActor"));
	Wheel->SetSimulatePhysics(true);
}

void AWheel::AddForwardForce(float Force)
{
	RequestedForce += Force;
}

// Called when the game starts
void AWheel::BeginPlay()
{
	Super::BeginPlay();

	SetupAxle();

	Wheel->SetNotifyRigidBodyCollision(true);
	Wheel->OnComponentHit.AddDynamic(this, &AWheel::OnHit);

	auto ParentRootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (ParentRootComponent)
	{
		SuspensionConstraint = NewConstraint(ParentRootComponent, NewSpring(Stiffness, Damping), ParentRootComponent, Axle);
		AxleConstraint = NewConstraint(ParentRootComponent, NewAxel(), Axle, Wheel);
	}
}

void AWheel::SetupAxle()
{
	Axle = NewObject<USphereComponent>(this);
	Axle->RegisterComponent();

	Axle->SetWorldLocation(Wheel->GetComponentLocation());
	Axle->SetSimulatePhysics(true);
	Axle->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	Axle->SetMassOverrideInKg(NAME_None, 1, true);
}

UPhysicsConstraintComponent* AWheel::NewConstraint(
	UPrimitiveComponent* RootComponent,
	const FConstraintInstance& ConstraintSetup,
	UPrimitiveComponent* Component1,
	UPrimitiveComponent* Component2) 
{
	auto Constraint = NewObject<UPhysicsConstraintComponent>(this);
	Constraint->RegisterComponent();

	Constraint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Constraint->SetWorldLocation(Wheel->GetComponentLocation());

	Constraint->ConstraintInstance = ConstraintSetup;

	Constraint->SetConstrainedComponents(Component1, NAME_None, Component2, NAME_None);
	return Constraint;
}


void AWheel::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	float MaxForce = DrivingFriction * NormalImpulse.Size();
	float CappedForce = FMath::Clamp(RequestedForce, -MaxForce, MaxForce);
	Wheel->AddForce(Axle->GetRightVector() ^ Hit.Normal * CappedForce);
}

void AWheel::Tick
(
	float DeltaTime
)
{
	if (GetWorld()->TickGroup == TG_PostPhysics)
	{
		RequestedForce = 0;
	}
}