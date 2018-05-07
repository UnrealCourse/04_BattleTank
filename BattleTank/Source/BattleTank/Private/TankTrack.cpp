// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

#include "Wheel.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
	Wheels = FindWheels();
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

TArray<AWheel*> UTankTrack::FindWheels()
{
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);
	TArray<AWheel*> OurWheels;
	for (auto Child : Children)
	{
		auto ChildActorComponent = Cast<UChildActorComponent>(Child);
		if (!ChildActorComponent) continue;
		auto Wheel = Cast<AWheel>(ChildActorComponent->GetChildActor());
		if (!Wheel) continue;
		OurWheels.Add(Wheel);
	}
	return OurWheels;
}

void UTankTrack::OnChildAttached(USceneComponent * ChildComponent)
{
	AWheel* Wheel = Cast<AWheel>(ChildComponent);
	if (Wheel)
	{
		Wheels.Add(Wheel);
	}
}
