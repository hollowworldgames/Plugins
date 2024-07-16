// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/SpaceCharacterShipAttributes.h"
#include "Net/UnrealNetwork.h"

void USpaceCharacterShipAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterShipAttributes, HullHealthBoost, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterShipAttributes, HullPhysicalMitigationBoost, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCharacterShipAttributes, HullEnergyMitigationBoost, COND_None, REPNOTIFY_Always);
}

void USpaceCharacterShipAttributes::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(USpaceCharacterShipAttributes, HullHealthBoost);
ATTRIBUTE_IMPLEMENT(USpaceCharacterShipAttributes, HullPhysicalMitigationBoost);
ATTRIBUTE_IMPLEMENT(USpaceCharacterShipAttributes, HullEnergyMitigationBoost);