// Copyright EmbraceIT Ltd.

#include "BattleTank.h"
#include "WheelSocket.h"


// Sets default values for this component's properties
UWheelSocket::UWheelSocket()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWheelSocket::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWheelSocket::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

