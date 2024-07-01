// (c) Copyright 2023 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SpawnPoint.generated.h"

class ISpawnable;
// This class does not need to be modified.
UINTERFACE(BlueprintType)
class SPAWNING_API USpawnPoint : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPAWNING_API ISpawnPoint
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	APawn * Spawn(const TScriptInterface<ISpawnable>& Spawnable);
	virtual APawn * Spawn_Implementation(const TScriptInterface<ISpawnable>& Spawnable) = 0;
	virtual bool IsOccupied() = 0;
	virtual FVector GetLocation() = 0;
	virtual FRotator GetRotation() = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FName GetSpawnName();
	virtual FName GetSpawnName_Implementation() = 0;
	virtual int GetSpawnType() = 0;
	virtual int GetSpawnFaction() = 0;
};
