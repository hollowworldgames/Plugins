// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "ConverterStatics.h"

double UConverterStatics::UNewtonsToKNewtons(double units)
{
	return units / 10000;
}

double UConverterStatics::UUnitsToKm(double units)
{
	return units / 100000.0;
}

double UConverterStatics::KmToUUnits(double units)
{
	return units * 100000.0;
}

FVector UConverterStatics::KmToUUnitsVector(FVector units)
{
	return units * 100000.0;
}

double UConverterStatics::UUnitsToMeters(double units)
{
	return units / 100.0;
}

double UConverterStatics::MetersToUUnits(double units)
{
	return units * 100.0;
}

double UConverterStatics::UUnitsToMm(double units)
{
	return units / 100000000.0;
}

double UConverterStatics::MmToUUnits(double units)
{
	return units * 100000000.0;
}

double UConverterStatics::UUnitsToGm(double units)
{
	return units / 100000000000.0;
}

double UConverterStatics::GmToUUnits(double units)
{
	return units * 100000000000.0;
}

double UConverterStatics::UUnitsToAU(double units)
{
	return units / 14959790000000.0;
}

double UConverterStatics::AUToUUnits(double units)
{
	return  units * 14959790000000.0;
}

double UConverterStatics::UUnitsSToC(double units)
{
	return units / 30000000000.0;
}

double UConverterStatics::CToUUnitsS(double units)
{
	return units * 30000000000.0;
}

double UConverterStatics::UUnitsSToKmh(double units)
{
	return UUnitsToMeters(units) * 3.6;
}

double UConverterStatics::KmhToUUnitsS(double units)
{
	return KmToMeters(units) / 3.6;
}

double UConverterStatics::UUnitsToFeet(double units)
{
	return units * 30.48;
}

double UConverterStatics::FeetToUUnits(double units)
{
	return units / 30.48;
}

double UConverterStatics::UUnitsToMiles(double units)
{
	return units * 160934.4;
}

double UConverterStatics::MilesToUUnits(double units)
{
	return units / 160934.4;
}

double UConverterStatics::UUnitsToYards(double units)
{
	return units * 91.44;
}

double UConverterStatics::YardsToUUnits(double units)
{
	return units / 91.44;
}

double UConverterStatics::UUnitsSToMph(double units)
{
	return units * 579363840;
}

double UConverterStatics::MphToUUnitsS(double units)
{
	return units / 44.704;
}

double UConverterStatics::UUnitsSToKnots(double units)
{
	return units * 51.444444;
}

double UConverterStatics::KnotsToUUnitsS(double units)
{
	return units / 51.444444;
}

double UConverterStatics::AirspeedKnots(double units)
{
	return units * 185199.9984;
}

double UConverterStatics::HPToNewtons(double units)
{
	return units * 745.69987158;
}

double UConverterStatics::AngleToSigned(double angle)
{
	if (angle > 180)
	{
		angle = 360 - angle;
	}
	if (angle < -180)
	{
		angle = 360 - FMath::Abs(angle);
	}
	return angle;
}

FString UConverterStatics::DistanceToString(double distance)
{
	if (distance > 100000000000)
	{
		return FString::Printf(TEXT("%.2f Gm"), UUnitsToGm(distance));
	}
	else if (distance > 100000000)
	{
		return FString::Printf(TEXT("%.2f Mm"), UUnitsToMm(distance));
	}
	else if (distance > 100000)
	{
		return FString::Printf(TEXT("%.2f Km"), UUnitsToKm(distance));
	}

	return FString::Printf(TEXT("%.2f m"), UUnitsToMeters(distance));
}

FString UConverterStatics::SpeedToString(double speed)
{
	if (speed > 100000000000)
	{
		return FString::Printf(TEXT("%.2f Gm/s"), UUnitsToGm(speed));
	}
	else if (speed > 100000000)
	{
		return FString::Printf(TEXT("%.2f Mm/s"), UUnitsToMm(speed));
	}
	else if (speed > 100000)
	{
		return FString::Printf(TEXT("%.2f Km/s"), UUnitsToKm(speed));
	}

	return FString::Printf(TEXT("%.2f m/s"), UUnitsToMeters(speed));
}

double UConverterStatics::KmToMeters(double km)
{
	return km * 1000;
}

float UConverterStatics::NewtonsToUNewtons(float newtons)
{
	return newtons * 100;
}

FVector UConverterStatics::NewtonsToUNewtonsVector(FVector newtons)
{
	return newtons * 100;
}

float UConverterStatics::KNewtonsToUNewtons(float kn)
{
	return kn * 10000;
}

FVector UConverterStatics::KNewtonsToUNewtonsVector(FVector kn)
{
	return kn * 10000;
}
