// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

#include "Wheel.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(CurrentThrottle);
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	float TotalForce = CurrentThrottle * TrackMaxDrivingForce;
	float WheelForce = TotalForce / Wheels.Num();
	for (AWheel* Wheel : Wheels)
	{
		Wheel->AddForwardForce(WheelForce);
	}
}

void UTankTrack::OnChildAttached(USceneComponent * ChildComponent)
{
	AWheel* Wheel = Cast<AWheel>(ChildComponent);
	Wheels.Add(Wheel);
}
