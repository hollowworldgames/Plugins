// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/SciFiSkillsAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

float USciFiSkillsAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(ArmorUse, AttributeTag)
	GET_IF_TAGMATCHES(ArmorUseExperience, AttributeTag)
	GET_IF_TAGMATCHES(Pistols, AttributeTag)
	GET_IF_TAGMATCHES(PistolsExperience, AttributeTag)
	GET_IF_TAGMATCHES(Rifles, AttributeTag)
	GET_IF_TAGMATCHES(RiflesExperience, AttributeTag)
	GET_IF_TAGMATCHES(PersonalShields, AttributeTag)
	GET_IF_TAGMATCHES(PersonalShieldsExperience, AttributeTag)
	return Super::GetAttributeValue(AttributeTag);
}

void USciFiSkillsAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(ArmorUse, Attribute, Value)
	SET_IF_TAGMATCHES(ArmorUseExperience, Attribute, Value)
	SET_IF_TAGMATCHES(Pistols, Attribute, Value)
	SET_IF_TAGMATCHES(PistolsExperience, Attribute, Value)
	SET_IF_TAGMATCHES(Rifles, Attribute, Value)
	SET_IF_TAGMATCHES(RiflesExperience, Attribute, Value)
	SET_IF_TAGMATCHES(PersonalShields, Attribute, Value)
	SET_IF_TAGMATCHES(PersonalShieldsExperience, Attribute, Value)
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag USciFiSkillsAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(ArmorUse, Attribute)
	CHECK_IF_ATTRIBUTE(ArmorUseExperience, Attribute)
	CHECK_IF_ATTRIBUTE(Pistols, Attribute)
	CHECK_IF_ATTRIBUTE(PistolsExperience, Attribute)
	CHECK_IF_ATTRIBUTE(Rifles, Attribute)
	CHECK_IF_ATTRIBUTE(RiflesExperience, Attribute)
	CHECK_IF_ATTRIBUTE(PersonalShields, Attribute)
	CHECK_IF_ATTRIBUTE(PersonalShieldsExperience, Attribute)
	return Super::GetAttributeTag(Attribute);
}

void USciFiSkillsAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(USciFiSkillsAttributeSet, ArmorUse, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USciFiSkillsAttributeSet, ArmorUseExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USciFiSkillsAttributeSet, Pistols, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USciFiSkillsAttributeSet, PistolsExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USciFiSkillsAttributeSet, Rifles, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USciFiSkillsAttributeSet, RiflesExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USciFiSkillsAttributeSet, PersonalShields, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USciFiSkillsAttributeSet, PersonalShieldsExperience, COND_None, REPNOTIFY_Always);
}

void USciFiSkillsAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingArmorUseExperience, ArmorUseExperience,  ArmorUseCurve, ArmorUse, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingPistolsExperience, PistolsExperience,  PistolsCurve, Pistols, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingRiflesExperience, RiflesExperience,  RiflesCurve, Rifles, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingPersonalShieldsExperience, PersonalShieldsExperience, PersonalShieldsCurve, PersonalShields, OnLevelChanged, Data);
}

ATTRIBUTE_IMPLEMENT(USciFiSkillsAttributeSet, ArmorUse);
ATTRIBUTE_IMPLEMENT(USciFiSkillsAttributeSet, ArmorUseExperience);
ATTRIBUTE_IMPLEMENT(USciFiSkillsAttributeSet, Pistols);
ATTRIBUTE_IMPLEMENT(USciFiSkillsAttributeSet, PistolsExperience);
ATTRIBUTE_IMPLEMENT(USciFiSkillsAttributeSet, Rifles);
ATTRIBUTE_IMPLEMENT(USciFiSkillsAttributeSet, RiflesExperience);
ATTRIBUTE_IMPLEMENT(USciFiSkillsAttributeSet, PersonalShields);
ATTRIBUTE_IMPLEMENT(USciFiSkillsAttributeSet, PersonalShieldsExperience);