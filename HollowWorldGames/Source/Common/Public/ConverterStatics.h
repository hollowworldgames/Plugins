// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ConverterStatics.generated.h"

/**
 * 
 */
UCLASS()
class COMMON_API UConverterStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintPure)
	static double UNewtonsToKNewtons(double units);
		//metric
	UFUNCTION(BlueprintPure)
		static double UUnitsToMeters(double units);
	UFUNCTION(BlueprintPure)
		static double UUnitsToKm(double units);
	UFUNCTION(BlueprintPure)
		static double UUnitsToMm(double units);
	UFUNCTION(BlueprintPure)
		static double UUnitsToGm(double units);
	UFUNCTION(BlueprintPure)
		static double UUnitsToAU(double units);
	UFUNCTION(BlueprintPure)
		static double UUnitsSToC(double units);
	UFUNCTION(BlueprintPure)
		static double UUnitsSToKmh(double units);
	//imperial
	UFUNCTION(BlueprintPure)
		static double UUnitsToFeet(double units);
	UFUNCTION(BlueprintPure)
		static double UUnitsToYards(double units);
	UFUNCTION(BlueprintPure)
		static double UUnitsToMiles(double units);
	UFUNCTION(BlueprintPure)
		static double UUnitsSToMph(double units);
	UFUNCTION(BlueprintPure)
		static double UUnitsSToKnots(double units);

	UFUNCTION(BlueprintPure)
		static double MetersToUUnits(double units);
	UFUNCTION(BlueprintPure)
		static double KmToUUnits(double units);
	UFUNCTION(BlueprintPure)
		static FVector KmToUUnitsVector(FVector units);
	UFUNCTION(BlueprintPure)
		static double MmToUUnits(double units);
	UFUNCTION(BlueprintPure)
		static double GmToUUnits(double units);
	UFUNCTION(BlueprintPure)
		static double AUToUUnits(double units);
	UFUNCTION(BlueprintPure)
		static double CToUUnitsS(double units);
	UFUNCTION(BlueprintPure)
		static double KmhToUUnitsS(double units);
	//imperial
	UFUNCTION(BlueprintPure)
		static double FeetToUUnits(double units);
	UFUNCTION(BlueprintPure)
		static double YardsToUUnits(double units);
	UFUNCTION(BlueprintCallable)
		static double MilesToUUnits(double units);
	UFUNCTION(BlueprintPure)
		static double MphToUUnitsS(double units);
	UFUNCTION(BlueprintPure)
		static double KnotsToUUnitsS(double units);
	UFUNCTION(BlueprintPure)
		static double AirspeedKnots(double units);
	UFUNCTION(BlueprintPure)
		static double HPToNewtons(double units);
	UFUNCTION(BlueprintPure)
		static double AngleToSigned(double angle);
	UFUNCTION(BlueprintPure)
		static FString DistanceToString(double distance);
	UFUNCTION(BlueprintPure)
		static FString SpeedToString(double speed);
	UFUNCTION(BlueprintPure)
		static double KmToMeters(double km);
	UFUNCTION(BlueprintPure)
		static float NewtonsToUNewtons(float newtons);
	UFUNCTION(BlueprintPure)
		static FVector NewtonsToUNewtonsVector(FVector newtons);
	UFUNCTION(BlueprintPure)
		static float KNewtonsToUNewtons(float kn);
	UFUNCTION(BlueprintPure)
		static FVector KNewtonsToUNewtonsVector(FVector kn);
};