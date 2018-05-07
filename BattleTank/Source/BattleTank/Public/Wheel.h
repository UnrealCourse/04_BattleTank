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
	virtual void TickComponent
	(
		float DeltaTime,
		enum ELevelTick TickType,
		FActorComponentTickFunction * ThisTickFunction
	) override;

	void AddForwardForce(float Force);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	void SetupAxle();

	UPhysicsConstraintComponent * NewConstraint(
		UPrimitiveComponent* RootComponent, 
		const FConstraintInstance& ConstraintSetup, 
		UPrimitiveComponent* Component1, 
		UPrimitiveComponent* Component2
	);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	//config
	UPROPERTY(EditAnywhere)
	float DrivingFriction = 1;
	UPROPERTY(EditDefaultsOnly)
	float Stiffness = 40;
	UPROPERTY(EditDefaultsOnly)
	float Damping = 20;


	//references
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Axle;
	UPROPERTY(VisibleAnywhere)
	UPhysicsConstraintComponent* SuspensionConstraint;
	UPROPERTY(VisibleAnywhere)
	UPhysicsConstraintComponent* AxleConstraint;

	//state
	float RequestedForce = 0;
};