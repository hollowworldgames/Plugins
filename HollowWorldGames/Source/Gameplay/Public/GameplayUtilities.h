// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayUtilities.generated.h"


UENUM(BlueprintType)
enum ECombatRollResult
{
	Miss UMETA(DisplayName = "Miss"),
	Hit UMETA(DisplayName = "Hit"),
	Glance UMETA(DisplayName = "Glance"),
	Block UMETA(DisplayName = "Block"),
	Parry UMETA(DisplayName = "Parry"),
	Evade UMETA(DisplayName = "Evade"),
	CriticalHit UMETA(DisplayName = "Critical Hit"),
	PenetratingHit UMETA(DisplayName = "Penetrating Hit"),
	DamageOverTime UMETA(Displayname = "Damage Over Time")
};

UCLASS()
class GAMEPLAY_API UGameplayUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public :
	static ECombatRollResult DoCombatRoll(FVector4f& Damage, float Accuracy, FVector4f Mitigation, float BlockChance,
	                                                   float BlockValue, float ParryChance, float EvadeChance, float GlanceChance, float GlanceValue,
	                                                   float CriticalChance, float CriticalDefense, float CriticalValue, float PenetrationChance, float PenetrationValue);
	static float ApplyMitigation(float Damage, float Mitigation);
	static FVector4f ApplyMitigation(FVector4f Damage, float Mitigation1, float Mitigation2, float Mitigation3, float Mitigation4);
	static bool ApplyCriticalHit(FVector4f& Damage, float CriticalChance, float CriticalDefense, float CriticalValue);
	static ECombatRollResult DoCombatRoll(float HitChance, float EvadeChance, float GlanceChance);
	static float ParryValue;
};
