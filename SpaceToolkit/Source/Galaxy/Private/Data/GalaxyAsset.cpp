// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/GalaxyAsset.h"

#include "Data/SolarSystem.h"
#include "Data/SolarSystemTableRow.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxySpiralCoreSizeTag, "Galaxy.Spiral.CoreSize", "Spiral Galaxy Core Size");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxySpiralArmCountTag, "Galaxy.Spiral.ArmCount", "Spiral Galaxy Arm Count");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxySpiralArmWidthTag, "Galaxy.Spiral.ArmWidth", "Spiral Galaxy Arm Width");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxySpiralArmLengthTag, "Galaxy.Spiral.ArmLength", "Spiral Galaxy Arm Length");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxySpiralArmTightnessTag, "Galaxy.Spiral.ArmTightness", "Spiral Galaxy Arm Tightness");


FSystemId::FSystemId(const int NewSectorX, const int NewSectorY, const int NewSystemX,
	int NewSystemY, const FVector& NewGalaxyPosition, int NewSystemZ, int64 NewSeed, int NewRing, int NewSubRing, int NewSatellite)
{
	SectorX = NewSectorX;
	SectorY = NewSectorY;
	SystemX = NewSystemX;
	SystemY = NewSystemY;
	SystemZ = NewSystemZ;
	Ring = NewRing;
	SubRing = NewSubRing;
	Satellite = NewSatellite;
	GalaxyPosition = NewGalaxyPosition;
	Seed = NewSeed;
}

bool FSystemId::IsSystem() const
{
	return Ring + SubRing + Satellite == 0;
}

bool FSystemId::IsLocation() const
{
	return Ring + SubRing + Satellite != 0;
}

bool FSystemId::IsSameLocation(const FSystemId& System) const
{
	return SectorX == System.SectorX && SectorY == System.SectorY && SystemX == System.SystemX && SystemY == System.SystemY
	&& Ring == System.Ring && SubRing == System.SubRing;
}

bool FSystemId::IsSameSystem(const FSystemId& System) const
{
	return  SectorX == System.SectorX && SectorY == System.SectorY && SystemX == System.SystemX && SystemY == System.SystemY;
}

void FSystemId::UpdatePosition(float GalaxyWidth, float SectorWidth, float GalaxyScale, FScalableFloat Heights, float MaxHeight)
{
	float X = SectorX * GalaxyWidth * SectorWidth + SystemX * SectorWidth;
	float Y = SectorY * GalaxyWidth * SectorWidth + SystemY * SectorWidth;
	float Z = 0;
	GalaxyPosition = FVector(X, Y, Z);
}

bool FSystemId::operator==(const FSystemId& Id) const
{
	return SectorX == Id.SectorX && SectorY == Id.SectorY &&
		SystemX == Id.SystemX && SystemY == Id.SystemY &&
			Ring == Id.Ring && SubRing == Id.SubRing && Satellite == Id.Satellite; 
}

TArray<FSystemId> UGalaxyAsset::GetSystemsInSector(int X, int Y)
{
	TArray<FSystemId> Systems;
	int seed = X + Y;
	return Systems;
}

FVector UGalaxyAsset::GetDustLocation(int X, int Y) const
{
	return FVector(X * Size * SectorSize,Y * Size * SectorSize,0);
}

FVector UGalaxyAsset::ComputeGalaxyPosition(int SectorX, int SectorY, int SystemX, int SystemY, int SystemZ) const
{
	double X = SectorX * Size * SectorSize + SystemX * SectorSize;
	double Y = SectorY * Size * SectorSize + SystemY * SectorSize;
	double Z = 0;
	return FVector(X, Y, Z);
}

FSystemId UGalaxyAsset::GenerateSystemId(int SectorX, int SectorY, int SystemX, int SystemY) const
{
	//compute Z here
	double HeightAt = GetHeightAt(SectorX, SectorY);
	int64 seed = GenerateSeed(SectorX, SectorY, SystemX, SystemY);
	FMath::RandInit(seed);
	int SystemZ = FMath::RandRange(-HeightAt, HeightAt);
	FVector Position = ComputeGalaxyPosition(SectorX, SectorY, SystemX, SystemY, SystemZ);
	return FSystemId(SectorX, SectorY, SystemX, SystemY, Position, SystemZ, seed);
}

