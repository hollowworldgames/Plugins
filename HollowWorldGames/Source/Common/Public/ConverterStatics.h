// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ConverterStatics.generated.h"

UENUM(BlueprintType)
enum class EDistanceMeasure : uint8
{
	Metric,
	Imperial,
};

UCLASS()
class COMMON_API UConverterStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintPure, Category = "Conversions")
	static double UNewtonsToKNewtons(double units);
		//metric
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double UUnitsToMeters(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double UUnitsToKm(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double UUnitsToMm(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double UUnitsToGm(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double UUnitsToAU(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double UUnitsSToC(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double UUnitsSToKmh(double units);
	//imperial
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double UUnitsToFeet(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double UUnitsToYards(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double UUnitsToMiles(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double UUnitsSToMph(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double UUnitsSToKnots(double units);

	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double MetersToUUnits(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double KmToUUnits(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static FVector KmToUUnitsVector(FVector units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double MmToUUnits(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double GmToUUnits(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double AUToUUnits(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double CToUUnitsS(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double KmhToUUnitsS(double units);
	//imperial
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double FeetToUUnits(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double YardsToUUnits(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double MilesToUUnits(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double MphToUUnitsS(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double KnotsToUUnitsS(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double AirspeedKnots(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double HPToNewtons(double units);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double AngleToSigned(double angle);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static FString DistanceToString(double distance, EDistanceMeasure Measure = EDistanceMeasure::Metric);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static FString SpeedToString(double speed);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static double KmToMeters(double km);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static float NewtonsToUNewtons(float newtons);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static FVector NewtonsToUNewtonsVector(FVector newtons);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static float KNewtonsToUNewtons(float kn);
	UFUNCTION(BlueprintPure, Category = "Conversions")
		static FVector KNewtonsToUNewtonsVector(FVector kn);
};