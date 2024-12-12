// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/Professions/PilotAttributeSet.h"

#include "Net/UnrealNetwork.h"



float UPilotAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(GForceTolerance, AttributeTag);
	GET_IF_TAGMATCHES(GForceEndurance, AttributeTag);
	GET_IF_TAGMATCHES(ThrusterPower, AttributeTag);
	GET_IF_TAGMATCHES(ThrusterResponse, AttributeTag);
	GET_IF_TAGMATCHES(JumpPower, AttributeTag);
	GET_IF_TAGMATCHES(JumpRange, AttributeTag);
	GET_IF_TAGMATCHES(JumpSpeed, AttributeTag);
	GET_IF_TAGMATCHES(JumpTime, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UPilotAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(GForceTolerance, Attribute, Value);
	SET_IF_TAGMATCHES(GForceEndurance, Attribute, Value);
	SET_IF_TAGMATCHES(ThrusterPower, Attribute, Value);
	SET_IF_TAGMATCHES(ThrusterResponse, Attribute, Value);
	SET_IF_TAGMATCHES(JumpPower, Attribute, Value);
	SET_IF_TAGMATCHES(JumpRange, Attribute, Value);
	SET_IF_TAGMATCHES(JumpSpeed, Attribute, Value);
	SET_IF_TAGMATCHES(JumpTime, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UPilotAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(GForceTolerance, Attribute);
	CHECK_IF_ATTRIBUTE(GForceEndurance, Attribute);
	CHECK_IF_ATTRIBUTE(ThrusterPower, Attribute);
	CHECK_IF_ATTRIBUTE(ThrusterResponse, Attribute);
	CHECK_IF_ATTRIBUTE(JumpPower, Attribute);
	CHECK_IF_ATTRIBUTE(JumpRange, Attribute);
	CHECK_IF_ATTRIBUTE(JumpSpeed, Attribute);
	CHECK_IF_ATTRIBUTE(JumpTime, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UPilotAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UPilotAttributeSet, GForceTolerance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPilotAttributeSet, GForceEndurance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPilotAttributeSet, ThrusterPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPilotAttributeSet, ThrusterResponse, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPilotAttributeSet, JumpPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPilotAttributeSet, JumpRange, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPilotAttributeSet, JumpSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPilotAttributeSet, JumpTime, COND_None, REPNOTIFY_Always);
}

void UPilotAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UPilotAttributeSet, GForceTolerance);
ATTRIBUTE_IMPLEMENT(UPilotAttributeSet, GForceEndurance);
ATTRIBUTE_IMPLEMENT(UPilotAttributeSet, ThrusterPower);
ATTRIBUTE_IMPLEMENT(UPilotAttributeSet, ThrusterResponse);
ATTRIBUTE_IMPLEMENT(UPilotAttributeSet, JumpPower);
ATTRIBUTE_IMPLEMENT(UPilotAttributeSet, JumpRange);
ATTRIBUTE_IMPLEMENT(UPilotAttributeSet, JumpSpeed);
ATTRIBUTE_IMPLEMENT(UPilotAttributeSet, JumpTime);

