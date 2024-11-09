// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GalaxyAsset.h"
#include "Engine/DataAsset.h"
#include "SolarSystemTableRow.generated.h"

USTRUCT(BlueprintType)
struct FSystemLocation
{
	GENERATED_BODY()
	
};

USTRUCT(BlueprintType)
struct FSystemStar
{
	GENERATED_BODY()
	
};

USTRUCT(BlueprintType)
struct FSolarSystemTableRow : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY()
	FSystemId SystemId;
	UPROPERTY()
	FName SystemName;
	UPROPERTY()
	TArray<FSystemStar> SystemStars;
	UPROPERTY()
	TArray<FSystemLocation> Locations;
	UPROPERTY()
	TArray<FSystemId> ConnectedSystems;
};
