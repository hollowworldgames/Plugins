// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/Location.h"

#include "RandomGenerator.h"
#include "UtilityStatics.h"
#include "Data/Orbital.h"
#include "Data/SolarSystemTableRow.h"



void ULocation::Generate(FSystemId NewSystemId, UGalaxyAsset* Asset, int NewRing, int NewSubRing, double NewRadius)
{
	SystemId = Asset->GenerateLocationId(NewSystemId.SectorX, NewSystemId.SectorY, NewSystemId.SystemX, NewSystemId.SystemY, NewRing, NewSubRing);
	Radius = NewRadius;
	OrbitRate = ((OrbitalK * 2 * PI) / 360.0) / Radius;
	RotationRate = 2 * PI / RotationalK; 
}

void ULocation::Generate(FSystemLocation Location)
{
	LocationType = Location.LocationType;
	SystemId = Location.SystemId;
	Radius = Location.Radius;
	Eccentricity = Location.Eccentricity;
	StartAngle = Location.StartAngle;
	AxialTilt = Location.AxialTilt;
	OrbitRate = ((OrbitalK * 2 * PI) / 360.0) / Radius;
	RotationRate = 2 * PI / RotationalK;

	for(FSystemOrbital SystemOrbital : Location.Orbitals)
	{
		switch (LocationType)
		{
		case ELocationType::ELocationType_Planet:
			{
				switch(SystemOrbital.OrbitalType)
				{
				case EOrbitalType::EOrbitalType_Planet:
				case EOrbitalType::EOrbitalType_Moon:
					{
						UOrbital * Orbital = NewObject<UOrbital>(this, UPlanetoid::StaticClass());
						if(ensure(Orbital))
						{
							Orbital->Generate(SystemOrbital);
							Orbitals.Add(Orbital);
						}
						break;
					}
				case EOrbitalType::EOrbitalType_Asteroid:
					{
						UOrbital * Orbital = NewObject<UOrbital>(this, UAsteroidOrbital::StaticClass());
						if(ensure(Orbital))
						{
							Orbital->Generate(SystemOrbital);
							Orbitals.Add(Orbital);
						}
						break;
					}
				case EOrbitalType::EOrbitalType_Cloud:
					{
						UOrbital * Orbital = NewObject<UOrbital>(this, UCloudOrbital::StaticClass());
						if(ensure(Orbital))
						{
							Orbital->Generate(SystemOrbital);
							Orbitals.Add(Orbital);
						}
						break;
					}
				}
			}
		case ELocationType::ELocationType_AsteroidCluster:
			{
				UOrbital * Orbital = NewObject<UOrbital>(this, UFieldAsteroid::StaticClass());
				if(ensure(Orbital))
				{
					Orbital->Generate(SystemOrbital);
					Orbitals.Add(Orbital);
				}
				break;
			}
		case ELocationType::ELocationType_Comet:
			{
				break;
			}
		default :
			{
				break;
			}
		}
	}
}

FVector ULocation::GetPosition() const
{
	if (Radius == 0.0)
	{
		return FVector::Zero();
	}
	double degree = (FDateTime::Now().GetTicks() / TimeDivisor) * OrbitRate + FMath::Fmod(StartAngle , 360);
	return FVector(FMath::Cos(FMath::DegreesToRadians(degree)) * Radius, 0, FMath::Sin(FMath::DegreesToRadians(degree)) * (Radius * Eccentricity));
}

FRotator ULocation::GetRotation() const
{
	double degree = (FDateTime::Now().GetTicks() / TimeDivisor) * FMath::Fmod(RotationRate , 360);
	return FRotator(AxialTilt, degree, 0.0);
}

void UPlanet::Generate(FSystemId NewSystemId, UGalaxyAsset* Asset, int NewRing, int NewSubRing, double NewRadius)
{
	Super::Generate(NewSystemId, Asset, NewRing, NewSubRing, NewRadius);
	FRandomGenerator64 Random(SystemId.GetSeed());
	ensure(RingTypeChances.Contains(NewRing));
	FRingChanceData ChanceData = RingTypeChances[Ring];
	Type = Random.GetRandomItem(ChanceData.Chances);
	ensure(SatelliteChances.Contains(Type));
	FSatelliteChance SatChance = SatelliteChances[Type];
	Ring = Random.ChanceRoll(RingChances[Type], 100);

	UPlanetoid* Planetoid = NewObject<UPlanetoid>(this, PlanetoidClass);
	if(ensure(Planetoid))
	{
		Planetoid->SetPlanetType(Type);
		Planetoid->SetPlanetSize(Size);
		Planetoid->SetShowRing(Ring);
		Planetoid->SetAtmosphere(EAtmosphereType::EAtmosphereType_None);
		Orbitals.Add(Planetoid);
	}
	
	int NextSatellite = 1;
	double SatelliteRadius = 5 * 1;
	int SatelliteCount = Random.RandRange(SatChance.MinMoons, SatChance.MaxMoons);
	while(SatelliteCount-- > 0)
	{
		EPlanetType SatelliteType = Random.GetRandomItem(SatChance.Chances);
		switch(SatelliteType)
		{
		case EPlanetType::EPlanetType_Rocky:
		case EPlanetType::EPlanetType_Barren:
		case EPlanetType::EPlanetType_Lava:
		case EPlanetType::EPlanetType_Temperate:
		case EPlanetType::EPlanetType_Ice:
			{
				Planetoid = NewObject<UPlanetoid>(this, PlanetoidClass);
				if(ensure(Planetoid))
				{
					Planetoid->Generate(SystemId, Asset, SatelliteRadius, NextSatellite++);
					Orbitals.Add(Planetoid);
				}
				break;
			}
		case EPlanetType::EPlanetType_Asteroid:
			{
				UAsteroidOrbital* Asteroid = NewObject<UAsteroidOrbital>(this, AsteroidClass);
				if(ensure(Asteroid))
				{
					Asteroid->Generate(SystemId, Asset, SatelliteRadius, NextSatellite++);
					Orbitals.Add(Asteroid);
				}
				break;
			}
		default: ensure(false); break;
		}
	}
}

void UAsteroidField::Generate(FSystemId NewSystemId, UGalaxyAsset* Asset, int NewRing, int NewSubRing, double NewRadius)
{
	Super::Generate(NewSystemId, Asset, NewRing, NewSubRing, NewRadius);
	FRandomGenerator64 Random(SystemId.GetSeed());
	int AsteroidCount = Random.RandRange(MinAsteroids, MaxAsteroids);
	double SpawnRadius = 0;
	while(AsteroidCount-- > 0)
	{
		UFieldAsteroid * Asteroid = NewObject<UFieldAsteroid>(this);
		Asteroid->Generate(SystemId, Asset, SpawnRadius, AsteroidCount);
		if(AsteroidCount % 2 == 0)
		{
			Radius += ExpandM;
		}
		Orbitals.Add(Asteroid);
	}
}

void UComet::Generate(FSystemId NewSystemId, UGalaxyAsset* Asset, int NewRing, int NewSubRing, double NewRadius)
{
	Super::Generate(NewSystemId, Asset, NewRing, NewSubRing, NewRadius);
	FRandomGenerator64 Random(SystemId.GetSeed());
	
}
