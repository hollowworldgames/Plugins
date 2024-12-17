// (c) Copyright 2023 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpawnerWidget.generated.h"

class ASpawnerActor;
class ASpawnerPawn;
class ISpawnPoint;
class ISpawnable;
class ISpawner;
/**
 * 
 */
UCLASS()
class SPAWNING_API USpawnerWidget : public UUserWidget
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintCallable, Category = "SpawnerWidget")
	void SetSpawnerActor(ASpawnerActor * Spawn);
	UFUNCTION(BlueprintCallable, Category = "SpawnerWidget")
	void SetSpawnerPawn(ASpawnerPawn * Pawn);
	UFUNCTION(BlueprintPure, Category = "SpawnerWidget")
	TScriptInterface<ISpawner> GetSpawner() const { return Spawner; }
	UFUNCTION(BlueprintCallable, Category = "SpawnerWidget")
	void NextSpawnable();
	UFUNCTION(BlueprintCallable, Category = "SpawnerWidget")
	void PreviousSpawnable();
	UFUNCTION(BlueprintCallable, Category = "SpawnerWidget")
	TScriptInterface<ISpawnable> GetCurrentSpawnable();
	UFUNCTION(BlueprintCallable, Category = "SpawnerWidget")
	void NextSpawnPoint();
	UFUNCTION(BlueprintCallable, Category = "SpawnerWidget")
	void PreviousSpawnPoint();
	UFUNCTION(BlueprintCallable, Category = "SpawnerWidget")
	TScriptInterface<ISpawnable> GetCurrentSpawnPoint();
	UFUNCTION(BlueprintCallable, Category = "SpawnerWidget")
	void Spawn();
	UFUNCTION(BlueprintCallable, Category = "SpawnerWidget")
	void SpawnRandom();
	UFUNCTION(BlueprintCallable, Category = "SpawnerWidget")
	void OnInteraction();
protected:
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category=Status)
	TScriptInterface<ISpawner> Spawner;
};
