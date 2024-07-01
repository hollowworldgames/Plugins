// (c) Copyright 2023 Hollow World Games llc All Rights Reserved


#include "SpawnerPawn.h"

#include "Spawnable.h"
#include "SpawnPoint.h"
#include "SpawnQueueComponent.h"

// Sets default values
ASpawnerPawn::ASpawnerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnerPawn::BeginPlay()
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
	}
}

// Called every frame
void ASpawnerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpawnerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

TArray<TScriptInterface<ISpawnPoint>> ASpawnerPawn::GetSpawnPoints_Implementation()
{
	return SpawnPoints;
}

TArray<TScriptInterface<ISpawnPoint>> ASpawnerPawn::GetSpawnPointsByType_Implementation(int Type)
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

TArray<TScriptInterface<ISpawnable>> ASpawnerPawn::GetSpawnables_Implementation()
{
	return Spawnables;
}

void ASpawnerPawn::AddSpawn_Implementation(const TScriptInterface<ISpawnPoint>& SpawnPoint)
{
	SpawnPoints.Add(SpawnPoint);
}

bool ASpawnerPawn::SpawnRandom_Implementation(const TScriptInterface<ISpawnable>& Spawnable)
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

void ASpawnerPawn::AddSpawnable_Implementation(UObject* Spawnable)
{
	if(ensure(Cast<ISpawnable>(Spawnable)))
	{
		TScriptInterface<ISpawnable> spawn;
		spawn.SetObject(Spawnable);
		spawn.SetInterface(Cast<ISpawnable>(Spawnable));
		Spawnables.Add(spawn);
	}
}

bool ASpawnerPawn::Spawn_Implementation(const TScriptInterface<ISpawnable>& Spawnable)
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

void ASpawnerPawn::Despawn_Implementation(APawn* Pawn)
{
	GetWorld()->DestroyActor(Pawn);
}
