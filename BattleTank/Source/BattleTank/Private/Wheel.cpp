// Copyright EmbraceIT Ltd.

#include "BattleTank.h"
#include "Wheel.h"

#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values for this component's properties
UWheel::UWheel()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SetMassOverrideInKg(NAME_None, 1, true);
	SetCollisionProfileName(TEXT("PhysicsActor"));
	SetSimulatePhysics(true);
}


// Called when the game starts
void UWheel::BeginPlay()
{
	Super::BeginPlay();

	auto RootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (!RootComponent) return;

	Axel = NewObject<USphereComponent>(this);
	Axel->RegisterComponent();
	
	Axel->SetWorldLocation(GetComponentLocation());

	SuspensionConstraint = NewObject<UPhysicsConstraintComponent>(this);
	SuspensionConstraint->RegisterComponent();
	AxelConstraint = NewObject<UPhysicsConstraintComponent>(this);
	AxelConstraint->RegisterComponent();
	
	SuspensionConstraint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SuspensionConstraint->SetWorldLocation(GetComponentLocation());
	AxelConstraint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	AxelConstraint->SetWorldLocation(GetComponentLocation());


	SuspensionConstraint->ConstraintInstance = SuspensionConstraintSetup;
	AxelConstraint->ConstraintInstance = AxelConstraintSetup;

	Axel->SetSimulatePhysics(true);
	Axel->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	Axel->SetMassOverrideInKg(NAME_None, 1, true);
	//DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);

	SuspensionConstraint->SetConstrainedComponents(RootComponent, NAME_None, Axel, NAME_None);
	AxelConstraint->SetConstrainedComponents(Axel, NAME_None, this, NAME_None);
}


// Called every frame
void UWheel::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

