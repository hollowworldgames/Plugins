// (c) Copyright 2023 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Spawner.h"
#include "GameFramework/Actor.h"
#include "SpawnerActor.generated.h"

class USpawnStationComponent;

UCLASS()
class SPAWNING_API ASpawnerActor : public AActor, public ISpawner
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnerActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual TArray<TScriptInterface<ISpawnPoint>> GetSpawnPoints_Implementation();
	virtual TArray<TScriptInterface<ISpawnable>> GetSpawnables_Implementation();
	virtual TArray<TScriptInterface<ISpawnPoint>> GetSpawnPointsByType_Implementation(int Type) override;
	virtual void AddSpawn_Implementation(const TScriptInterface<ISpawnPoint>& SpawnPoint) override;
	virtual bool SpawnRandom_Implementation(const TScriptInterface<ISpawnable>& Spawnable) override;
	virtual void AddSpawnable_Implementation(UObject* Spawnable) override;
	virtual bool Spawn_Implementation(const TScriptInterface<ISpawnable>& Spawnable) override;
	virtual void Despawn_Implementation(APawn* Pawn) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category="Spawning")
	TArray<TScriptInterface<ISpawnPoint>> SpawnPoints;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category="Spawning")
	TArray<TScriptInterface<ISpawnable>> Spawnables;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category="Spawning")
	TObjectPtr<USpawnStationComponent> SpawnStation;
};
