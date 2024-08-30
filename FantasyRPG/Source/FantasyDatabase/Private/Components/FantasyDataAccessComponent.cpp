// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/FantasyDataAccessComponent.h"


// Sets default values for this component's properties
UFantasyDataAccessComponent::UFantasyDataAccessComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UFantasyDataAccessComponent::LoadActorState(uint64 ActorId)
{
	Super::LoadActorState(ActorId);
	CharacterId = ActorId;
}

void UFantasyDataAccessComponent::SaveActorState()
{
	Super::SaveActorState();
}

// Called when the game starts
void UFantasyDataAccessComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
