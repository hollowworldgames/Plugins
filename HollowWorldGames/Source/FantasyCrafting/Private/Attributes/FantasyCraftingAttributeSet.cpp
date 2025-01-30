// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/FantasyCraftingAttributeSet.h"
#include "GameplayEffectExtension.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(ProspectingExperienceTag, "Crafting.Attributes.ProspectingExperience", "");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ProspectingLevelTag, "Crafting.Attributes.ProspectingLevel", "");

float UFantasyCraftingAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	return Super::GetAttributeValue(AttributeTag);
}

void UFantasyCraftingAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UFantasyCraftingAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	return Super::GetAttributeTag(Attribute);
}

void UFantasyCraftingAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void UFantasyCraftingAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	PROCESS_INCOMING_EXPERIENCE(IncomingProspectingExperience, ProspectingExperience, ProspectingCurve, ProspectingLevel,OnProspectingLevel,Data);
}

ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, ProspectingExperience);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, ProspectingLevel);