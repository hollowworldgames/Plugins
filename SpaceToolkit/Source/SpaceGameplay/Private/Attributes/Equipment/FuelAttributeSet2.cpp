// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/Equipment/FuelAttributeSet2.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"



void UFuelAttributeSet2::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UFuelAttributeSet2, Fuel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFuelAttributeSet2, MaxFuel, COND_None, REPNOTIFY_Always);
}

void UFuelAttributeSet2::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	CAP_ATTRIBUTE(Fuel, MaxFuel, Data);
}

ATTRIBUTE_IMPLEMENT(UFuelAttributeSet2, Fuel);
ATTRIBUTE_IMPLEMENT(UFuelAttributeSet2, MaxFuel);