FSystemId UGalaxyAsset::GenerateLocationId(int SectorX, int SectorY, int SystemX, int SystemY, int Ring,
	int SubRing) const
{
	//compute Z here
	double HeightAt = GetHeightAt(SectorX, SectorY);
	int64 seed = GenerateSeed(SectorX, SectorY, SystemX, SystemY);
	FMath::RandInit(seed);
	int SystemZ = FMath::RandRange(-HeightAt, HeightAt);
	FVector Position = ComputeGalaxyPosition(SectorX, SectorY, SystemX, SystemY, SystemZ);
	seed += Ring + SubRing;
	return FSystemId(SectorX, SectorY, SystemX, SystemY, Position, SystemZ, seed, Ring, SubRing);
}

FSystemId UGalaxyAsset::GenerateOrbitalId(int SectorX, int SectorY, int SystemX, int SystemY, int Ring,
	int SubRing, int Satellite) const
{
	//compute Z here
	double HeightAt = GetHeightAt(SectorX, SectorY);
	int64 seed = GenerateSeed(SectorX, SectorY, SystemX, SystemY);
	FMath::RandInit(seed);
	int SystemZ = FMath::RandRange(-HeightAt, HeightAt);
	FVector Position = ComputeGalaxyPosition(SectorX, SectorY, SystemX, SystemY, SystemZ);
	seed += Ring + SubRing + Satellite;
	return FSystemId(SectorX, SectorY, SystemX, SystemY, Position, SystemZ, seed, Ring, SubRing, Satellite);
}

double UGalaxyAsset::GetHeightAt(int SectorX, int SectorY) const
{
	double HalfSize = Size/2;
	FVector2d Center(HalfSize, HalfSize);
	double Distance = FVector2D::Distance(Center, FVector2d(SectorX, SectorY)) / HalfSize;
	return Heights.GetValueAtLevel(Distance) * MaxHeight;
}

int64 UGalaxyAsset::GenerateSeed(int SectorX, int SectorY, int SystemX, int SystemY, int Ring, int SubRing,
	int Satellite) const
{
	return (SectorX + SectorY * Size) * 1000000 + (SystemX + SystemY * SectorSize) * 10000 + Ring + SubRing + Satellite;
}

TObjectPtr<USolarSystem> UGalaxyAsset::GetSystem(const FSystemId& SystemId)
{
	if(SystemId.IsLocation())
	{
		//Should Be System Id
	}
	if(KnownSystems.Contains(SystemId))
	{
		return KnownSystems[SystemId];
	}
	//See if its in out Database of Asset Systems

	if(FSolarSystemTableRow * SolarSystemTableRow = FindSolarSystem(SystemId))
	{
		return CreateSystemFromRow(SolarSystemTableRow);
	}
	USolarSystem * System = NewObject<USolarSystem>(this, SolarSystemClass);
	System->GenerateLocations(SystemId, this);
	System->FindConnectedSystems(this);
	return System;	
}

FSolarSystemTableRow* UGalaxyAsset::FindSolarSystem(const FSystemId& SystemId)
{
	TArray<FSolarSystemTableRow*> SolarSystemTableRows;
	SystemDatabase->GetAllRows(TEXT(""),SolarSystemTableRows);
	for(int i = 0; i < SolarSystemTableRows.Num(); i++)
	{
		if(SolarSystemTableRows[i]->SystemId.IsSameSystem(SystemId))
		{
			return SolarSystemTableRows[i];
		}
	}
	return nullptr;
}

USolarSystem* UGalaxyAsset::CreateSystemFromRow(FSolarSystemTableRow* Row)
{
	ensure(Row);
	USolarSystem * System = NewObject<USolarSystem>(this, SolarSystemClass);
	if(ensure(System))
	{
		
	}
	return System;
}

