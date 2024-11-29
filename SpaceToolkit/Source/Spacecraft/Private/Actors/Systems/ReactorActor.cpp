// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/ReactorActor.h"

#include "Attributes/Equipment/ReactorAttributeSet.h"


// Sets default values
AReactorActor::AReactorActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Reactor = CreateDefaultSubobject<UReactorAttributeSet>("Reactor Attributes");
}

// Called when the game starts or when spawned
void AReactorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReactorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AReactorActor::InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData)
{
	Super::InitializeAttributes(SystemOwner, SystemData);
}
