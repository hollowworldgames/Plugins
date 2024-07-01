// (c) Copyright 2023 Hollow World Games llc All Rights Reserved


#include "SpawnQueueComponent.h"
#include "SpawnPoint.h"

// Sets default values for this component's properties
USpawnQueueComponent::USpawnQueueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawnQueueComponent::BeginPlay()
{
	Super::BeginPlay();

	if(GetOwner())
	{
		TArray<USceneComponent*> components;
		GetOwner()->GetComponents(components);
		for(USceneComponent * component : components)
		{
			ISpawnPoint * point = Cast<ISpawnPoint>(component);
			if(point)
			{
				 SpawnPoints.Push(TObjectPtr<USceneComponent>(component));
			}
		}
	}
}


// Called every frame
void USpawnQueueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(SpawnQueue.Num() > 0)
	{
		const FSpawnMe spawnable = SpawnQueue[0];
		for(TScriptInterface<ISpawnPoint> point : SpawnPoints)
		{
			if(!point->IsOccupied() && point->GetSpawnType() == spawnable.Type)
			{
				point->Spawn(spawnable.Spawnable);
				SpawnQueue.Pop();
			}
		}
	}
}

void USpawnQueueComponent::QueueForSpawn(const TScriptInterface<ISpawnable>& Spawnable, int Type)
{
	SpawnQueue.Push(FSpawnMe(Spawnable, Type));
}