void UGalaxyAsset::CreateGalaxy()
{
	switch(GalaxyType)
	{
	case EGalaxyType::EGalaxyType_Spiral :
		{
			float CoreSize = 30;
			if(Settings.Contains(GalaxySpiralCoreSizeTag))
			{
				CoreSize = Settings[GalaxySpiralCoreSizeTag];
			}
			float ArmCount = 2;
			if(Settings.Contains(GalaxySpiralArmCountTag))
			{
				ArmCount = Settings[GalaxySpiralArmCountTag];
			}
			float ArmWidth = 30;
			if(Settings.Contains(GalaxySpiralArmWidthTag))
			{
				ArmWidth = Settings[GalaxySpiralArmWidthTag];
			}
			float ArmTightness = 30;
			if(Settings.Contains(GalaxySpiralArmTightnessTag))
			{
				ArmTightness = Settings[GalaxySpiralArmTightnessTag];
			}
			float ArmLength = 30;
			if(Settings.Contains(GalaxySpiralArmLengthTag))
			{
				ArmLength = Settings[GalaxySpiralArmLengthTag];
			}
			CreateSpiralGalaxy(CoreSize, ArmCount, ArmWidth, ArmTightness, ArmLength);
			break;
		}
	case EGalaxyType::EGalaxyType_Bar:
		{
			CreateBarGalaxy();
			break;
		}
	case EGalaxyType::EGalaxyType_Ring:
		{
			CreateRingGalaxy();
			break;
		}
	case EGalaxyType::EGalaxyType_Elliptical:
		{
			CreateEllipticalGalaxy();
			break;
		}
	}
}

void UGalaxyAsset::CreateSpiralGalaxy(float CoreSize, int ArmCount,float ArmWidth,float ArmTightness,float ArmLength)
{
	GalaxyData.Reset(Size * Size);
	FMath::RandInit(Seed);
	DrawCircle(Size/2,Size/2, CoreSize, CoreSize, 0,100);
	float anglePer = 360 / ArmCount;
	float angleStart = FMath::RandRange(0, 359);
	for(int Arm = 0; Arm < ArmCount; Arm++)
	{
		DrawArm(angleStart, CoreSize, 10, 100, ArmWidth, ArmTightness, ArmLength);
		angleStart += anglePer;
	}
}

void UGalaxyAsset::CreateBarGalaxy()
{
	
}

void UGalaxyAsset::CreateRingGalaxy()
{
	
}

void UGalaxyAsset::CreateEllipticalGalaxy()
{
	
}

void UGalaxyAsset::DrawCircle(int X, int Y, int SizeX, int SizeY, int MinDensity, int MaxDensity)
{
	for (int x = 0; x < SizeX; x++)
	{
		for (int y = 0; y < SizeY; y++)
		{
			if (x * x * SizeY * SizeY + y * y * SizeX * SizeX <= SizeY * SizeY * SizeX * SizeX)
			{
				float distance = FMath::Sqrt(static_cast<float>(x * x + y * y));
				int max = (int)FMath::Lerp(MaxDensity, MinDensity, distance / SizeX);
				WriteDensity(X + x, Y + y, FMath::RandRange(max - 5, max));
				WriteDensity(X - x, Y - y, FMath::RandRange(max - 5, max));
				WriteDensity(X + x, Y - y, FMath::RandRange(max - 5, max));
				WriteDensity(X - x, Y + y, FMath::RandRange(max - 5, max));
			}
		}
	}
}

void UGalaxyAsset::DrawArm(float StartAngle, float DistanceStart, float MinDensity, float MaxDensity, float ArmWidth,float ArmTightness,float ArmLength)
{
	int maxDensity = MaxDensity / 2;
	int minDensity = MaxDensity / 32;
	int step = maxDensity / ArmLength;
	float currentAngle = StartAngle;
	float previousAngle = StartAngle;
	for (int currentLength = 0; currentLength < ArmLength; currentLength++)
	{
		float size = FMath::Lerp(1, ArmWidth, 1.0f - (float)currentLength / (float)ArmLength);
		currentAngle += ArmTightness;
		for (float angle = previousAngle; angle < currentAngle; angle += 0.01f)
		{
			float x = Size/2 + FMath::Cos(FMath::DegreesToRadians(angle)) *
				(DistanceStart + currentLength);
			float y = Size/2 + FMath::Sin(FMath::DegreesToRadians(angle)) *
				(DistanceStart + currentLength);
			DrawCircle(x, y, ArmWidth, ArmWidth, MaxDensity, MinDensity);
		}
		maxDensity -= step;
		minDensity -= step;
		previousAngle = currentAngle;
	}
}


void UGalaxyAsset::WriteDensity(int x, int y, int density, bool Overwrite)
{
	int index = x + y * Size;
	if(ensure(index > 0 && index < GalaxyData.Num()))
	{
		if(Overwrite || GalaxyData[index] < density)
		{
			GalaxyData[index] = density;
		}
	}
}