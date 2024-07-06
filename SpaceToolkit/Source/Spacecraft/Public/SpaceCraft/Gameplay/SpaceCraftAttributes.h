// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "AttributeSet.h"
#include "SpaceCraftAttributes.generated.h"

/**
 * 
 */
UCLASS()
class SPACECRAFT_API USpaceCraftAttributes : public UAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, HullLevel);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, HullHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, MaxHullHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, HullCriticalDefense);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, HullEnergyMitigationBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, HullPhysicalMitigationBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldLevel);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldOn);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldHealthBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldFrontBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldBackBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldPhysicalMitigationBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldEnergyMitigationBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, MaxShieldHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldCriticalDefense);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldPhysicalMitigation);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldEnergyMitigation);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, FrontShieldHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, MaxFrontShieldHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, BackShieldHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, MaxBackShieldHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, HullPhysicalMitigation);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, HullEnergyMitigation);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingHullEnergyDamage);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingHullPhysicalDamage);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingHullHealing);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingFrontEnergyDamage);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingFrontPhysicalDamage);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingBackEnergyDamage);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingBackPhysicalDamage);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingReactorDamage);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingReactorHealing);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingShieldDamage);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingShieldHealing);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingBatteryDamage);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingBatteryHealing);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingEngineDamage);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, IncomingEngineHealing);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ReactorLevel);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ReactorBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ReactorHealthBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ReactorHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, MaxReactorHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, PowerGenerated);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, BatteryPower);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, MaxBatteryPower);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, BatteryLevel);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, BatteryBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, BatteryHealthBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, BatteryHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, MaxBatteryHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, WeaponPower);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, WeaponDistribution);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldPower);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, ShieldDistribution);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, EnginePower);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, EngineDistribution);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, EngineOn);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, EngineLevel);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, EngineBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, EngineHealthBoost);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, EngineHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, MaxEngineHealth);
	ATTRIBUTE_ACCESSORS(USpaceCraftAttributes, EngineThrust);
