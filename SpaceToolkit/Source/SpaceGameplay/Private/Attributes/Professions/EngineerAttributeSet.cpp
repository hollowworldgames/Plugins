// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/Professions/EngineerAttributeSet.h"
#include "Attributes/Equipment/ShieldAttributeSet.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(ReactorPowerTag, "Engineer.Attributes.ReactorPower", "Reactor Power");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ReactorEfficiencyTag,"Engineer.Attributes.ReactorEfficiency","Reactor Efficiency");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldEfficiencyTag,"Engineer.Attributes.ShieldEfficiency","Reactor Efficiency");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldStrengthTag,"Engineer.Attributes.ShieldStrength","Reactor Efficiency");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldReinforcementTag,"Engineer.Attributes.ShieldReinforcement","Reactor Efficiency");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(BatteryEfficiencyTag,"Engineer.Attributes.BatteryEfficiency","Battery Efficiency Efficiency");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(HullStrengthTag,"Engineer.Attributes.HullStrength","Hull Strength");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(HullReinforcementTag,"Engineer.Attributes.HullReinforcement","Hull Reinforcement");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ComponentStrengthTag,"Engineer.Attributes.ComponentStrength","Component Strength");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ArmorReinforcementTag,"Engineer.Attributes.ArmorReinforcement","Armor Reinforcement");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ArmorMassTag,"Engineer.Attributes.ArmorMass","Armor Mass");

float UEngineerAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(ReactorPower, AttributeTag);
	GET_IF_TAGMATCHES(ReactorEfficiency, AttributeTag);
	GET_IF_TAGMATCHES(ShieldEfficiency, AttributeTag);
	GET_IF_TAGMATCHES(ShieldStrength, AttributeTag);
	GET_IF_TAGMATCHES(ShieldReinforcement, AttributeTag);
	GET_IF_TAGMATCHES(BatteryEfficiency, AttributeTag);
	GET_IF_TAGMATCHES(HullStrength, AttributeTag);
	GET_IF_TAGMATCHES(HullReinforcement, AttributeTag);
	GET_IF_TAGMATCHES(ComponentStrength, AttributeTag);
	GET_IF_TAGMATCHES(ArmorReinforcement, AttributeTag);
	GET_IF_TAGMATCHES(ArmorMass, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UEngineerAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(ReactorPower, Attribute, Value);
	SET_IF_TAGMATCHES(ReactorEfficiency, Attribute, Value);
	SET_IF_TAGMATCHES(ShieldEfficiency, Attribute, Value);
	SET_IF_TAGMATCHES(ShieldStrength, Attribute, Value);
	SET_IF_TAGMATCHES(ShieldReinforcement, Attribute, Value);
	SET_IF_TAGMATCHES(BatteryEfficiency, Attribute, Value);
	SET_IF_TAGMATCHES(HullStrength, Attribute, Value);
	SET_IF_TAGMATCHES(HullReinforcement, Attribute, Value);
	SET_IF_TAGMATCHES(ComponentStrength, Attribute, Value);
	SET_IF_TAGMATCHES(ArmorReinforcement, Attribute, Value);
	SET_IF_TAGMATCHES(ArmorMass, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UEngineerAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(ReactorPower, Attribute);
	CHECK_IF_ATTRIBUTE(ReactorEfficiency, Attribute);
	CHECK_IF_ATTRIBUTE(ShieldEfficiency, Attribute);
	CHECK_IF_ATTRIBUTE(ShieldStrength, Attribute);
	CHECK_IF_ATTRIBUTE(ShieldReinforcement, Attribute);
	CHECK_IF_ATTRIBUTE(BatteryEfficiency, Attribute);
	CHECK_IF_ATTRIBUTE(HullStrength, Attribute);
	CHECK_IF_ATTRIBUTE(HullReinforcement, Attribute);
	CHECK_IF_ATTRIBUTE(ComponentStrength, Attribute);
	CHECK_IF_ATTRIBUTE(ArmorReinforcement, Attribute);
	CHECK_IF_ATTRIBUTE(ArmorMass, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UEngineerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineerAttributeSet, ReactorPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineerAttributeSet, ReactorEfficiency, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineerAttributeSet, ShieldEfficiency, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineerAttributeSet, ShieldStrength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineerAttributeSet, ShieldReinforcement, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineerAttributeSet, BatteryEfficiency, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineerAttributeSet, HullStrength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineerAttributeSet, HullReinforcement, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineerAttributeSet, ComponentStrength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineerAttributeSet, ArmorReinforcement, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEngineerAttributeSet, ArmorMass, COND_None, REPNOTIFY_Always);
}

void UEngineerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UEngineerAttributeSet, ReactorPower);
ATTRIBUTE_IMPLEMENT(UEngineerAttributeSet, ReactorEfficiency);
ATTRIBUTE_IMPLEMENT(UEngineerAttributeSet, ShieldEfficiency);
ATTRIBUTE_IMPLEMENT(UEngineerAttributeSet, ShieldStrength);
ATTRIBUTE_IMPLEMENT(UEngineerAttributeSet, ShieldReinforcement);
ATTRIBUTE_IMPLEMENT(UEngineerAttributeSet, BatteryEfficiency);
ATTRIBUTE_IMPLEMENT(UEngineerAttributeSet, HullStrength);
ATTRIBUTE_IMPLEMENT(UEngineerAttributeSet, HullReinforcement);
ATTRIBUTE_IMPLEMENT(UEngineerAttributeSet, ComponentStrength);
ATTRIBUTE_IMPLEMENT(UEngineerAttributeSet, ArmorReinforcement);
ATTRIBUTE_IMPLEMENT(UEngineerAttributeSet, ArmorMass);