// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/FantasyCraftingAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(ProspectingExperienceTag, "Crafting.Prospecting.Experience", "Prospecting Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ProspectingLevelTag, "Crafting.Prospecting.Level", "Prospecting Level");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ForestryExperienceTag, "Crafting.Forestry.Experience", "Forestry Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ForestryLevelTag, "Crafting.Forestry.Level", "Forestry Level");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FarmingExperienceTag, "Crafting.Farming.Experience", "Farming Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FarmingLevelTag, "Crafting.Farming.Level", "Farming Level");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(JewelerExperienceTag, "Crafting.Jeweler.Experience", "Jeweler Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(JewelerLevelTag, "Crafting.Jeweler.Level", "Jeweler Level");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(HerbalistExperienceTag, "Crafting.Herbalist.Experience", "Herbalist Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(HerbalistLevelTag, "Crafting.Herbalist.Level", "Herbalist Level");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(CookExperienceTag, "Crafting.Cook.Experience", "Cook Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(CookLevelTag, "Crafting.Cook.Level", "Cook Level");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(BlacksmithExperienceTag, "Crafting.Blacksmith.Experience", "Blacksmith Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(BlacksmithLevelTag, "Crafting.Blacksmith.Level", "Blacksmith Level");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WoodWorkerExperienceTag, "Crafting.WoodWorker.Experience", "WoodWorker Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WoodWorkerLevelTag, "Crafting.WoodWorker.Level", "WoodWorker Level");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(LoreMasterExperienceTag, "Crafting.LoreMaster.Experience", "LoreMaster Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(LoreMasterLevelTag, "Crafting.LoreMaster.Level", "LoreMaster Level");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(TailorExperienceTag, "Crafting.Tailor.Experience", "Tailor Experience");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(TailorLevelTag, "Crafting.Tailor.Level", "Tailor Level");

float UFantasyCraftingAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(ProspectingLevel, AttributeTag);
	GET_IF_TAGMATCHES(ProspectingExperience, AttributeTag);
	GET_IF_TAGMATCHES(ForestryExperience, AttributeTag);
	GET_IF_TAGMATCHES(ForestryLevel, AttributeTag);
	GET_IF_TAGMATCHES(FarmingExperience, AttributeTag);
	GET_IF_TAGMATCHES(FarmingLevel, AttributeTag);
	GET_IF_TAGMATCHES(JewelerExperience, AttributeTag);
	GET_IF_TAGMATCHES(JewelerLevel, AttributeTag);
	GET_IF_TAGMATCHES(HerbalistExperience, AttributeTag);
	GET_IF_TAGMATCHES(HerbalistLevel, AttributeTag);
	GET_IF_TAGMATCHES(CookExperience, AttributeTag);
	GET_IF_TAGMATCHES(CookLevel, AttributeTag);
	GET_IF_TAGMATCHES(BlacksmithExperience, AttributeTag);
	GET_IF_TAGMATCHES(BlacksmithLevel, AttributeTag);
	GET_IF_TAGMATCHES(WoodWorkerExperience, AttributeTag);
	GET_IF_TAGMATCHES(WoodWorkerLevel, AttributeTag);
	GET_IF_TAGMATCHES(LoreMasterExperience, AttributeTag);
	GET_IF_TAGMATCHES(LoreMasterLevel, AttributeTag);
	GET_IF_TAGMATCHES(TailorExperience, AttributeTag);
	GET_IF_TAGMATCHES(TailorLevel, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UFantasyCraftingAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(ProspectingExperience, Attribute, Value);
	SET_IF_TAGMATCHES(ProspectingLevel, Attribute, Value);
	SET_IF_TAGMATCHES(ForestryExperience, Attribute, Value);
	SET_IF_TAGMATCHES(ForestryLevel, Attribute, Value);
	SET_IF_TAGMATCHES(FarmingExperience, Attribute, Value);
	SET_IF_TAGMATCHES(FarmingLevel, Attribute, Value);
	SET_IF_TAGMATCHES(JewelerExperience, Attribute, Value);
	SET_IF_TAGMATCHES(JewelerLevel, Attribute, Value);
	SET_IF_TAGMATCHES(HerbalistExperience, Attribute, Value);
	SET_IF_TAGMATCHES(HerbalistLevel, Attribute, Value);
	SET_IF_TAGMATCHES(CookExperience, Attribute, Value);
	SET_IF_TAGMATCHES(CookLevel, Attribute, Value);
	SET_IF_TAGMATCHES(BlacksmithExperience, Attribute, Value);
	SET_IF_TAGMATCHES(BlacksmithLevel, Attribute, Value);
	SET_IF_TAGMATCHES(WoodWorkerExperience, Attribute, Value);
	SET_IF_TAGMATCHES(WoodWorkerLevel, Attribute, Value);
	SET_IF_TAGMATCHES(LoreMasterExperience, Attribute, Value);
	SET_IF_TAGMATCHES(LoreMasterLevel, Attribute, Value);
	SET_IF_TAGMATCHES(TailorExperience, Attribute, Value);
	SET_IF_TAGMATCHES(TailorLevel, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UFantasyCraftingAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(ProspectingExperience, Attribute);
	CHECK_IF_ATTRIBUTE(ProspectingLevel, Attribute);
	CHECK_IF_ATTRIBUTE(ForestryExperience, Attribute);
	CHECK_IF_ATTRIBUTE(ForestryLevel, Attribute);
	CHECK_IF_ATTRIBUTE(FarmingExperience, Attribute);
	CHECK_IF_ATTRIBUTE(FarmingLevel, Attribute);
	CHECK_IF_ATTRIBUTE(JewelerExperience, Attribute);
	CHECK_IF_ATTRIBUTE(JewelerLevel, Attribute);
	CHECK_IF_ATTRIBUTE(HerbalistExperience, Attribute);
	CHECK_IF_ATTRIBUTE(HerbalistLevel, Attribute);
	CHECK_IF_ATTRIBUTE(CookExperience, Attribute);
    CHECK_IF_ATTRIBUTE(CookLevel, Attribute);
	CHECK_IF_ATTRIBUTE(BlacksmithExperience, Attribute);
	CHECK_IF_ATTRIBUTE(BlacksmithLevel, Attribute);
	CHECK_IF_ATTRIBUTE(WoodWorkerExperience, Attribute);
	CHECK_IF_ATTRIBUTE(WoodWorkerLevel, Attribute);
	CHECK_IF_ATTRIBUTE(LoreMasterExperience, Attribute);
	CHECK_IF_ATTRIBUTE(LoreMasterLevel, Attribute);
	CHECK_IF_ATTRIBUTE(TailorExperience, Attribute);
	CHECK_IF_ATTRIBUTE(TailorLevel, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UFantasyCraftingAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, ProspectingExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, ProspectingLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, ForestryExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, ForestryLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, FarmingExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, FarmingLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, JewelerExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, JewelerLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, HerbalistExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, HerbalistLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, CookExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, CookLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, BlacksmithExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, BlacksmithLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, WoodWorkerExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, WoodWorkerLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, LoreMasterExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, LoreMasterLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, TailorExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCraftingAttributeSet, TailorLevel, COND_None, REPNOTIFY_Always);
}

void UFantasyCraftingAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	PROCESS_INCOMING_EXPERIENCE(IncomingProspectingExperience, ProspectingExperience, ProspectingCurve, ProspectingLevel,OnLevelChanged,Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingForestryExperience, ForestryExperience, ForestryCurve, ForestryLevel,OnLevelChanged,Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingFarmingExperience, FarmingExperience, FarmingCurve, FarmingLevel, OnLevelChanged, Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingJewelerExperience, JewelerExperience, JewelerCurve, JewelerLevel,OnLevelChanged,Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingHerbalistExperience, HerbalistExperience, HerbalistCurve, HerbalistLevel,OnLevelChanged,Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingCookExperience, CookExperience, CookCurve, CookLevel,OnLevelChanged,Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingBlacksmithExperience, BlacksmithExperience, BlacksmithCurve, BlacksmithLevel,OnLevelChanged,Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingWoodWorkerExperience, WoodWorkerExperience, WoodWorkerCurve, WoodWorkerLevel,OnLevelChanged,Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingLoreMasterExperience, LoreMasterExperience, LoreMasterCurve, LoreMasterLevel,OnLevelChanged,Data);
	PROCESS_INCOMING_EXPERIENCE(IncomingTailorExperience, TailorExperience, TailorCurve, TailorLevel,OnLevelChanged,Data);
}

ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, ProspectingExperience);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, ProspectingLevel);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, ForestryExperience);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, ForestryLevel);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, FarmingExperience);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, FarmingLevel);

ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, JewelerExperience);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, JewelerLevel);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, HerbalistExperience);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, HerbalistLevel);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, CookExperience);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, CookLevel);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, BlacksmithExperience);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, BlacksmithLevel);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, WoodWorkerExperience);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, WoodWorkerLevel);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, LoreMasterExperience);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, LoreMasterLevel);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, TailorExperience);
ATTRIBUTE_IMPLEMENT(UFantasyCraftingAttributeSet, TailorLevel);