//Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GalaxyAsset.h"
#include "Location.h"
#include "Engine/DataAsset.h"
#include "SolarSystemTableRow.generated.h"



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
