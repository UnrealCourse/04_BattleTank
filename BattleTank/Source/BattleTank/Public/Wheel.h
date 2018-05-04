// Copyright EmbraceIT Ltd.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/ConstraintInstance.h"

#include "Wheel.generated.h"

UCLASS( ClassGroup=(Custom), Blueprintable, meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UWheel : public USphereComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWheel();

	void AddForwardForce(float Force);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	float DrivingFriction = 1;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Axel;
	UPROPERTY(VisibleAnywhere)
	UPhysicsConstraintComponent* SuspensionConstraint;
	UPROPERTY(VisibleAnywhere)
	UPhysicsConstraintComponent* AxelConstraint;

	UPROPERTY(EditDefaultsOnly)
	FConstraintInstance SuspensionConstraintSetup;
	UPROPERTY(EditDefaultsOnly)
	FConstraintInstance AxelConstraintSetup;

};
