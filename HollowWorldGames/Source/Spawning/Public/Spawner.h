// (c) Copyright 2023 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Spawner.generated.h"

class ISpawnable;
class ISpawnPoint;
// This class does not need to be modified.
UINTERFACE(BlueprintType)
class USpawner : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPAWNING_API ISpawner
{
	GENERATED_BODY()
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawner")
	TArray<TScriptInterface<ISpawnPoint>> GetSpawnPoints();
	virtual TArray<TScriptInterface<ISpawnPoint>> GetSpawnPoints_Implementation() =  0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawner")
	TArray<TScriptInterface<ISpawnPoint>> GetSpawnPointsByType(int Type);
	virtual TArray<TScriptInterface<ISpawnPoint>> GetSpawnPointsByType_Implementation(int Type) =  0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawner")
	TArray<TScriptInterface<ISpawnable>> GetSpawnables();
	virtual TArray<TScriptInterface<ISpawnable>> GetSpawnables_Implementation() = 0;

	/*
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AddSpawnPoint(USceneComponent * spawnPoint);
	virtual void AddSpawnPoint_Implementation(USceneComponent * spawnPoint);*/

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawner")
	void AddSpawn(const TScriptInterface<ISpawnPoint>& SpawnPoint);
	virtual void AddSpawn_Implementation(const TScriptInterface<ISpawnPoint>& SpawnPoint) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawner")
	bool SpawnRandom(const TScriptInterface<ISpawnable>& Spawnable);
	virtual bool SpawnRandom_Implementation(const TScriptInterface<ISpawnable>& Spawnable) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawner")
	void AddSpawnable(UObject * Spawnable);
	virtual void AddSpawnable_Implementation(UObject* Spawnable) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawner")
	bool Spawn(const TScriptInterface<ISpawnable>& Spawnable);
	virtual bool Spawn_Implementation(const TScriptInterface<ISpawnable>& Spawnable) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawner")
	bool SpawnAt(const TScriptInterface<ISpawnable>& Spawnable, const TScriptInterface<ISpawnPoint>& SpawnPoint);
	virtual bool SpawnAt_Implementation(const TScriptInterface<ISpawnable>& Spawnable, const TScriptInterface<ISpawnPoint>& SpawnPoint);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawner")
	void Despawn(APawn * Pawn);
	virtual void Despawn_Implementation(APawn * Pawn) = 0;
};
