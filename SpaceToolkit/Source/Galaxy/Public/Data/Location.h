// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GalaxyAsset.h"
#include "UObject/Object.h"
#include "Location.generated.h"

/**
 * 
 */
UCLASS()
class GALAXY_API ULocation : public UObject
{
	GENERATED_BODY()
public :
	virtual void SpawnLocation(FSystemId systemId, FVector centerPoint);
};
