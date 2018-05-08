// Copyright EmbraceIT Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/ConstraintInstance.h"

#include "Wheel.generated.h"

UCLASS( ClassGroup=(Custom), Blueprintable, meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API AWheel : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	AWheel();
	virtual void Tick
	(
		float DeltaTime
	) override;

	void AddForwardForce(float Force);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	void SetupAxle();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	//config
	UPROPERTY(EditAnywhere)
	float DrivingFriction = 100;
	UPROPERTY(EditDefaultsOnly)
	float Stiffness = 40;
	UPROPERTY(EditDefaultsOnly)
	float Damping = 20;


	//references
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Axle;
	UPROPERTY(VisibleAnywhere, Instanced)
	UPhysicsConstraintComponent* SuspensionConstraint;
	UPROPERTY(VisibleAnywhere, Instanced)
	UPhysicsConstraintComponent* AxleConstraint;
	UPROPERTY(VisibleAnywhere)
	USphereComponent *Wheel;

	//state
	float RequestedForce = 0;
};