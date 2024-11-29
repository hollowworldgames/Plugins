// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/CombatAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitChanceTag, "Combat.Attributes.HitChance", "Hit Chance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EvadeChanceTag,"Combat.Attributes.EvadeChance","Evade Chance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GlanceChanceTag,"Combat.Attributes.GlanceChance","Glance Chance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GlanceValueTag,"Combat.Attributes.GlanceValue","Glance Value");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(KineticMitigationTag,"Combat.Attributes.KineticMitigation","Kinetic Mitigation");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EnergyMitigationTag,"Combat.Attributes.EnergyMitigation","Energy Mitigation");

UE_DEFINE_GAMEPLAY_TAG_COMMENT(CriticalChanceTag,"Combat.Attributes.CriticalChance","Critical Chance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(CriticalDamageTag,"Combat.Attributes.CriticalDamage","Critical Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(CriticalDefenseTag,"Combat.Attributes.CriticalDefense","Critical Defense");

UE_DEFINE_GAMEPLAY_TAG_COMMENT(FrontShieldTag,"Combat.Attributes.FrontShield","Front Shield");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxFrontShieldTag,"Combat.Attributes.MaxFrontShield","Max Front Shield");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FrontKineticMitigationTag,"Combat.Attributes.FrontKineticMitigation","Front Kinetic Mitigation");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FrontEnergyMitigationTag,"Combat.Attributes.FrontEnergyMitigation","Front Energy Mitigation");

UE_DEFINE_GAMEPLAY_TAG_COMMENT(BackShieldTag,"Combat.Attributes.BackShield","Back Shield");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxBackShieldTag,"Combat.Attributes.MaxBackShield","Max Back Shield");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(BackKineticMitigationTag,"Combat.Attributes.BackKineticMitigation","Back Kinetic Mitigation");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(BackEnergyMitigationTag,"Combat.Attributes.BackEnergyMitigation","Back Energy Mitigation");

UE_DEFINE_GAMEPLAY_TAG_COMMENT(RightShieldTag,"Combat.Attributes.RightShield","Right Shield");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxRightShieldTag,"Combat.Attributes.MaxRightShield","Max Right Shield");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(RightKineticMitigationTag,"Combat.Attributes.RightKineticMitigation","Right Kinetic Mitigation");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(RightEnergyMitigationTag,"Combat.Attributes.RightEnergyMitigation","Right Energy Mitigation");

UE_DEFINE_GAMEPLAY_TAG_COMMENT(LeftShieldTag,"Combat.Attributes.LeftShield","Left Shield");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxLeftShieldTag,"Combat.Attributes.MaxLeftShield","Max Left Shield");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(LeftKineticMitigationTag,"Combat.Attributes.LeftKineticMitigation","Left Kinetic Mitigation");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(LeftEnergyMitigationTag,"Combat.Attributes.LeftEnergyMitigation","Left Energy Mitigation");

UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingFrontKineticDamageTag,"Combat.Attributes.IncomingFrontKineticDamage","Incoming Front Kinetic Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingFrontEnergyDamageTag,"Combat.Attributes.IncomingFrontEnergyDamage","Incoming Front Energy Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingBackKineticDamageTag,"Combat.Attributes.IncomingBackKineticDamage","Incoming Back Kinetic Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingBackEnergyDamageTag,"Combat.Attributes.IncomingBackEnergyDamage","Incoming Back Energy Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingRightKineticDamageTag,"Combat.Attributes.IncomingRightKineticDamage","Incoming Right Kinetic Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingRightEnergyDamageTag,"Combat.Attributes.IncomingRightEnergyDamage","Incoming Right Energy Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingLeftKineticDamageTag,"Combat.Attributes.IncomingLeftKineticDamage","Incoming Left Kinetic Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingLeftEnergyDamageTag,"Combat.Attributes.IncomingLeftEnergyDamage","Incoming Left Energy Damage");

float UCombatAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(HitChance, AttributeTag);
	GET_IF_TAGMATCHES(EvadeChance, AttributeTag);
	GET_IF_TAGMATCHES(GlanceChance, AttributeTag);
	GET_IF_TAGMATCHES(GlanceValue, AttributeTag);
	GET_IF_TAGMATCHES(EnergyMitigation, AttributeTag);
	GET_IF_TAGMATCHES(KineticMitigation, AttributeTag);
	
	GET_IF_TAGMATCHES(CriticalChance, AttributeTag);
	GET_IF_TAGMATCHES(CriticalDamage, AttributeTag);
	GET_IF_TAGMATCHES(CriticalDefense, AttributeTag);
	
	GET_IF_TAGMATCHES(FrontShield, AttributeTag);
	GET_IF_TAGMATCHES(MaxFrontShield, AttributeTag);
	GET_IF_TAGMATCHES(FrontKineticMitigation, AttributeTag);
	GET_IF_TAGMATCHES(FrontEnergyMitigation, AttributeTag);

	GET_IF_TAGMATCHES(BackShield, AttributeTag);
	GET_IF_TAGMATCHES(MaxBackShield, AttributeTag);
	GET_IF_TAGMATCHES(BackKineticMitigation, AttributeTag);
	GET_IF_TAGMATCHES(BackEnergyMitigation, AttributeTag);

	GET_IF_TAGMATCHES(RightShield, AttributeTag);
	GET_IF_TAGMATCHES(MaxRightShield, AttributeTag);
	GET_IF_TAGMATCHES(RightKineticMitigation, AttributeTag);
	GET_IF_TAGMATCHES(RightEnergyMitigation, AttributeTag);

	GET_IF_TAGMATCHES(LeftShield, AttributeTag);
	GET_IF_TAGMATCHES(MaxLeftShield, AttributeTag);
	GET_IF_TAGMATCHES(LeftKineticMitigation, AttributeTag);
	GET_IF_TAGMATCHES(LeftEnergyMitigation, AttributeTag);

	GET_IF_TAGMATCHES(IncomingFrontEnergyDamage, AttributeTag);
	GET_IF_TAGMATCHES(IncomingFrontKineticDamage, AttributeTag);
	GET_IF_TAGMATCHES(IncomingBackEnergyDamage, AttributeTag);
	GET_IF_TAGMATCHES(IncomingBackKineticDamage, AttributeTag);
	GET_IF_TAGMATCHES(IncomingRightEnergyDamage, AttributeTag);
	GET_IF_TAGMATCHES(IncomingRightKineticDamage, AttributeTag);
	GET_IF_TAGMATCHES(IncomingLeftEnergyDamage, AttributeTag);
	GET_IF_TAGMATCHES(IncomingLeftKineticDamage, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UCombatAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(HitChance, Attribute, Value);
	SET_IF_TAGMATCHES(EvadeChance, Attribute, Value);
	SET_IF_TAGMATCHES(GlanceChance, Attribute, Value);
	SET_IF_TAGMATCHES(GlanceValue, Attribute, Value);
	SET_IF_TAGMATCHES(EnergyMitigation, Attribute, Value);
	SET_IF_TAGMATCHES(KineticMitigation, Attribute, Value);

	SET_IF_TAGMATCHES(CriticalChance, Attribute, Value);
	SET_IF_TAGMATCHES(CriticalDamage, Attribute, Value);
	SET_IF_TAGMATCHES(CriticalDefense, Attribute, Value);

	SET_IF_TAGMATCHES(FrontShield, Attribute, Value);
	SET_IF_TAGMATCHES(MaxFrontShield, Attribute, Value);
	SET_IF_TAGMATCHES(FrontKineticMitigation, Attribute, Value);
	SET_IF_TAGMATCHES(FrontEnergyMitigation, Attribute, Value);

	SET_IF_TAGMATCHES(BackShield, Attribute, Value);
	SET_IF_TAGMATCHES(MaxBackShield, Attribute, Value);
	SET_IF_TAGMATCHES(BackKineticMitigation, Attribute, Value);
	SET_IF_TAGMATCHES(BackEnergyMitigation, Attribute, Value);

	SET_IF_TAGMATCHES(RightShield, Attribute, Value);
	SET_IF_TAGMATCHES(MaxRightShield, Attribute, Value);
	SET_IF_TAGMATCHES(RightKineticMitigation, Attribute, Value);
	SET_IF_TAGMATCHES(RightEnergyMitigation, Attribute, Value);

	SET_IF_TAGMATCHES(LeftShield, Attribute, Value);
	SET_IF_TAGMATCHES(MaxLeftShield, Attribute, Value);
	SET_IF_TAGMATCHES(LeftKineticMitigation, Attribute, Value);
	SET_IF_TAGMATCHES(LeftEnergyMitigation, Attribute, Value);

	SET_IF_TAGMATCHES(IncomingFrontEnergyDamage, Attribute, Value);
	SET_IF_TAGMATCHES(IncomingFrontKineticDamage, Attribute, Value);
	SET_IF_TAGMATCHES(IncomingBackEnergyDamage, Attribute, Value);
	SET_IF_TAGMATCHES(IncomingBackKineticDamage, Attribute, Value);
	SET_IF_TAGMATCHES(IncomingRightEnergyDamage, Attribute, Value);
	SET_IF_TAGMATCHES(IncomingRightKineticDamage, Attribute, Value);
	SET_IF_TAGMATCHES(IncomingLeftEnergyDamage, Attribute, Value);
	SET_IF_TAGMATCHES(IncomingLeftKineticDamage, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UCombatAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(HitChance, Attribute);
	CHECK_IF_ATTRIBUTE(EvadeChance, Attribute);
	CHECK_IF_ATTRIBUTE(GlanceChance, Attribute);
	CHECK_IF_ATTRIBUTE(GlanceValue, Attribute);
	CHECK_IF_ATTRIBUTE(EnergyMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(KineticMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(CriticalChance, Attribute);
	CHECK_IF_ATTRIBUTE(CriticalDamage, Attribute);
	CHECK_IF_ATTRIBUTE(CriticalDefense, Attribute);
	CHECK_IF_ATTRIBUTE(FrontShield, Attribute);
	CHECK_IF_ATTRIBUTE(MaxFrontShield, Attribute);
	CHECK_IF_ATTRIBUTE(FrontKineticMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(FrontEnergyMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(BackShield, Attribute);
	CHECK_IF_ATTRIBUTE(MaxBackShield, Attribute);
	CHECK_IF_ATTRIBUTE(BackKineticMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(BackEnergyMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(RightShield, Attribute);
	CHECK_IF_ATTRIBUTE(MaxRightShield, Attribute);
	CHECK_IF_ATTRIBUTE(RightKineticMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(RightEnergyMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(LeftShield, Attribute);
	CHECK_IF_ATTRIBUTE(MaxLeftShield, Attribute);
	CHECK_IF_ATTRIBUTE(LeftKineticMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(LeftEnergyMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(IncomingFrontKineticDamage, Attribute);
	CHECK_IF_ATTRIBUTE(IncomingFrontEnergyDamage, Attribute);
	CHECK_IF_ATTRIBUTE(IncomingBackKineticDamage, Attribute);
	CHECK_IF_ATTRIBUTE(IncomingBackEnergyDamage, Attribute);
	CHECK_IF_ATTRIBUTE(IncomingRightKineticDamage, Attribute);
	CHECK_IF_ATTRIBUTE(IncomingRightEnergyDamage, Attribute);
	CHECK_IF_ATTRIBUTE(IncomingLeftKineticDamage, Attribute);
	CHECK_IF_ATTRIBUTE(IncomingLeftEnergyDamage, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UCombatAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, HitChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, EvadeChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, GlanceChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, GlanceValue, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, KineticMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, EnergyMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, CriticalChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, CriticalDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, CriticalDefense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, FrontShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, MaxFrontShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, FrontKineticMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, FrontEnergyMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, BackShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, MaxBackShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, BackKineticMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, BackEnergyMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, RightShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, MaxRightShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, RightKineticMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, RightEnergyMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, LeftShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, MaxLeftShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, LeftKineticMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, LeftEnergyMitigation, COND_None, REPNOTIFY_Always);
}

void UCombatAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	CAP_ATTRIBUTE(FrontShield, MaxFrontShield, Data);
	CAP_ATTRIBUTE(BackShield, MaxBackShield, Data);
	CAP_ATTRIBUTE(RightShield, MaxRightShield, Data);
	CAP_ATTRIBUTE(LeftShield, MaxLeftShield, Data);
}

ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, HitChance)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, EvadeChance)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, GlanceChance)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, GlanceValue)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, CriticalChance)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, CriticalDamage)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, CriticalDefense)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, FrontShield)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, FrontKineticMitigation)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, FrontEnergyMitigation)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, BackShield)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, BackKineticMitigation)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, BackEnergyMitigation)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, RightShield)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, RightKineticMitigation)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, RightEnergyMitigation)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, LeftShield)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, LeftKineticMitigation)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, LeftEnergyMitigation)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, MaxFrontShield)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, MaxBackShield)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, MaxRightShield)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, MaxLeftShield)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, KineticMitigation)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, EnergyMitigation)
ATTRIBUTE_IMPLEMENT(UCombatAttributeSet, ShieldFaces)
