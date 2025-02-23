// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/GameplayStructs.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayUtilities.generated.h"


class UGameplayEffect;
struct FCustomEffectValue;



UCLASS()
class GAMEPLAY_API UGameplayUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public :
	//Combat roll for full Tab Target Style Combat
	static ECombatRollResult DoCombatRoll(float& Damage, float Accuracy, float Mitigation, float BlockChance,
													   float BlockValue, float ParryChance, float EvadeChance, float GlanceChance, float GlanceValue,
													   float CriticalChance, float CriticalDefense, float CriticalValue, float PenetrationChance, float PenetrationValue);
	static ECombatRollResult DoCombatRoll(FVector4f& Damage, float Accuracy, FVector4f Mitigation, float BlockChance,
	                                                   float BlockValue, float ParryChance, float EvadeChance, float GlanceChance, float GlanceValue,
	                                                   float CriticalChance, float CriticalDefense, float CriticalValue, float PenetrationChance, float PenetrationValue);
	static ECombatRollResult DoActionCombatRoll(float& Damage, float Accuracy, float Mitigation, float CriticalChance, float CriticalDefense,
		float CriticalValue, float PenetrationChance, float PenetrationValue);
	static float ApplyMitigation(float Damage, float Mitigation);
	static FVector4f ApplyMitigation(FVector4f Damage, float Mitigation1, float Mitigation2, float Mitigation3, float Mitigation4);
	static bool ApplyCriticalHit(float& Damage, float CriticalChance, float CriticalDefense, float CriticalValue);
	static bool ApplyCriticalHit(FVector4f& Damage, float CriticalChance, float CriticalDefense, float CriticalValue);
	static ECombatRollResult DoCombatRoll(float HitChance, float EvadeChance, float GlanceChance);
	UFUNCTION(BlueprintCallable)
	static void ApplyEffectToTarget(const TSubclassOf<UGameplayEffect>& Effect, float Level, AActor* Target, const AActor* Source,
	                                const TArray<FCustomEffectValue>& CustomValues);
	UFUNCTION(BlueprintCallable)
	static void ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& Effect, float Level, AActor* Source,
								const TArray<FCustomEffectValue>& CustomValues);
	UFUNCTION(BlueprintCallable)
	static void RemoveEffect(const TSubclassOf<UGameplayEffect>& Effect, AActor * Source);
	UFUNCTION(BlueprintCallable)
	static void RunAbility(FGameplayTag Ability, AActor* Target, AActor* Source, float Magnitude);
	static float ParryValue;
};
