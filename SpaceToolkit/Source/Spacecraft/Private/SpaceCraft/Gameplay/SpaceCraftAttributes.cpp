// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCraft/Gameplay/SpaceCraftAttributes.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void USpaceCraftAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, HullHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, MaxHullHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, ShieldOn, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, ShieldLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, ShieldHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, MaxShieldHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, FrontShieldHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, MaxFrontShieldHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, BackShieldHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, MaxBackShieldHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, HullPhysicalMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, HullEnergyMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, ShieldPhysicalMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, ShieldEnergyMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, ReactorLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, ReactorHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, MaxReactorHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, BatteryLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, BatteryHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, MaxBatteryHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, PowerGenerated, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, BatteryPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, MaxBatteryPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, WeaponPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, WeaponDistribution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, EnginePower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, EngineDistribution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, ShieldPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, ShieldDistribution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, EngineOn, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, EngineLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, EngineBoost, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, EngineHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, MaxEngineHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCraftAttributes, EngineThrust, COND_None, REPNOTIFY_Always);
}

void USpaceCraftAttributes::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	CAP_ATTRIBUTE(HullHealth, MaxHullHealth, Data);
	CAP_ATTRIBUTE(FrontShieldHealth, MaxFrontShieldHealth, Data);
	CAP_ATTRIBUTE(BackShieldHealth, MaxBackShieldHealth, Data);
	CAP_ATTRIBUTE(BatteryPower, MaxBatteryPower, Data);
	CAP_ATTRIBUTE(ReactorHealth, MaxReactorHealth, Data);
	CAP_ATTRIBUTE(BatteryHealth, MaxBatteryHealth, Data);
	CAP_ATTRIBUTE(ShieldHealth, MaxShieldHealth, Data);
	CAP_ATTRIBUTE(EngineHealth, MaxEngineHealth, Data);

	PROCESS_INCOMING_DAMAGE(IncomingHullEnergyDamage, HullHealth, Data)
	PROCESS_INCOMING_DAMAGE(IncomingHullPhysicalDamage, HullHealth, Data)
	PROCESS_INCOMING_DAMAGE(IncomingFrontEnergyDamage, FrontShieldHealth, Data)
	PROCESS_INCOMING_DAMAGE(IncomingFrontPhysicalDamage, FrontShieldHealth, Data)
	PROCESS_INCOMING_DAMAGE(IncomingBackEnergyDamage, BackShieldHealth, Data)
	PROCESS_INCOMING_DAMAGE(IncomingBackPhysicalDamage, BackShieldHealth, Data)
	PROCESS_INCOMING_DAMAGE(IncomingBatteryDamage, BatteryHealth, Data);
	PROCESS_INCOMING_DAMAGE(IncomingReactorDamage, ReactorHealth, Data);
	PROCESS_INCOMING_DAMAGE(IncomingShieldDamage, ShieldHealth, Data);
	PROCESS_INCOMING_DAMAGE(IncomingEngineDamage, EngineHealth, Data);
}

ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, HullHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, MaxHullHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, HullPhysicalMitigation);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, HullEnergyMitigation);

ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, ShieldOn);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, ShieldLevel);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, ShieldHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, MaxShieldHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, FrontShieldHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, MaxFrontShieldHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, BackShieldHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, MaxBackShieldHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, ShieldPhysicalMitigation);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, ShieldEnergyMitigation);

ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, ReactorLevel);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, ReactorHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, MaxReactorHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, PowerGenerated);

ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, BatteryLevel);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, BatteryHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, MaxBatteryHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, BatteryPower);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, MaxBatteryPower);

ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, WeaponDistribution);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, EngineDistribution);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, ShieldDistribution);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, WeaponPower);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, EnginePower);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, ShieldPower);

ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, EngineOn);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, EngineLevel);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, EngineHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, MaxEngineHealth);
ATTRIBUTE_IMPLEMENT(USpaceCraftAttributes, EngineThrust);