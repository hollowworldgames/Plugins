// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/Star.h"

#include "RandomGenerator.h"

void UStar::Generate(const FSystemId& SystemId, UGalaxyAsset * Asset, double NewRadius, int NewRing)
{
	Id = Asset->GenerateLocationId(SystemId.SectorX, SystemId.SectorY, SystemId.SystemX, SystemId.SystemY, NewRing, 0);
	FRandomGenerator64 Random; 
	Size = Random.RandRange(MinStarSize, MaxStarSize);
	Temperature = Random.RandRange(0, 1);
	Ring = NewRing;
	Radius = NewRadius;
}
