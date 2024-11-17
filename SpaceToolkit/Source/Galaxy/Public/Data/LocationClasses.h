﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LocationClasses.generated.h"

enum class EPlanetType : uint8;
/**
 * 
 */
UCLASS(BlueprintType)
class GALAXY_API ULocationClasses : public UDataAsset
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AActor> FieldActorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AActor> CometActorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EPlanetType, TSubclassOf<class AActor>> PlanetoidActorClasses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AActor> AsteroidActorClass;
};