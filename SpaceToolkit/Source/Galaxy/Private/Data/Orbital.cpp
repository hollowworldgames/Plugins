// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/Orbital.h"

#include "ConverterStatics.h"
#include "RandomGenerator.h"
#include "SceneRenderTargetParameters.h"


void UOrbital::Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, double NewRadius, int Satellite)
{
	SystemId = Asset->GenerateOrbitalId(NewSystemId.SectorX, NewSystemId.SectorY, NewSystemId.SystemX,
		NewSystemId.SystemY, NewSystemId.Ring, NewSystemId.SubRing, Satellite);
	Radius = NewRadius;
	
}

EOrbitalType UOrbital::GetOrbitalType() const
{
	return EOrbitalType::EOrbitalType_Planet;
}

FVector UOrbital::GetOrbitalLocation() const
{
	if(Radius > 0.0)
	{
		
	}
	return FVector::ZeroVector;
}

FRotator UOrbital::GetOrbitalRotation() const
{
	return FRotator();
}

FVector UOrbital::GetOrbitalScale() const
{
	return FVector::OneVector;
}

void UPlanetoid::Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, double NewRadius, int Satellite)
{
	Super::Generate(NewSystemId, Asset, NewRadius, Satellite);
	FRandomGenerator64 Random(SystemId.GetSeed());
	if(Satellite > 0)
	{
		if(ensure(SatelliteChances.Contains(PlanetType)) && ensure(PlanetSizeChoices.Contains(PlanetType)))
		{
			PlanetType = Random.GetRandomItem(SatelliteChances[PlanetType].Chances);
			FPlanetSizeChoice Choice = PlanetSizeChoices[PlanetType];
			SizeKm = Random.RandRange(Choice.MinSizeKm, Choice.MaxSizeKm);	
		}
	}

	if(AtmosphereChoices.Contains(PlanetType))
	{
		AtmosphereType = Random.GetRandomItem(AtmosphereChoices[PlanetType].Choices);
	}
}

FVector UPlanetoid::GetOrbitalScale() const
{
	double S = UConverterStatics::KmToUUnits(SizeKm);
	return FVector(S, S, S);
}

void UFieldAsteroid::Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, double NewRadius, int Satellite)
{
	Super::Generate(NewSystemId, Asset, NewRadius, Satellite);
	FRandomGenerator64 Random(SystemId.GetSeed());
	double Angle = 0;
	if(Satellite%2 == 0)
	{
		Angle = Random.RandRange(30, 150);
	}
	else
	{
		Angle = Random.RandRange(210, 320);
	}
	Location = FVector(FMath::Cos(Angle) * Radius, FMath::Sin(Angle) * Radius, UConverterStatics::KmToUUnits(Random.RandRange(-MaxHeightKm, MaxHeightKm)));
}

void UAsteroidOrbital::Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, double NewRadius, int Satellite)
{
	Super::Generate(NewSystemId, Asset, NewRadius, Satellite);
	FRandomGenerator64 Random(NewSystemId.GetSeed());
	Scale = Random.RandVector(MinSizeVariation, MaxSizeVariation);
	Scale *= UConverterStatics::MetersToUUnits(Random.RandRange(MinSizeM, MaxSizeM));
	Rotation = Random.RandRotation();
}

void UCloudOrbital::Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, double NewRadius, int Satellite)
{
	Super::Generate(NewSystemId, Asset, NewRadius, Satellite);
	FRandomGenerator64 Random(SystemId.GetSeed());
}
