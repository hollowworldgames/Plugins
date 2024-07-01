// (c) Copyright 2023 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Spawner.h"
#include "GameFramework/Pawn.h"
#include "SpawnerPawn.generated.h"

UCLASS()
class SPAWNING_API ASpawnerPawn : public APawn, public ISpawner
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpawnerPawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual TArray<TScriptInterface<ISpawnPoint>> GetSpawnPoints_Implementation() override;
	virtual TArray<TScriptInterface<ISpawnPoint>> GetSpawnPointsByType_Implementation(int Type) override;
	virtual TArray<TScriptInterface<ISpawnable>> GetSpawnables_Implementation() override;
	virtual void AddSpawn_Implementation(const TScriptInterface<ISpawnPoint>& SpawnPoint) override;
	virtual bool SpawnRandom_Implementation(const TScriptInterface<ISpawnable>& Spawnable) override;
	virtual void AddSpawnable_Implementation(UObject* Spawnable) override;
	virtual bool Spawn_Implementation(const TScriptInterface<ISpawnable>& Spawnable) override;
	virtual void Despawn_Implementation(APawn* Pawn) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category=Spawning)
	TArray<TScriptInterface<ISpawnPoint>> SpawnPoints;
	UPROPERTY(VisibleAnywhere, Transient, Category=Spawning)
	TArray<TScriptInterface<ISpawnable>> Spawnables;
};


