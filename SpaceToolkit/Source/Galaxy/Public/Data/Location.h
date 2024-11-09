// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GalaxyAsset.h"
#include "UObject/Object.h"
#include "Location.generated.h"

class UAsteroidOrbital;
class UPlanetoid;
class UOrbital;

UENUM(BlueprintType)
enum class EPlanetType : uint8
{
	EPlanetType_Rocky,
	EPlanetType_Barren,
	EPlanetType_Lava,
	EPlanetType_Temperate,
	EPlanetType_GasGiant,
	EPlanetType_Ice,
	EPlanetType_Asteroid,
};

USTRUCT(Blueprintable, BlueprintType)
struct FRingChanceData
{
	GENERATED_BODY();
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	TArray<EPlanetType> Chances;
};

USTRUCT(Blueprintable, BlueprintType)
struct FSatelliteChance
{
	GENERATED_BODY();
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	TArray<EPlanetType> Chances;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	int MinMoons = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	int MaxMoons = 10;
};

UCLASS(Blueprintable, BlueprintType)
class GALAXY_API ULocation : public UObject
{
	GENERATED_BODY()
public :
	virtual void Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, int NewRing, int NewSubRing, double NewRadius);
	virtual FVector GetPosition() const;
	virtual FRotator GetRotation() const;
	FSystemId GetSystemId() const { return SystemId; }
	UFUNCTION(BlueprintPure)
	TArray<UOrbital*> GetOrbitals() const { return Orbitals; }
	UFUNCTION(BlueprintPure)
	ELocationType GetLocationType() const { return LocationType; }
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	ELocationType LocationType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	FSystemId SystemId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	double Radius = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	TArray<UOrbital*> Orbitals;
};

UCLASS(Blueprintable, BlueprintType)
class GALAXY_API UPlanet : public ULocation
{
	GENERATED_BODY()
public :
	virtual void Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, int NewRing, int NewSubRing, double NewRadius) override;
	EPlanetType GetPlanetType() const { return Type; }
	bool HasRing() const { return Ring; }
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	EPlanetType Type;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	bool Ring = false;
	double Size = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GeneratorSettings)
	TMap<int , FRingChanceData> RingTypeChances;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GeneratorSettings)
	TMap<EPlanetType, int> RingChances; //out of 100
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GeneratorSettings)
	TMap<EPlanetType, FSatelliteChance> SatelliteChances;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GeneratorSettings)
	int MinClouds = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GeneratorSettings)
	int MaxClouds = 3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GeneratorSettings)
	int HabitableZoneStart = 3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GeneratorSettings)
	int HabitableZoneEnd = 5;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Classes)
	TSubclassOf<UPlanetoid> PlanetoidClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Classes)
	TSubclassOf<UAsteroidOrbital> AsteroidClass;
};

UCLASS(Blueprintable, BlueprintType)
class GALAXY_API UAsteroidField : public ULocation
{
	GENERATED_BODY()
public :
	virtual void Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, int NewRing, int NewSubRing, double NewRadius) override;
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	int MinAsteroids = 30;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	int MaxAsteroids = 50;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	double ExpandM = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	TSubclassOf<class UFieldAsteroid> AsteroidClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	double HeightKm = 200.0;
};

UCLASS(Blueprintable, BlueprintType)
class GALAXY_API UComet : public ULocation
{
	GENERATED_BODY()
public :
	virtual void Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, int NewRing, int NewSubRing, double NewRadius) override;
};