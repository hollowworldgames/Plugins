// Copyright (c) 2024 Hollow World Games llc All Rights Reserved


#include "Attributes/PowerAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(PowerGenerationTag, "Vehicle.Attribute.Power.Generated", "Power Generated")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PowerMaxGenerationTag, "Vehicle.Attribute.Power.MaxGenerated", "Power Max Generated")

float UPowerAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	return Super::GetAttributeValue(AttributeTag);
}

void UPowerAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UPowerAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	return Super::GetAttributeTag(Attribute);
}

void UPowerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet, PowerGenerated, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPowerAttributeSet, PowerMaxGenerated, COND_None, REPNOTIFY_Always);
}

void UPowerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	CAP_ATTRIBUTE(PowerGenerated, PowerMaxGenerated, Data);
}

ATTRIBUTE_IMPLEMENT(UPowerAttributeSet, PowerGenerated);
ATTRIBUTE_IMPLEMENT(UPowerAttributeSet, PowerMaxGenerated);
