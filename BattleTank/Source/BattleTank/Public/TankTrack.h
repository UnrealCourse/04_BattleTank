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
    float TrackMaxDrivingForce = 60000000.0; // Assume 40 tonne tank, and 1g accelleration
    UPROPERTY(EditDefaultsOnly)
    float SpringForce = 100000.0;
    UPROPERTY(EditDefaultsOnly)
    float SpringDamping = -10000.0;
    UPROPERTY(EditDefaultsOnly)
    float SpringSideOffset = 200.0;
    UPROPERTY(EditDefaultsOnly)
    float SpringRearOffset = -300.0;
    UPROPERTY(EditDefaultsOnly)
    float SpringFrontOffset = 200.0;
    UPROPERTY(EditDefaultsOnly)
    float SpringHeightOffset = 200.0;
    UPROPERTY(EditDefaultsOnly)
    float SpringStop = 100.0;
    UPROPERTY(EditDefaultsOnly)
    float SpringLength = 300.0;
    

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
