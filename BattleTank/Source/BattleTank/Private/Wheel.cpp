// Copyright EmbraceIT Ltd.

#include "BattleTank.h"
#include "Wheel.h"

#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values for this component's properties
UWheel::UWheel()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// Set mass to 1kg
	SetMassOverrideInKg(NAME_None, 1, true);
	SetCollisionProfileName(TEXT("PhysicsActor"));
	SetSimulatePhysics(true);
}

void UWheel::AddForwardForce(float Force)
{
	FVector LinearForce, AngularForce;
	SuspensionConstraint->GetConstraintForce(LinearForce, AngularForce);
	float MaxForce = DrivingFriction * LinearForce.Size();
	float CappedForce = FMath::Min(MaxForce, Force);
	AddForce(Axle->GetForwardVector() * CappedForce);
}

// Called when the game starts
void UWheel::BeginPlay()
{
	Super::BeginPlay();

	SetupAxle();

	auto RootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (RootComponent)
	{
		SuspensionConstraint = NewConstraint(RootComponent, SuspensionConstraintSetup, RootComponent, Axle);
		AxleConstraint = NewConstraint(RootComponent, AxleConstraintSetup, Axle, this);
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