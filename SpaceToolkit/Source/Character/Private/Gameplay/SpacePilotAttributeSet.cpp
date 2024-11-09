// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Gameplay/SpacePilotAttributeSet.h"

#include "Net/UnrealNetwork.h"

void USpacePilotAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(USpacePilotAttributeSet, GForceTolerance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpacePilotAttributeSet, GForceEndurance, COND_None, REPNOTIFY_Always);
}

void USpacePilotAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(USpacePilotAttributeSet, GForceTolerance);
ATTRIBUTE_IMPLEMENT(USpacePilotAttributeSet, GForceEndurance);