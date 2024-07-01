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
	UFUNCTION(BlueprintCallable)
	void SetSpawnerActor(ASpawnerActor * Spawn);
	UFUNCTION(BlueprintCallable)
	void SetSpawnerPawn(ASpawnerPawn * Pawn);
	UFUNCTION(BlueprintPure)
	TScriptInterface<ISpawner> GetSpawner() const { return Spawner; }
	UFUNCTION(BlueprintCallable)
	void NextSpawnable();
	UFUNCTION(BlueprintCallable)
	void PreviousSpawnable();
	UFUNCTION(BlueprintCallable)
	TScriptInterface<ISpawnable> GetCurrentSpawnable();
	UFUNCTION(BlueprintCallable)
	void NextSpawnPoint();
	UFUNCTION(BlueprintCallable)
	void PreviousSpawnPoint();
	UFUNCTION(BlueprintCallable)
	TScriptInterface<ISpawnable> GetCurrentSpawnPoint();
	UFUNCTION(BlueprintCallable)
	void Spawn();
	UFUNCTION(BlueprintCallable)
	void SpawnRandom();
	UFUNCTION(BlueprintCallable)
	void OnInteraction();
protected:
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category=Status)
	TScriptInterface<ISpawner> Spawner;
};
