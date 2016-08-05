// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	// Max force per track, in Newtons
    UPROPERTY(EditDefaultsOnly)
    float TrackMaxDrivingForce = 400000; // Assume 40 tonne tank, and 1g accelleration
    UPROPERTY(EditDefaultsOnly)
    float SpringForce = 5;
    UPROPERTY(EditDefaultsOnly)
    float SpringDamping = 5;
    UPROPERTY(EditDefaultsOnly)
    float SpringSideOffset = 2;
    UPROPERTY(EditDefaultsOnly)
    float SpringRearOffset = 2;
    UPROPERTY(EditDefaultsOnly)
    float SpringFrontOffset = 2;
    UPROPERTY(EditDefaultsOnly)
    float SpringLength = 2;
    

private:
	UTankTrack();

	virtual void BeginPlay() override;
    
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
    
    bool ApplySpringForce(float DeltaTime, FVector LocalOffset);
    
	void ApplySidewaysForce();
    
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack();

	float CurrentThrottle = 0;
    
    float PreviousDisplacement = 0;
};
