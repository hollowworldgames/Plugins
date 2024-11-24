// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/BatteryActor.h"


// Sets default values
ABatteryActor::ABatteryActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABatteryActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABatteryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABatteryActor::InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData)
{
	Super::InitializeAttributes(SystemOwner, SystemData);

	
}

