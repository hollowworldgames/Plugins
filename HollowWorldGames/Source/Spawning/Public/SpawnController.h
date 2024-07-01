// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Spawnable.h"
#include "UObject/Interface.h"
#include "SpawnController.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USpawnController : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPAWNING_API ISpawnController
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void OnSpawn(AActor* Spawner) = 0;
	virtual void OnSpawnRandom(AActor* Spawner) = 0;
	virtual void NextSpawnPoint(AActor* Spawner) = 0;
	virtual void PreviousSpawnPoint(AActor* Spawner) = 0;
	virtual TScriptInterface<ISpawnable> GetSpawnPoint() = 0;
};
