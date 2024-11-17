//Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NativeGameplayTags.h"
#include "ScalableFloat.h"
#include "GalaxyEnums.h"
#include "SystemId.h"
#include "GalaxyAsset.generated.h"

struct FSolarSystemTableRow;
class USolarSystem;

//spiral settings
GALAXY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralCoreSizeTag);
GALAXY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralArmCountTag);
GALAXY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralArmWidthTag);
GALAXY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralArmLengthTag);
GALAXY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GalaxySpiralArmTightnessTag);

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
	int GetSize() const { return Size; }
	int GetDensity(int X, int Y) const;
	float GetDensityScalar(int X, int Y) const;

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
