// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/LifeSupportActor.h"

#include "Attributes/LifeSupportAttributeSet.h"


// Sets default values
ALifeSupportActor::ALifeSupportActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LifeSupportAttributes = CreateDefaultSubobject<ULifeSupportAttributeSet>("Life Support Attributes");
}

// Called when the game starts or when spawned
void ALifeSupportActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALifeSupportActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALifeSupportActor::InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData)
{
	Super::InitializeAttributes(SystemOwner, SystemData);
	
}