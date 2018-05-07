// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"


float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	return DamageToApply;
}

void ATank::Tick
(
	float DeltaSeconds
)
{
	Super::Tick(DeltaSeconds);

	auto Drag = DragCoefficient * - GetVelocity().SizeSquared() * GetVelocity().GetSafeNormal();
	auto BodyComponent = Cast<UPrimitiveComponent>(GetRootComponent());
	if (BodyComponent)
	{
		BodyComponent->AddForce(Drag);

		auto AngularVelocity = BodyComponent->GetPhysicsAngularVelocityInRadians();
		auto AngularDrag = AngularDragCoefficient * - AngularVelocity.SizeSquared() * AngularVelocity.GetSafeNormal();
		BodyComponent->AddTorqueInRadians(AngularDrag);
		UE_LOG(LogTemp, Warning, TEXT("Torque: %s AngularVelocity: %s"), *AngularDrag.ToString(), *AngularVelocity.ToString());
	}
}
