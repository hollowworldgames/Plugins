// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Orbital.h"
#include "UObject/Object.h"
#include "Data/GalaxyAsset.h"
#include "Utility/GalaxyGameInstance.h"
#include "SolarSystem.generated.h"

class UAsteroidField;
class UPlanet;
class UComet;
/**
 * 
 */
UCLASS()
class GALAXY_API USolarSystem : public UObject
{
	GENERATED_BODY()
public :
	void GenerateLocations(FSystemId NewSystemId, UGalaxyAsset * Asset);
	void GenerateLocations(FSolarSystemTableRow * Row, UGalaxyAsset * Asset);
	void FindConnectedSystems(TObjectPtr<UGalaxyAsset> GalaxyAsset);
	ULocation* GetLocation(const FSystemId& LocationId);
	TArray<TObjectPtr<class UStar>> GetStars() const { return Stars; }
	FSystemId GetSystemId() const { return SystemId; }
protected :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<ULocation>> Locations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<UStar>> Stars;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSystemId> ConnectedSystems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Classes)
	TSubclassOf<UStar> StarClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Classes)
	TSubclassOf<UPlanet> PlanetoidClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Classes)
	TSubclassOf<UAsteroidField> AsteroidFieldClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Classes)
	TSubclassOf<UComet> CometClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generator Settings")
	float AsteroidChance; //should only be planet or asteroid ring
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generator Settings")
	int MinLocations = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generator Settings")
	int MaxLocations = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generator Settings")
	int MinStars = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generator Settings")
	int MaxStars = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generator Settings")
	int MinComets = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generator Settings")
	int MaxComets = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FSystemId SystemId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generator Settings")
	float ExpandFactor = 1.2f;
};
