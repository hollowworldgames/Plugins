//Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GalaxyEnums.h"
#include "SystemId.h"
#include "Location.h"
#include "UObject/Object.h"
#include "Orbital.generated.h"



UCLASS(BlueprintType, Blueprintable)
class GALAXY_API UOrbital : public UObject
{
	GENERATED_BODY()
public :
	virtual void Generate(FSystemId NewSystemId, UGalaxyAsset * Asset, double NewRadius, int Satellite);
	virtual void Generate(FSystemOrbital Orbital);
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
	virtual void Generate(FSystemOrbital Orbital) override;
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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Gravity = 1.0f;
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
	UStaticMesh * GetMesh() const { return Mesh; }
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	double MaxSizeM = 200;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	double MinSizeM = 50;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	FVector MinSizeVariation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	FVector MaxSizeVariation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	TArray<TObjectPtr<UStaticMesh>> MeshChoices;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FVector Scale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FRotator Rotation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TObjectPtr<UStaticMesh> Mesh;
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
	virtual FRotator GetOrbitalRotation() const override { return Rotation; }
	void SetInstanceId(int32 NewInstanceId);
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=GenerationSettings)
	double MaxHeightKm = 1;
	FVector Location;
	FRotator Rotation;
	int32 InstanceId = -1;
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