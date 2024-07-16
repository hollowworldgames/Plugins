// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/SpaceCharacterAttributes.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void USpaceCharacterAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, HealthMax, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, Energy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, EnergyMax, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, Agility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, Precision, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, Luck, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, Constitution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, Endurance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, GlancingBlowChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, ParryChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterAttributes, EvadeChance, COND_None, REPNOTIFY_Always);
}

void USpaceCharacterAttributes::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	CAP_ATTRIBUTE(Health, HealthMax, Data);
	CAP_ATTRIBUTE(Energy, EnergyMax, Data);

	ProcessIncomingDamage(IncomingPhysicalDamage, Health, Data);
	ProcessIncomingDamage(IncomingEnergyDamage, Health, Data);
	ProcessIncomingHealing(IncomingHealing, Health, Data);
}

ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, Health);
ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, HealthMax);
ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, Energy);
ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, EnergyMax);

ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, GlancingBlowChance);
ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, ParryChance);
ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, EvadeChance);

ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, Strength);
ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, Agility);
ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, Precision);
ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, Luck);
ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, Constitution);
ATTRIBUTE_IMPLEMENT(USpaceCharacterAttributes, Endurance);
