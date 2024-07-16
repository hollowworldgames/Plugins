﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "AttributeSet.h"
#include "AttributeSetBase.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "RPGAttributeSet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLevelChange, float , NewLevel);

UCLASS()
class GAMEPLAY_API URPGAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	//General
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Level);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Experience);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, IncomingExperience);
	//health
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Health);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, HealthMax);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, HealthMax);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Energy);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Energy);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, EnergyMax);
	//Damage
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, IncomingHealing);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, IncomingHealing);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, IncomingDamage1);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, IncomingDamage1);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, IncomingDamage2);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, IncomingDamage2);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, IncomingDamage3);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, IncomingDamage3);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, IncomingDamage4);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, IncomingDamage4);
	
	//Combat
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DamageBoost1);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, DamageBoost1);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DamageBoost2);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, DamageBoost2);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DamageBoost3);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, DamageBoost3);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DamageBoost4);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, DamageBoost4);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Mitigation1);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Mitigation1);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Mitigation2);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Mitigation2);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Mitigation3);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Mitigation3);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Mitigation4);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Mitigation4);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Accuracy);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Accuracy);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, BlockChance);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, BlockChance);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, BlockValue);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, BlockValue);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, GlancingBlowChance);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, GlancingBlowChance);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ParryChance);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, ParryChance);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, EvadeChance);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, EvadeChance);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Penetration);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Penetration);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CriticalChance);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, CriticalChance);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CriticalValue);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, CriticalValue);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CriticalDefense);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, CriticalDefense);
	//Basic
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, EnergyMax);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Strength);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Strength);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Agility);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Agility);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Precision);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Precision);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Luck);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Luck);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Constitution);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Constitution);
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Endurance);
	ATTRIBUTE_TAG_ACCESSOR(URPGAttributeSet, Endurance);

	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FLevelChange OnLevelChanged;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	//Experience
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Level)
	FScalableFloat LevelFromXP;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Level, Category=Level)
	FGameplayAttributeData Level;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Level)
	FGameplayTag LevelTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Experience, Category=Experience)
	FGameplayAttributeData Experience;
	UFUNCTION()
	void OnRep_Experience(const FGameplayAttributeData& OldExperience) const;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Experience)
	FGameplayTag ExperienceTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Experience)
	FGameplayAttributeData IncomingExperience;
	UFUNCTION()
	void OnRep_Level(const FGameplayAttributeData& OldLevel) const;
	//Health
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Health, Category=Health)
	FGameplayAttributeData Health;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag HealthTag;
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HealthMax, Category=Health)
	FGameplayAttributeData HealthMax;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag HealthMaxTag;
	UFUNCTION()
	void OnRep_HealthMax(const FGameplayAttributeData& OldHealthMax) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Energy, Category=Health)
	FGameplayAttributeData Energy;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag EnergyTag;
	UFUNCTION()
	void OnRep_Energy(const FGameplayAttributeData& OldEnergy) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EnergyMax, Category=Health)
	FGameplayAttributeData EnergyMax;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag EnergyMaxTag;
	UFUNCTION()
	void OnRep_EnergyMax(const FGameplayAttributeData& OldEnergyMax) const;

	//Damage Attributes
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingHealing;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag IncomingHealingTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingDamage1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag IncomingDamage1Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingDamage2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag IncomingDamage2Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingDamage3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag IncomingDamage3Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingDamage4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag IncomingDamage4Tag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_DamageBoost1, Category=Combat)
	FGameplayAttributeData DamageBoost1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag DamageBoost1Tag;
	UFUNCTION()
	void OnRep_DamageBoost1(const FGameplayAttributeData& OldDamageBoost1) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_DamageBoost2, Category=Combat)
	FGameplayAttributeData DamageBoost2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag DamageBoost2Tag;
	UFUNCTION()
	void OnRep_DamageBoost2(const FGameplayAttributeData& OldDamageBoost1) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_DamageBoost3, Category=Combat)
	FGameplayAttributeData DamageBoost3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag DamageBoost3Tag;
	UFUNCTION()
	void OnRep_DamageBoost3(const FGameplayAttributeData& OldDamageBoost3) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_DamageBoost4, Category=Combat)
	FGameplayAttributeData DamageBoost4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag DamageBoost4Tag;
	UFUNCTION()
	void OnRep_DamageBoost4(const FGameplayAttributeData& OldDamageBoost4) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Mitigation1, Category=Combat)
	FGameplayAttributeData Mitigation1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag Mitigation1Tag;
	UFUNCTION()
	void OnRep_Mitigation1(const FGameplayAttributeData& OldMitigation1) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Mitigation2, Category=Combat)
	FGameplayAttributeData Mitigation2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag Mitigation2Tag;
	UFUNCTION()
	void OnRep_Mitigation2(const FGameplayAttributeData& OldMitigation2) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Mitigation3, Category=Combat)
	FGameplayAttributeData Mitigation3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag Mitigation3Tag;
	UFUNCTION()
	void OnRep_Mitigation3(const FGameplayAttributeData& OldMitigation3) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Mitigation4, Category=Combat)
	FGameplayAttributeData Mitigation4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag Mitigation4Tag;
	UFUNCTION()
	void OnRep_Mitigation4(const FGameplayAttributeData& OldMitigation4) const;
	//Combat Attributes
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Armor, Category=Combat)
	FGameplayAttributeData Armor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag ArmorTag;
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Accuracy, Category=Combat)
	FGameplayAttributeData Accuracy;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag AccuracyTag;
	UFUNCTION()
	void OnRep_Accuracy(const FGameplayAttributeData& OldAccuracy) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BlockChance, Category=Combat)
	FGameplayAttributeData BlockChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag BlockChanceTag;
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BlockValue, Category=Combat)
	FGameplayAttributeData BlockValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag BlockValueTag;
	UFUNCTION()
	void OnRep_BlockValue(const FGameplayAttributeData& OldBlockValue) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_GlancingBlowChance, Category=Combat)
	FGameplayAttributeData GlancingBlowChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag GlancingBlowChanceTag;
	UFUNCTION()
	void OnRep_GlancingBlowChance(const FGameplayAttributeData& OldGlancingBlowChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ParryChance, Category=Combat)
	FGameplayAttributeData ParryChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag ParryChanceTag;
	UFUNCTION()
	void OnRep_ParryChance(const FGameplayAttributeData& OldParryChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EvadeChance, Category=Combat)
	FGameplayAttributeData EvadeChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag EvadeChanceTag;
	UFUNCTION()
	void OnRep_EvadeChance(const FGameplayAttributeData& OldEvadeChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Penetration, Category=Combat)
	FGameplayAttributeData Penetration;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag PenetrationTag;
	UFUNCTION()
	void OnRep_Penetration(const FGameplayAttributeData& OldPenetration) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CriticalChance, Category=Combat)
	FGameplayAttributeData CriticalChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag CriticalChanceTag;
	UFUNCTION()
	void OnRep_CriticalChance(const FGameplayAttributeData& OldCriticalChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CriticalValue, Category=Combat)
	FGameplayAttributeData CriticalValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag CriticalValueTag;
	UFUNCTION()
	void OnRep_CriticalValue(const FGameplayAttributeData& OldCriticalValue) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CriticalDefense, Category=Combat)
	FGameplayAttributeData CriticalDefense;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag CriticalDefenseTag;
	UFUNCTION()
	void OnRep_CriticalDefense(const FGameplayAttributeData& OldCriticalDefense) const;
	//Attributes
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Strength, Category=Attributes)
	FGameplayAttributeData Strength;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag StrengthTag;
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Agility, Category=Attributes)
	FGameplayAttributeData Agility;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag AgilityTag;
	UFUNCTION()
	void OnRep_Agility(const FGameplayAttributeData& OldAgility) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Precision, Category=Attributes)
	FGameplayAttributeData Precision;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag PrecisionTag;
	UFUNCTION()
	void OnRep_Precision(const FGameplayAttributeData& OldPrecision) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Luck, Category=Attributes)
	FGameplayAttributeData Luck;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag LuckTag;
	UFUNCTION()
	void OnRep_Luck(const FGameplayAttributeData& OldLuck) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Constitution, Category=Attributes)
	FGameplayAttributeData Constitution;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag ConstitutionTag;
	UFUNCTION()
	void OnRep_Constitution(const FGameplayAttributeData& OldConstitution) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Endurance, Category=Attributes)
	FGameplayAttributeData Endurance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	FGameplayTag EnduranceTag;
	UFUNCTION()
	void OnRep_Endurance(const FGameplayAttributeData& OldEndurance) const;
};
