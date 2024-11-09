// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NativeGameplayTags.h"
#include "ScalableFloat.h"
#include "GalaxyAsset.generated.h"

struct FSolarSystemTableRow;
class USolarSystem;

UENUM(BlueprintType)
enum class EGalaxyType : uint8
{
	EGalaxyType_Spiral UMETA(DisplayName = "Spiral"),
	EGalaxyType_Bar UMETA(DisplayName = "Bar"),
	EGalaxyType_Ring UMETA(DisplayName = "Ring"),
	EGalaxyType_Elliptical UMETA(DisplayName = "Elliptical"),
};

//spiral settings
GALAXY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralCoreSizeTag);
GALAXY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralArmCountTag);
GALAXY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralArmWidthTag);
GALAXY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralArmLengthTag);
GALAXY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralArmTightnessTag);

UENUM(BlueprintType)
enum class ELocationType : uint8
{
	ELocationType_System,
	ELocationType_Nebula,
	ELocationType_Sun,
	ELocationType_Planet,
	ELocationType_AsteroidCluster,
	ELocationType_Comet,
};

USTRUCT(BlueprintType)
struct GALAXY_API FSystemId
{
	GENERATED_BODY()
public :
	FSystemId(): SectorX(0), SectorY(0), SystemX(0), SystemY(0), SystemZ(0), Ring(0), SubRing(0), Satellite(0), Seed(0)
	{
	}

	FSystemId(int NewSectorX, int NewSectorY, int NewSystemX, int NewSystemY, const FVector& NewGalaxyPosition,
	          int NewSystemZ, int64 NewSeed, int NewRing = 0, int NewSubRing = 0, int NewSatellite = 0);
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
	ELocationType Type = ELocationType::ELocationType_System;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int64 Seed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector GalaxyPosition;
	int64 GetSeed() const { return Seed; };
	FVector GetGalaxyLocation() const { return GalaxyPosition; };
	void SetGalaxyLocation(const FVector& Location) { GalaxyPosition = Location; };
	bool IsSystem() const;
	bool IsLocation() const;
	bool IsSameLocation(const FSystemId& System) const;
	bool IsSameSystem(const FSystemId& System) const;
	void UpdatePosition(float GalaxyWidth, float SectorWidth, float GalaxyScale, FScalableFloat Heights, float MaxHeight);
	friend uint32 GetTypeHash(const FSystemId& Id) { return Id.Seed; }
	bool operator==(const FSystemId&) const;
};


UCLASS(BlueprintType)
class GALAXY_API UGalaxyAsset : public UDataAsset
{
	GENERATED_BODY()
public :
	TArray<FSystemId> GetSystemsInSector(int X, int Y);
	FVector GetDustLocation(int X, int Y) const;
	FVector ComputeGalaxyPosition(int SectorX, int SectorY, int SystemX, int SystemY, int SystemZ) const;
	FSystemId GenerateSystemId(int SectorX, int SectorY, int SystemX, int SystemY) const;
	FSystemId GenerateLocationId(int SectorX, int SectorY, int SystemX, int SystemY, int Ring, int SubRing) const;
	FSystemId GenerateOrbitalId(int SectorX, int SectorY, int SystemX, int SystemY, int Ring, int SubRing, int Satellite) const;
	double GetHeightAt(int SectorX, int SectorY) const;
	int64 GenerateSeed(int SectorX, int SectorY, int SystemX = 0, int SystemY = 0, int Ring = 0, int SubRing = 0, int Satellite = 0) const;
	TObjectPtr<USolarSystem> GetSystem(const FSystemId& SystemId);
	FSolarSystemTableRow * FindSolarSystem(const FSystemId& SystemId);
	USolarSystem * CreateSystemFromRow(FSolarSystemTableRow * Row);
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Data)
	TArray<int> GalaxyData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Size)
	int Size = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Size)
	int SectorSize = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	int Density = 255;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	EGalaxyType GalaxyType = EGalaxyType::EGalaxyType_Spiral;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	int Seed = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TMap<FGameplayTag, float> Settings;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Heights)
	FScalableFloat Heights;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Heights)
	double MaxHeight = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Size)
	double GalaxyScale = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Systems)
	TObjectPtr<UDataTable> SystemDatabase;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Systems)
	TMap<FSystemId, TObjectPtr<USolarSystem>> KnownSystems;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Systems)
	TSubclassOf<USolarSystem> SolarSystemClass;
	UFUNCTION(CallInEditor)
	void CreateGalaxy();
	void CreateSpiralGalaxy(float CoreSize, int ArmCount,float ArmWidth,float ArmTightness,float ArmLength);
	void CreateBarGalaxy();
	void CreateRingGalaxy();
	void CreateEllipticalGalaxy();
	void DrawCircle(int X, int Y, int SizeX, int SizeY, int MinDensity, int MaxDensity);
	void DrawArm(float StartAngle, float DistanceStart, float MinDensity, float MaxDensity, float ArmWidth, float ArmTightness, float ArmLength);
	void WriteDensity(int x, int y, int density, bool Overwrite = false);
};
