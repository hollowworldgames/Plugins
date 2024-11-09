// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/Location.h"

#include "RandomGenerator.h"
#include "UtilityStatics.h"
#include "Data/Orbital.h"
#include "DSP/DynamicsProcessor.h"


void ULocation::Generate(FSystemId NewSystemId, UGalaxyAsset* Asset, int NewRing, int NewSubRing, double NewRadius)
{
	SystemId = Asset->GenerateLocationId(NewSystemId.SectorX, NewSystemId.SectorY, NewSystemId.SystemX, NewSystemId.SystemY, NewRing, NewSubRing);
	Radius = NewRadius;
}

FVector ULocation::GetPosition() const
{
	return FVector();
}

FRotator ULocation::GetRotation() const
{
	return FRotator();
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
