// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/SpaceCharacterShipAttributeSet.h"
#include "Net/UnrealNetwork.h"

void USpaceCharacterShipAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterShipAttributeSet, HullHealthBoost, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterShipAttributeSet, HullPhysicalMitigationBoost, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterShipAttributeSet, HullEnergyMitigationBoost, COND_None, REPNOTIFY_Always);
}

void USpaceCharacterShipAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(USpaceCharacterShipAttributeSet, HullHealthBoost);
ATTRIBUTE_IMPLEMENT(USpaceCharacterShipAttributeSet, HullPhysicalMitigationBoost);
ATTRIBUTE_IMPLEMENT(USpaceCharacterShipAttributeSet, HullEnergyMitigationBoost);