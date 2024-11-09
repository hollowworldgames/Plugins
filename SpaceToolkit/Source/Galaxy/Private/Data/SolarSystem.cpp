// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/SolarSystem.h"

#include "RandomGenerator.h"
#include "Data/Location.h"
#include "Data/Star.h"

void USolarSystem::GenerateLocations(FSystemId SystemId, UGalaxyAsset * Asset)
{
	FRandomGenerator64 Random(SystemId.GetSeed());
	int StarCount = Random.RandRange(MaxStars, MaxStars);
	int LocationCount = Random.RandRange(MinLocations, MaxLocations);
	int CometCount = Random.RandRange(MinComets, MaxComets);
	int Ring = 0;
	float Radius = 0;
	while(StarCount-- > 0)
	{
		FSystemId Id = Asset->GenerateLocationId(SystemId.SectorX, SystemId.SectorY, SystemId.SystemX, SystemId.SystemY, Ring, 0);
		UStar * Star = NewObject<UStar>(StarClass);
		if(ensure(Star))
		{
			Star->Generate(Id, Asset, Ring, Radius);
			Radius += Star->GetSize() * ExpandFactor;
			Stars.Add(Star);
		}
	}

	while(LocationCount-- > 0)
	{
		if(Random.RandRange(0, 100) < AsteroidChance)
		{
			int FieldCount = Random.RandRange(5, 8);
			int SubRing = 0;
			while(FieldCount-- > 0)
			{
				UAsteroidField * AsteroidField = NewObject<UAsteroidField>(this, AsteroidFieldClass);
				if(ensure(AsteroidField))
				{
					AsteroidField->Generate(SystemId, Asset, Ring, SubRing++, Radius);
					Locations.Add(AsteroidField);
				}
			}
		}
		else
		{
			UPlanet * Planet = NewObject<UPlanet>(this, PlanetoidClass);
			if(ensure(Planet))
			{
				Planet->Generate(SystemId, Asset, Ring, 0, Radius);
				Locations.Add(Planet);
			}
		}
		Radius *= ExpandFactor;
	}

	while(CometCount-- > 0)
	{
		UComet * Comet = NewObject<UComet>(this, CometClass);
		if(ensure(Comet))
		{
			Comet->Generate(SystemId, Asset, Ring, CometCount, Radius);
			Locations.Add(Comet);
		}
	}
}

void USolarSystem::FindConnectedSystems(TObjectPtr<UGalaxyAsset> GalaxyAsset)
{
	
}
