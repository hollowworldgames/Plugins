// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.


#include "Attributes/ReactorPowerAttributeSet.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(ReactorFuelAvailableTag, "Reactor.Attributes.FuelAvailable","Reactor Fuel Available")

float UReactorPowerAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	return Super::GetAttributeValue(AttributeTag);
}

void UReactorPowerAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UReactorPowerAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	return Super::GetAttributeTag(Attribute);
}

void UReactorPowerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void UReactorPowerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UReactorPowerAttributeSet, ReactorFuelAvailable);