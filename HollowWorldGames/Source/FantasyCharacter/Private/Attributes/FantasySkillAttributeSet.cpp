// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/FantasySkillAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(OneHandedTag, "Combat.Skill.OneHanded", "One Handed Skill");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(OneHandedExperienceTag, "Combat.Skill.OneHanded.Experience", "One Handed Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(TwoHandedTag, "Combat.Skill.TwoHanded", "Two Handed Skill");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(TwoHandedExperienceTag, "Combat.Skill.TwoHanded.Experience", "Two Handed Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldTag, "Combat.Skill.Shield", "Shield Skill");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldExperienceTag, "Combat.Skill.Shield.Experience", "Shield Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ArcheryTag, "Combat.Skill.Archery", "Archery Skill");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ArcheryExperienceTag, "Combat.Skill.Archery.Experience", "Shield Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ArmorUseTag, "Combat.Skill.ArmorUse", "Armor Use Skill");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ArmorUseExperienceTag, "Combat.Skill.ArmorUse.Experience", "Armor Use Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(DestructionTag, "Magic.Skill.Destruction", "Destruction Skill");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(DestructionExperienceTag, "Magic.Skill.Destruction.Experience", "Destruction Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(RestorationTag, "Magic.Skill.Restoration", "Restoration Skill");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(RestorationExperienceTag, "Magic.Skill.Restoration.Experience", "Restoration Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(AlterationTag, "Magic.Skill.Alteration", "Alteration Skill");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(AlterationExperienceTag, "Magic.Skill.Alteration.Experience", "Alteration Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ConjurationTag, "Magic.Skill.Conjuration", "Conjuration Skill");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ConjurationExperienceTag, "Magic.Skill.Conjuration.Experience", "Conjuration Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IllusionTag, "Magic.Skill.Illusion", "Illusion Skill");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IllusionExperienceTag, "Magic.Skill.Illusion.Experience", "Illusion Experience");

float UFantasySkillAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(OneHanded, AttributeTag);
	GET_IF_TAGMATCHES(OneHandedExperience, AttributeTag);
	GET_IF_TAGMATCHES(TwoHanded, AttributeTag);
	GET_IF_TAGMATCHES(TwoHandedExperience, AttributeTag);
	GET_IF_TAGMATCHES(Shield, AttributeTag);
	GET_IF_TAGMATCHES(ShieldExperience, AttributeTag);
	GET_IF_TAGMATCHES(ArmorUse, AttributeTag);
	GET_IF_TAGMATCHES(ArmorUseExperience, AttributeTag);
	GET_IF_TAGMATCHES(Archery, AttributeTag);
	GET_IF_TAGMATCHES(ArcheryExperience, AttributeTag);
	GET_IF_TAGMATCHES(Destruction, AttributeTag);
	GET_IF_TAGMATCHES(Restoration, AttributeTag);
	GET_IF_TAGMATCHES(Alteration, AttributeTag);
	GET_IF_TAGMATCHES(Conjuration, AttributeTag);
	GET_IF_TAGMATCHES(Illusion, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UFantasySkillAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(OneHanded, Attribute, Value);
	SET_IF_TAGMATCHES(OneHandedExperience, Attribute, Value);
	SET_IF_TAGMATCHES(TwoHanded, Attribute, Value);
	SET_IF_TAGMATCHES(TwoHandedExperience, Attribute, Value);
	SET_IF_TAGMATCHES(Shield, Attribute, Value);
	SET_IF_TAGMATCHES(ShieldExperience, Attribute, Value);
	SET_IF_TAGMATCHES(ArmorUse, Attribute, Value);
	SET_IF_TAGMATCHES(ArmorUseExperience, Attribute, Value);
	SET_IF_TAGMATCHES(Archery, Attribute, Value);
	SET_IF_TAGMATCHES(ArcheryExperience, Attribute, Value);
	SET_IF_TAGMATCHES(Destruction, Attribute, Value);
	SET_IF_TAGMATCHES(Restoration, Attribute, Value);
	SET_IF_TAGMATCHES(Alteration, Attribute, Value);
	SET_IF_TAGMATCHES(Conjuration, Attribute, Value);
	SET_IF_TAGMATCHES(Illusion, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UFantasySkillAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(OneHanded, Attribute);
	CHECK_IF_ATTRIBUTE(OneHandedExperience, Attribute);
	CHECK_IF_ATTRIBUTE(TwoHanded, Attribute);
	CHECK_IF_ATTRIBUTE(TwoHandedExperience, Attribute);
	CHECK_IF_ATTRIBUTE(Shield, Attribute);
	CHECK_IF_ATTRIBUTE(ShieldExperience, Attribute);
	CHECK_IF_ATTRIBUTE(ArmorUse, Attribute);
	CHECK_IF_ATTRIBUTE(ArmorUseExperience, Attribute);
	CHECK_IF_ATTRIBUTE(Archery, Attribute);
	CHECK_IF_ATTRIBUTE(ArcheryExperience, Attribute);
	CHECK_IF_ATTRIBUTE(Destruction, Attribute);
	CHECK_IF_ATTRIBUTE(Restoration, Attribute);
	CHECK_IF_ATTRIBUTE(Alteration, Attribute);
	CHECK_IF_ATTRIBUTE(Conjuration, Attribute);
	CHECK_IF_ATTRIBUTE(Illusion, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UFantasySkillAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, OneHanded, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, OneHandedExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, TwoHanded, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, TwoHandedExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, Shield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, ShieldExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, ArmorUse, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, ArmorUseExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, Archery, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, ArcheryExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, Destruction, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, Restoration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, Alteration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, Conjuration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, Illusion, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, DestructionExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, RestorationExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, AlterationExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, ConjurationExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasySkillAttributeSet, IllusionExperience, COND_None, REPNOTIFY_Always);
}

void UFantasySkillAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	PROCESS_INCOMING_EXPERIENCE(IncomingOneHandedExperience, OneHandedExperience, OneHandedCurve, OneHanded, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingTwoHandedExperience, TwoHandedExperience, TwoHandedCurve, TwoHanded, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingShieldExperience, ShieldExperience, ShieldCurve, Shield, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingArmorUseExperience, ArmorUseExperience, ArmorUseCurve , ArmorUse, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingArcheryExperience, ArcheryExperience, ArcheryCurve , Archery, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(DestructionExperience, DestructionExperience, DestructionCurve, Destruction, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(RestorationExperience, RestorationExperience, RestorationCurve, Restoration, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(AlterationExperience, AlterationExperience, AlterationCurve, Alteration, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(ConjurationExperience, ConjurationExperience, ConjurationCurve, Conjuration, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(IllusionExperience, IllusionExperience, IllusionCurve, Illusion, OnLevelChanged, Data);
}

ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, OneHanded);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, OneHandedExperience);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, TwoHanded);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, TwoHandedExperience);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, Shield);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, ShieldExperience);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, ArmorUse);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, ArmorUseExperience);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, Archery);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, ArcheryExperience);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, Destruction);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, DestructionExperience);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, Restoration);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, RestorationExperience);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, Alteration);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, AlterationExperience);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, Conjuration);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, ConjurationExperience);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, Illusion);
ATTRIBUTE_IMPLEMENT(UFantasySkillAttributeSet, IllusionExperience);