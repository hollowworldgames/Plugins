//Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once


UENUM(BlueprintType)
enum class EGalaxyType : uint8
{
	EGalaxyType_Spiral UMETA(DisplayName = "Spiral"),
	EGalaxyType_Bar UMETA(DisplayName = "Bar"),
	EGalaxyType_Ring UMETA(DisplayName = "Ring"),
	EGalaxyType_Elliptical UMETA(DisplayName = "Elliptical"),
};

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

UENUM(BlueprintType)
enum class EOrbitalType : uint8
{
	EOrbitalType_Planet,
	EOrbitalType_Moon,
	EOrbitalType_Asteroid,
	EOrbitalType_FieldAsteroid,
	EOrbitalType_Cloud,
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

UENUM(BlueprintType)
enum class ELocationType : uint8
{
	ELocationType_System,
	ELocationType_Nebula,
	ELocationType_Sun,
	ELocationType_Planet,
	ELocationType_AsteroidCluster,
	ELocationType_Comet,
};