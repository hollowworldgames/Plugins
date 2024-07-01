// (c) Copyright 2023 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Spawnable.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpawnNotify, TScriptInterface<ISpawnPoint>, SpawnPoint, APawn*, Spawned);
// This class does not need to be modified.
UINTERFACE(BlueprintType)
class USpawnable : public UInterface
{
	GENERATED_BODY()
};


class SPAWNING_API ISpawnable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TSubclassOf<APawn> GetSpawnClass();
	virtual TSubclassOf<APawn> GetSpawnClass_Implementation() = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UTexture2D * GetSpawnImage();
	virtual UTexture2D * GetSpawnImage_Implementation() = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FName GetSpawnName();
	virtual FName GetSpawnName_Implementation() = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	double GetSpawnHeight();
	virtual double GetSpawnHeight_Implementation() = 0;
	virtual FSpawnNotify& GetNotify() = 0;
	virtual APawn * Spawn(UWorld * World, const TScriptInterface<ISpawnPoint>& SpawnPoint) = 0;
};
