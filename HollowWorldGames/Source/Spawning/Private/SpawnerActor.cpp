// (c) Copyright 2023 Hollow World Games llc All Rights Reserved


#include "SpawnerActor.h"

#include "UtilityStatics.h"
#include "Spawnable.h"
#include "SpawnerWidget.h"
#include "SpawnPoint.h"
#include "SpawnQueueComponent.h"
#include "SpawnStationComponent.h"

// Sets default values
ASpawnerActor::ASpawnerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnerActor::BeginPlay()
{
	Super::BeginPlay();
	TArray<USceneComponent*> components;
	GetComponents(components);
	for(USceneComponent * component : components)
	{
		ISpawnPoint * point = Cast<ISpawnPoint>(component);
		if(point)
		{
			SpawnPoints.Add(TObjectPtr<USceneComponent>(component));
		}
		if(component->IsA(USpawnStationComponent::StaticClass()))
		{
			SpawnStation = Cast<USpawnStationComponent>(component);
			if(ensureMsgf(SpawnStation, TEXT("SpawnStation Null")) && ensureMsgf(SpawnStation->GetSpawnerWidget(), TEXT("Spawner Widget Null")))
			{
				SpawnStation->GetSpawnerWidget()->SetSpawnerActor(this);
				LogStart(LogSeverity::Information, false) << TEXT("Spawner Set for Widget") << LogStop();
			}
		}
	}

	ensure(SpawnPoints.Num() > 0);
	ensure(SpawnStation);
}

// Called every frame
void ASpawnerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<TScriptInterface<ISpawnPoint>> ASpawnerActor::GetSpawnPoints_Implementation()
{
	return SpawnPoints;
}

TArray<TScriptInterface<ISpawnable>> ASpawnerActor::GetSpawnables_Implementation()
{
	return Spawnables;
}

TArray<TScriptInterface<ISpawnPoint>> ASpawnerActor::GetSpawnPointsByType_Implementation(int Type)
{
	TArray<TScriptInterface<ISpawnPoint>> Spawns;
	for(TScriptInterface<ISpawnPoint> SpawnPoint : SpawnPoints)
	{
		if(SpawnPoint->GetSpawnType() == Type)
		{
			Spawns.Add(SpawnPoint);
		}
	}
	return Spawns;
}

void ASpawnerActor::AddSpawn_Implementation(const TScriptInterface<ISpawnPoint>& SpawnPoint)
{
	ensure(SpawnPoint);
	SpawnPoints.Add(SpawnPoint);
}

bool ASpawnerActor::SpawnRandom_Implementation(const TScriptInterface<ISpawnable>& Spawnable)
{
	for(TScriptInterface<ISpawnPoint> spawn : SpawnPoints)
	{
		if(!spawn->IsOccupied())
		{
			spawn->Execute_Spawn(spawn.GetObject(), Spawnable);
			return true;
		}
	}
	return false;
}

void ASpawnerActor::AddSpawnable_Implementation(UObject* Spawnable)
{
	if(ensure(Cast<ISpawnable>(Spawnable)))
	{
		TScriptInterface<ISpawnable> spawn;
		spawn.SetObject(Spawnable);
		spawn.SetInterface(Cast<ISpawnable>(Spawnable));
		ensure(spawn);
		Spawnables.Add(spawn);
	}
}

bool ASpawnerActor::Spawn_Implementation(const TScriptInterface<ISpawnable>& Spawnable)
{
	USpawnQueueComponent * Queue = GetComponentByClass<USpawnQueueComponent>();
	if(Queue)
	{
		Queue->QueueForSpawn(Spawnable);
		return true;
	}
	else
	{
		for(TScriptInterface<ISpawnPoint> point : SpawnPoints)
		{
			if(!point->IsOccupied())
			{
				point->Execute_Spawn(point.GetObject(), Spawnable);
				return true;
			}
		}
	}
	return false;
}

void ASpawnerActor::Despawn_Implementation(APawn* Pawn)
{
	GetWorld()->DestroyActor(Pawn);
}

