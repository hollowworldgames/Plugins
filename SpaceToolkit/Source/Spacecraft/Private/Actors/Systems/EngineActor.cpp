// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/EngineActor.h"

#include "Attributes/Equipment/EngineAttributeSet.h"


// Sets default values
AEngineActor::AEngineActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Engine = CreateDefaultSubobject<UEngineAttributeSet>("Engine Attributes");
}

// Called when the game starts or when spawned
void AEngineActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEngineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEngineActor::InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData)
{
	Super::InitializeAttributes(SystemOwner, SystemData);

	
}

