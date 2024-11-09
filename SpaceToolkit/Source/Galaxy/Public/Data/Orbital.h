// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GalaxyAsset.h"
#include "Location.h"
#include "UObject/Object.h"
#include "Orbital.generated.h"

UENUM(BlueprintType)
enum class EOrbitalType : uint8
{
	EOrbitalType_Planet,
	EOrbitalType_Moon,
	EOrbitalType_Asteroid,
	EOrbitalType_Cloud,
};

UCLASS(BlueprintType, Blueprintable)
class GALAXY_API UOrbital : public UObject
{
	GENERATED_BODY()
public :
	virtual void Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, double NewRadius, int Satellite);
	UFUNCTION(BlueprintPure)
	virtual EOrbitalType GetOrbitalType() const;
	UFUNCTION(BlueprintPure)
	virtual FVector GetOrbitalLocation() const;
	UFUNCTION(BlueprintPure)
	virtual FRotator GetOrbitalRotation() const;
	UFUNCTION(BlueprintPure)
	virtual FVector GetOrbitalScale() const;
	UFUNCTION(BlueprintPure)
	FSystemId GetSystemId() const { return SystemId; }
protected :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSystemId SystemId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Radius = 0;
};

UENUM(BlueprintType)
enum class EAtmosphereType : uint8
{
	EAtmosphereType_None,
	EAtmosphereType_Oxygen,
	EAtmosphereType_OxygenNitrogen,
	EAtmosphereType_Nitrogen,
	EAtmosphereType_Helium,
	EAtmosphereType_Hydrogen,
	EAtmosphereType_CarbonDioxide,
	EAtmosphereType_Methane,
	EAtmosphereType_SulphurDioxide,
};

USTRUCT(BlueprintType)
struct FAtmosphereChoices
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<EAtmosphereType> Choices;
};

USTRUCT(BlueprintType)
struct FPlanetSizeChoice
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	double MinSizeKm = 1000;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	double MaxSizeKm = 3000;
};

UCLASS(BlueprintType, Blueprintable)
class GALAXY_API UPlanetoid : public UOrbital
{
	GENERATED_BODY()
public :
	virtual EOrbitalType GetOrbitalType() const override { return EOrbitalType::EOrbitalType_Planet; }
	void SetPlanetType(EPlanetType NewType) { PlanetType = NewType; }
	UFUNCTION(BlueprintPure)
	EPlanetType GetPlanetType() const { return PlanetType; }
	void SetPlanetSize(double NewSize) { SizeKm = NewSize; }
	void SetShowRing(bool NewShowRing) { ShowRing = NewShowRing; }
	void SetAtmosphere(EAtmosphereType NewType) { AtmosphereType = NewType; }
	virtual void Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, double NewRadius, int Satellite) override;
	virtual FVector GetOrbitalScale() const override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPlanetType PlanetType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAtmosphereType AtmosphereType = EAtmosphereType::EAtmosphereType_None;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GeneratorSettings)
	TMap<EPlanetType, FSatelliteChance> SatelliteChances;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GeneratorSettings)
	TMap<EPlanetType, FAtmosphereChoices> AtmosphereChoices;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GeneratorSettings)
	TMap<EPlanetType, FPlanetSizeChoice> PlanetSizeChoices;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	double SizeKm = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool ShowRing = false;
};

//Asteroid Orbiting a planet
UCLASS(BlueprintType, Blueprintable)
class GALAXY_API UAsteroidOrbital : public UOrbital
{
	GENERATED_BODY()
public :
	virtual EOrbitalType GetOrbitalType() const override { return EOrbitalType::EOrbitalType_Asteroid; }
	virtual void Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, double NewRadius, int Satellite) override;
	virtual FVector GetOrbitalScale() const override { return Scale; }
	virtual FRotator GetOrbitalRotation() const override { return Rotation; }
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	double MaxSizeM = 200;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	double MinSizeM = 50;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	FVector MinSizeVariation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	FVector MaxSizeVariation;
	FVector Scale;
	FRotator Rotation;
};

//Asteroid in an asteroid field
UCLASS(BlueprintType, Blueprintable)
class GALAXY_API UFieldAsteroid : public UAsteroidOrbital
{
	GENERATED_BODY()
public :
	virtual EOrbitalType GetOrbitalType() const override { return EOrbitalType::EOrbitalType_Asteroid; }
	virtual void Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, double NewRadius, int Satellite) override;
	virtual FVector GetOrbitalLocation() const override { return Location; }
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	double MaxHeightKm = 1;
	FVector Location;
};




//dust and gas micro-nebula orbiting a planet

UCLASS(BlueprintType, Blueprintable)
class GALAXY_API UCloudOrbital : public UOrbital
{
	GENERATED_BODY()
public :
	virtual EOrbitalType GetOrbitalType() const override { return EOrbitalType::EOrbitalType_Cloud; }
	virtual void Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, double NewRadius, int Satellite) override;
protected :
};