// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/ShieldAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Chaos/Deformable/MuscleActivationConstraints.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldFrontHitPointsTag,"Shield.Attribute.FrontHitPoints","Max Back Shield Health");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldMaxFrontHitPointsTag,"Shield.Attribute.MaxFrontHitPoints","Max Back Shield Health");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldBackHitPointsTag,"Shield.Attribute.BackHitPoints","Max Back Shield Health");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldMaxBackHitPointsTag,"Shield.Attribute.MaxBackHitPoints","Max Back Shield Health");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldPowerTag,"Shield.Attribute.Power","Max Back Shield Health");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldDistributionTag,"Shield.Attribute.Distribution","Max Back Shield Health");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShieldOnTag,"Shield.State.On","Shield On");

float UShieldAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(ShieldFrontHitPoints, AttributeTag);
	GET_IF_TAGMATCHES(ShieldMaxFrontHitPoints, AttributeTag);
	GET_IF_TAGMATCHES(ShieldBackHitPoints, AttributeTag);
	GET_IF_TAGMATCHES(ShieldMaxBackHitPoints, AttributeTag);
	GET_IF_TAGMATCHES(ShieldPower, AttributeTag);
	GET_IF_TAGMATCHES(ShieldDistribution, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UShieldAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(ShieldFrontHitPoints, Attribute, Value);
	SET_IF_TAGMATCHES(ShieldMaxFrontHitPoints, Attribute, Value);
	SET_IF_TAGMATCHES(ShieldBackHitPoints, Attribute, Value);
	SET_IF_TAGMATCHES(ShieldMaxBackHitPoints, Attribute, Value);
	SET_IF_TAGMATCHES(ShieldPower, Attribute, Value);
	SET_IF_TAGMATCHES(ShieldDistribution, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UShieldAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(ShieldFrontHitPoints, Attribute);
	CHECK_IF_ATTRIBUTE(ShieldMaxFrontHitPoints, Attribute);
	CHECK_IF_ATTRIBUTE(ShieldBackHitPoints, Attribute);
	CHECK_IF_ATTRIBUTE(ShieldMaxBackHitPoints, Attribute);
	CHECK_IF_ATTRIBUTE(ShieldPower, Attribute);
	CHECK_IF_ATTRIBUTE(ShieldDistribution, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UShieldAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldAttributeSet, ShieldFrontHitPoints, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldAttributeSet, ShieldMaxFrontHitPoints, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldAttributeSet, ShieldBackHitPoints, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldAttributeSet, ShieldMaxBackHitPoints, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldAttributeSet, ShieldPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldAttributeSet, ShieldDistribution, COND_None, REPNOTIFY_Always);
}

void UShieldAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	CAP_ATTRIBUTE(ShieldFrontHitPoints, ShieldMaxFrontHitPoints, Data);
	CAP_ATTRIBUTE(ShieldBackHitPoints, ShieldMaxBackHitPoints, Data);

	PROCESS_INCOMING_DAMAGE_NO_NOTIFY(ShieldIncomingFrontDamage, ShieldFrontHitPoints, Data);

}

ATTRIBUTE_IMPLEMENT(UShieldAttributeSet, ShieldFrontHitPoints);
ATTRIBUTE_IMPLEMENT(UShieldAttributeSet, ShieldMaxFrontHitPoints);
ATTRIBUTE_IMPLEMENT(UShieldAttributeSet, ShieldBackHitPoints);
ATTRIBUTE_IMPLEMENT(UShieldAttributeSet, ShieldMaxBackHitPoints);
ATTRIBUTE_IMPLEMENT(UShieldAttributeSet, ShieldPower);
ATTRIBUTE_IMPLEMENT(UShieldAttributeSet, ShieldDistribution);