protected :
	//Health Attributes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HullLevel, Category=Health)
	FGameplayAttributeData HullLevel;
	UFUNCTION()
	void OnRep_HullLevel(const FGameplayAttributeData& OldHullLevel) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Shield)
	FGameplayAttributeData HullBoost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Shield)
	FGameplayAttributeData HullPhysicalMitigationBoost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Shield)
	FGameplayAttributeData HullEnergyMitigationBoost;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HullHealth, Category=Health)
	FGameplayAttributeData HullHealth;
	UFUNCTION()
	void OnRep_HullHealth(const FGameplayAttributeData& OldHullHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxHullHealth, Category=Health)
	FGameplayAttributeData MaxHullHealth;
	UFUNCTION()
	void OnRep_MaxHullHealth(const FGameplayAttributeData& OldMaxHullHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HullPhysicalMitigation, Category=Health)
	FGameplayAttributeData HullPhysicalMitigation;
	UFUNCTION()
	void OnRep_HullPhysicalMitigation(const FGameplayAttributeData& OldHullPhysicalMitigation) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HullEnergyMitigation, Category=Health)
	FGameplayAttributeData HullEnergyMitigation;
	UFUNCTION()
	void OnRep_HullEnergyMitigation(const FGameplayAttributeData& OldHullEnergyMitigation) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HullCriticalDefense, Category=Health)
	FGameplayAttributeData HullCriticalDefense;
	UFUNCTION()
	void OnRep_HullCriticalDefense(const FGameplayAttributeData& OldHullCriticalDefense) const;
	
    //Shield Attributes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldOn, Category=Shield)
	FGameplayAttributeData ShieldOn;
	UFUNCTION()
	void OnRep_ShieldOn(const FGameplayAttributeData& OldShieldOn) const;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldLevel, Category=Shield)
	FGameplayAttributeData ShieldLevel;
	UFUNCTION()
	void OnRep_ShieldLevel(const FGameplayAttributeData& OldShieldLevel) const;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Shield)
	FGameplayAttributeData ShieldBoost;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Shield)
	FGameplayAttributeData ShieldHealthBoost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Shield)
	FGameplayAttributeData ShieldFrontBoost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Shield)
	FGameplayAttributeData ShieldBackBoost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Shield)
	FGameplayAttributeData ShieldPhysicalMitigationBoost;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Shield)
	FGameplayAttributeData ShieldEnergyMitigationBoost;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldHealth, Category=Shield)
	FGameplayAttributeData ShieldHealth;
	UFUNCTION()
	void OnRep_ShieldHealth(const FGameplayAttributeData& OldShieldHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxShieldHealth, Category=Shield)
	FGameplayAttributeData MaxShieldHealth;
	UFUNCTION()
	void OnRep_MaxShieldHealth(const FGameplayAttributeData& OldMaxShieldHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldCriticalDefense, Category=Shield)
	FGameplayAttributeData ShieldCriticalDefense;
	UFUNCTION()
	void OnRep_ShieldCriticalDefense(const FGameplayAttributeData& OldShieldCriticalDefense) const;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_FrontShieldHealth, Category=Shield)
	FGameplayAttributeData FrontShieldHealth;
	UFUNCTION()
	void OnRep_FrontShieldHealth(const FGameplayAttributeData& OldFrontShieldHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxFrontShieldHealth, Category=Shield)
	FGameplayAttributeData MaxFrontShieldHealth;
	UFUNCTION()
	void OnRep_MaxFrontShieldHealth(const FGameplayAttributeData& OldMaxFrontShieldHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BackShieldHealth, Category=Shield)
	FGameplayAttributeData BackShieldHealth;
	UFUNCTION()
	void OnRep_BackShieldHealth(const FGameplayAttributeData& OldBackShieldHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxBackShieldHealth, Category=Shield)
	FGameplayAttributeData MaxBackShieldHealth;
	UFUNCTION()
	void OnRep_MaxBackShieldHealth(const FGameplayAttributeData& OldMaxFrontBackHealth) const;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldPhysicalMitigation, Category=Shield)
	FGameplayAttributeData ShieldPhysicalMitigation;
	UFUNCTION()
	void OnRep_ShieldPhysicalMitigation(const FGameplayAttributeData& OldShieldPhysicalMitigation) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldEnergyMitigation, Category=Shield)
	FGameplayAttributeData ShieldEnergyMitigation;
	UFUNCTION()
	void OnRep_ShieldEnergyMitigation(const FGameplayAttributeData& OldShieldEnergyMitigation) const;

	//Power Attributes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ReactorLevel, Category=Power)
	FGameplayAttributeData ReactorLevel;
	UFUNCTION()
	void OnRep_ReactorLevel(const FGameplayAttributeData& OldReactorLevel) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Power)
	FGameplayAttributeData ReactorBoost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Power)
	FGameplayAttributeData ReactorHealthBoost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ReactorHealth, Category=Power)
	FGameplayAttributeData ReactorHealth;
	UFUNCTION()
	void OnRep_ReactorHealth(const FGameplayAttributeData& OldReactorHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxReactorHealth, Category=Power)
	FGameplayAttributeData MaxReactorHealth;
	UFUNCTION()
	void OnRep_MaxReactorHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BatteryLevel, Category=Power)
	FGameplayAttributeData BatteryLevel;
	UFUNCTION()
	void OnRep_BatteryLevel(const FGameplayAttributeData& OldBatteryLevel) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Power)
	FGameplayAttributeData BatteryBoost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Power)
	FGameplayAttributeData BatteryHealthBoost;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BatteryHealth, Category=Power)
	FGameplayAttributeData BatteryHealth;
	UFUNCTION()
	void OnRep_BatteryHealth(const FGameplayAttributeData& OldBatteryHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxBatteryHealth, Category=Power)
	FGameplayAttributeData MaxBatteryHealth;
	UFUNCTION()
	void OnRep_MaxBatteryHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_PowerGenerated, Category=Power)
	FGameplayAttributeData PowerGenerated;
	UFUNCTION()
	void OnRep_PowerGenerated(const FGameplayAttributeData& OldPowerGenerated) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BatteryPower, Category=Power)
	FGameplayAttributeData BatteryPower;
	UFUNCTION()
	void OnRep_BatteryPower(const FGameplayAttributeData& OldBatteryPower) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxBatteryPower, Category=Power)
	FGameplayAttributeData MaxBatteryPower;
	UFUNCTION()
	void OnRep_MaxBatteryPower(const FGameplayAttributeData& OldMaxBatteryPower) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponDistribution, Category=Power)
	FGameplayAttributeData WeaponDistribution;
	UFUNCTION()
	void OnRep_WeaponDistribution(const FGameplayAttributeData& OldWeaponDistribution) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponPower, Category=Power)
	FGameplayAttributeData WeaponPower;
	UFUNCTION()
	void OnRep_WeaponPower(const FGameplayAttributeData& OldWeaponPower) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EngineDistribution, Category=Power)
	FGameplayAttributeData EngineDistribution;
	UFUNCTION()
	void OnRep_EngineDistribution(const FGameplayAttributeData& OldEngineDistribution) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EnginePower, Category=Power)
	FGameplayAttributeData EnginePower;
	UFUNCTION()
	void OnRep_EnginePower(const FGameplayAttributeData& OldEnginePower) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldDistribution, Category=Power)
	FGameplayAttributeData ShieldDistribution;
	UFUNCTION()
	void OnRep_ShieldDistribution(const FGameplayAttributeData& OldShieldDistribution) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldPower, Category=Power)
	FGameplayAttributeData ShieldPower;
	UFUNCTION()
	void OnRep_ShieldPower(const FGameplayAttributeData& OldShieldPower) const;

	//Engine Attributes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EngineLEvel, Category=Engine)
	FGameplayAttributeData EngineLevel;
	UFUNCTION()
	void OnRep_EngineLevel(const FGameplayAttributeData& OldEngineLevel) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Engine)
	FGameplayAttributeData EngineBoost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Engine)
	FGameplayAttributeData EngineHealthBoost;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EngineHealth, Category=Engine)
	FGameplayAttributeData EngineHealth;
	UFUNCTION()
	void OnRep_EngineHealth(const FGameplayAttributeData& OldEngineHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxEngineHealth, Category=Engine)
	FGameplayAttributeData MaxEngineHealth;
	UFUNCTION()
	void OnRep_MaxEngineHealth(const FGameplayAttributeData& OldMaxEngineHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EngineOn, Category=Engine)
	FGameplayAttributeData EngineOn;
	UFUNCTION()
	void OnRep_EngineOn(const FGameplayAttributeData& OldEngineOn) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EngineThrust, Category=Engine)
	FGameplayAttributeData EngineThrust;
	UFUNCTION()
	void OnRep_EngineThrust(const FGameplayAttributeData& OldEngineThrust) const;
	//Incoming Damage & Healing Attributes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingHullPhysicalDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingHullEnergyDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingHullHealing;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingFrontPhysicalDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingFrontEnergyDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingBackPhysicalDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingBackEnergyDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingShieldDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingShieldHealing;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingEngineDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingEngineHealing;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingReactorDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingReactorHealing;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingBatteryDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData IncomingBatteryHealing;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
