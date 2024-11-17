// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlanetLodSettingsAsset.generated.h"


USTRUCT(BlueprintType)
struct FPlanetLodLevel
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double ViewDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Complexity;
};

UCLASS(BlueprintType)
class TERRASUITE_API UPlanetLodSettingsAsset : public UDataAsset
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FPlanetLodLevel> LodLevels;
};
