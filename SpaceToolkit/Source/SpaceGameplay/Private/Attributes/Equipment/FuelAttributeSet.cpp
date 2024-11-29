// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/Equipment/FuelAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(FuelTag, "Fuel.Attributes.Fuel", "Fuel");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxFuelTag,"Fuel.Attributes.MaxFuel","MaxFuel");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FuelOnTag,"Fuel.State.On","Fuel On");

void UFuelAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UFuelAttributeSet, Fuel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFuelAttributeSet, MaxFuel, COND_None, REPNOTIFY_Always);
}

void UFuelAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	CAP_ATTRIBUTE(Fuel, MaxFuel, Data);
}

ATTRIBUTE_IMPLEMENT(UFuelAttributeSet, Fuel);
ATTRIBUTE_IMPLEMENT(UFuelAttributeSet, MaxFuel);