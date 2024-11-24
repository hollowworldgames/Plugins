// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/SensorActor.h"


// Sets default values
ASensorActor::ASensorActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASensorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASensorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASensorActor::InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData)
{
	Super::InitializeAttributes(SystemOwner, SystemData);
	
}

