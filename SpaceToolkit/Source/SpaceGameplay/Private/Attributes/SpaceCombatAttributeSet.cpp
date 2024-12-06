// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/SpaceCombatAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"


float USpaceCombatAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(FrontShield, AttributeTag);
	GET_IF_TAGMATCHES(MaxFrontShield, AttributeTag);
	GET_IF_TAGMATCHES(FrontMitigation1, AttributeTag);
	GET_IF_TAGMATCHES(FrontMitigation2, AttributeTag);
	GET_IF_TAGMATCHES(FrontMitigation3, AttributeTag);
	GET_IF_TAGMATCHES(FrontMitigation4, AttributeTag);

	GET_IF_TAGMATCHES(BackShield, AttributeTag);
	GET_IF_TAGMATCHES(MaxBackShield, AttributeTag);
	GET_IF_TAGMATCHES(BackMitigation1, AttributeTag);
	GET_IF_TAGMATCHES(BackMitigation2, AttributeTag);
	GET_IF_TAGMATCHES(BackMitigation3, AttributeTag);
	GET_IF_TAGMATCHES(BackMitigation4, AttributeTag);

	GET_IF_TAGMATCHES(RightShield, AttributeTag);
	GET_IF_TAGMATCHES(MaxRightShield, AttributeTag);
	GET_IF_TAGMATCHES(RightMitigation1, AttributeTag);
	GET_IF_TAGMATCHES(RightMitigation2, AttributeTag);
	GET_IF_TAGMATCHES(RightMitigation3, AttributeTag);
	GET_IF_TAGMATCHES(RightMitigation4, AttributeTag);

	GET_IF_TAGMATCHES(LeftShield, AttributeTag);
	GET_IF_TAGMATCHES(MaxLeftShield, AttributeTag);
	GET_IF_TAGMATCHES(LeftMitigation1, AttributeTag);
	GET_IF_TAGMATCHES(LeftMitigation2, AttributeTag);
	GET_IF_TAGMATCHES(LeftMitigation3, AttributeTag);
	GET_IF_TAGMATCHES(LeftMitigation4, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void USpaceCombatAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(FrontShield, Attribute, Value);
	SET_IF_TAGMATCHES(MaxFrontShield, Attribute, Value);
	SET_IF_TAGMATCHES(FrontMitigation1, Attribute, Value);
	SET_IF_TAGMATCHES(FrontMitigation2, Attribute, Value);
	SET_IF_TAGMATCHES(FrontMitigation3, Attribute, Value);
	SET_IF_TAGMATCHES(FrontMitigation4, Attribute, Value);

	SET_IF_TAGMATCHES(BackShield, Attribute, Value);
	SET_IF_TAGMATCHES(MaxBackShield, Attribute, Value);
	SET_IF_TAGMATCHES(BackMitigation1, Attribute, Value);
	SET_IF_TAGMATCHES(BackMitigation2, Attribute, Value);
	SET_IF_TAGMATCHES(BackMitigation3, Attribute, Value);
	SET_IF_TAGMATCHES(BackMitigation4, Attribute, Value);

	SET_IF_TAGMATCHES(RightShield, Attribute, Value);
	SET_IF_TAGMATCHES(MaxRightShield, Attribute, Value);
	SET_IF_TAGMATCHES(RightMitigation1, Attribute, Value);
	SET_IF_TAGMATCHES(RightMitigation2, Attribute, Value);
	SET_IF_TAGMATCHES(RightMitigation3, Attribute, Value);
	SET_IF_TAGMATCHES(RightMitigation4, Attribute, Value);

	SET_IF_TAGMATCHES(LeftShield, Attribute, Value);
	SET_IF_TAGMATCHES(MaxLeftShield, Attribute, Value);
	SET_IF_TAGMATCHES(LeftMitigation1, Attribute, Value);
	SET_IF_TAGMATCHES(LeftMitigation2, Attribute, Value);
	SET_IF_TAGMATCHES(LeftMitigation3, Attribute, Value);
	SET_IF_TAGMATCHES(LeftMitigation4, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag USpaceCombatAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(FrontShield, Attribute);
	CHECK_IF_ATTRIBUTE(MaxFrontShield, Attribute);
	CHECK_IF_ATTRIBUTE(FrontMitigation1, Attribute);
	CHECK_IF_ATTRIBUTE(FrontMitigation2, Attribute);
	CHECK_IF_ATTRIBUTE(FrontMitigation3, Attribute);
	CHECK_IF_ATTRIBUTE(FrontMitigation4, Attribute);
	CHECK_IF_ATTRIBUTE(BackShield, Attribute);
	CHECK_IF_ATTRIBUTE(MaxBackShield, Attribute);
	CHECK_IF_ATTRIBUTE(BackMitigation1, Attribute);
	CHECK_IF_ATTRIBUTE(BackMitigation2, Attribute);
	CHECK_IF_ATTRIBUTE(BackMitigation3, Attribute);
	CHECK_IF_ATTRIBUTE(BackMitigation4, Attribute);
	CHECK_IF_ATTRIBUTE(RightShield, Attribute);
	CHECK_IF_ATTRIBUTE(MaxRightShield, Attribute);
	CHECK_IF_ATTRIBUTE(RightMitigation1, Attribute);
	CHECK_IF_ATTRIBUTE(RightMitigation2, Attribute);
	CHECK_IF_ATTRIBUTE(RightMitigation3, Attribute);
	CHECK_IF_ATTRIBUTE(RightMitigation4, Attribute);
	CHECK_IF_ATTRIBUTE(LeftShield, Attribute);
	CHECK_IF_ATTRIBUTE(MaxLeftShield, Attribute);
	CHECK_IF_ATTRIBUTE(LeftMitigation1, Attribute);
	CHECK_IF_ATTRIBUTE(LeftMitigation2, Attribute);
	CHECK_IF_ATTRIBUTE(LeftMitigation3, Attribute);
	CHECK_IF_ATTRIBUTE(LeftMitigation4, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void USpaceCombatAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, FrontShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, MaxFrontShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, FrontMitigation1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, FrontMitigation2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, FrontMitigation3, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, FrontMitigation4, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, BackShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, MaxBackShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, BackMitigation1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, BackMitigation2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, BackMitigation3, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, BackMitigation4, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, RightShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, MaxRightShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, RightMitigation1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, RightMitigation2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, RightMitigation3, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, RightMitigation4, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, LeftShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, MaxLeftShield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, LeftMitigation1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, LeftMitigation2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, LeftMitigation3, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USpaceCombatAttributeSet, LeftMitigation4, COND_None, REPNOTIFY_Always);
}

void USpaceCombatAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	CAP_ATTRIBUTE(FrontShield, MaxFrontShield, Data);
	CAP_ATTRIBUTE(BackShield, MaxBackShield, Data);
	CAP_ATTRIBUTE(RightShield, MaxRightShield, Data);
	CAP_ATTRIBUTE(LeftShield, MaxLeftShield, Data);
}

ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, FrontShield)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, FrontMitigation1)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, FrontMitigation2)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, FrontMitigation3)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, FrontMitigation4)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, BackShield)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, BackMitigation1)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, BackMitigation2)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, BackMitigation3)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, BackMitigation4)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, RightShield)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, RightMitigation1)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, RightMitigation2)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, RightMitigation3)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, RightMitigation4)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, LeftShield)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, LeftMitigation1)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, LeftMitigation2)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, LeftMitigation3)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, LeftMitigation4)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, MaxFrontShield)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, MaxBackShield)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, MaxRightShield)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, MaxLeftShield)
ATTRIBUTE_IMPLEMENT(USpaceCombatAttributeSet, ShieldFaces)
