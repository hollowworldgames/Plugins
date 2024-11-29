// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "DamageReportInterface.generated.h"

UENUM(BlueprintType)
enum class EDamageReportType : uint8
{
	Miss,
	NormalHit,
	GlancingHit,
	CriticalHit,
};

// This class does not need to be modified.
UINTERFACE()
class UDamageReportInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPACEGAMEPLAY_API IDamageReportInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ReportDamage(const AActor * Source, float EnergyDamage, float KineticDamage, int ShieldFace, EDamageReportType Type) = 0;
	virtual void ReportDamage(const AActor * Source, float EnergyDamage, float KineticDamage, EDamageReportType Type) = 0;
	virtual void ReportComponentDamage(const AActor * Source, float EnergyDamage, float KineticDamage,FGameplayTag Component, EDamageReportType Type) = 0;
};
