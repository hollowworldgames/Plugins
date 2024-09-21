// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NativeGameplayTags.h"
#include "GalaxyAsset.generated.h"

UENUM(BlueprintType)
enum class EGalaxyType : uint8
{
	EGalaxyType_Spiral UMETA(DisplayName = "Spiral"),
	EGalaxyType_Bar UMETA(DisplayName = "Bar"),
	EGalaxyType_Ring UMETA(DisplayName = "Ring"),
	EGalaxyType_Elliptical UMETA(DisplayName = "Elliptical"),
};

//spiral settings
UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxyColorRedTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxyColorGreenTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxyColorBlueTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxyColorAlphaTag);

UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralCoreSizeTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralArmCountTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralArmWidthTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralArmLengthTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralArmTightnessTag);

UENUM(BlueprintType)
enum class ELocationType : uint8
{
	ELocationType_Sun,
	ELocationType_Planet,
	ELocationType_AsteroidCluster,
	ELocationType_Comet,
};

USTRUCT(BlueprintType)
struct FSystemId
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int SectorX;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int SectorY;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int SystemX;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int SystemY;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int SystemZ;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Ring;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int SubRing;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Satellite;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ELocationType Type = ELocationType::ELocationType_Planet;
	int64 GetSeed() const;
	FVector GetGalaxyLocation() const;
	FVector GetSystemLocation() const;
	bool IsSystem() const;
	bool IsLocation() const;
	bool IsSameLocation(FSystemId System);
	bool IsSameSystem(FSystemId system);
};


UCLASS()
class GALAXY_API UGalaxyAsset : public UDataAsset
{
	GENERATED_BODY()
	
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Data)
	TArray<int> GalaxyData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	int Size = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	int MaxDensity = 255;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	EGalaxyType GalaxyType = EGalaxyType::EGalaxyType_Spiral;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	int Seed = 1;
	UFUNCTION(CallInEditor)
	void CreateGalaxy();
	void CreateSpiralGalaxy();
	void CreateBarGalaxy();
	void CreateRingGalaxy();
	void CreateEllipticalGalaxy();
};
