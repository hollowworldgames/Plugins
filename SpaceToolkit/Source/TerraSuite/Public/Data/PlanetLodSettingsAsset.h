// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlanetLodSettingsAsset.generated.h"


USTRUCT(BlueprintType)
struct FPlanetLodLevel
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	double ViewDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int Complexity;
};

UCLASS(BlueprintType)
class TERRASUITE_API UPlanetLodSettingsAsset : public UDataAsset
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TArray<FPlanetLodLevel> LodLevels;
};
