//Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once


#include "GalaxyEnums.h"
#include "ScalableFloat.h"
#include "SystemId.generated.h"

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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sector")
	int SectorX;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sector")
	int SectorY;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "System")
	int SystemX;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "System")
	int SystemY;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "System")
	int SystemZ;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Location")
	int Ring;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Location")
	int SubRing;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Location")
	int Satellite;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Location")
	ELocationType Type = ELocationType::ELocationType_System;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	int64 Seed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FVector GalaxyPosition;
	//int64 GetSeed() const { return Seed; };
	//FVector GetGalaxyLocation() const { return GalaxyPosition; };
	//void SetGalaxyLocation(const FVector& Location) { GalaxyPosition = Location; };
	bool IsSystem() const;
	bool IsLocation() const;
	bool IsSameLocation(const FSystemId& System) const;
	bool IsSameSystem(const FSystemId& System) const;
	void UpdatePosition(float GalaxyWidth, float SectorWidth, float GalaxyScale, FScalableFloat Heights, float MaxHeight);
	friend uint32 GetTypeHash(const FSystemId& Id) { return Id.Seed; }
	bool operator==(const FSystemId&) const;
};