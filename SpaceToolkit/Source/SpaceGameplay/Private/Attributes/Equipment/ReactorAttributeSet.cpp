// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/Equipment/ReactorAttributeSet.h"

#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(PowerOutputTag,"Reactor.Attributes.PowerOutput","Reactor Output");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FuelAvailableTag,"Reactor.Attributes.FuelAvailable","Reactor Output");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FuelNeededTag,"Reactor.Attributes.FuelNeeded","Reactor Output");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxPowerOutputTag,"Reactor.Attributes.MaxPowerOutput","Reactor Output");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ReactorOnTag,"Reactor.State.On","Reactor On");

float UReactorAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(PowerOutput, AttributeTag);
	GET_IF_TAGMATCHES(FuelAvailable, AttributeTag);
	GET_IF_TAGMATCHES(FuelNeeded, AttributeTag);
	GET_IF_TAGMATCHES(MaxPowerOutput, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UReactorAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(PowerOutput, Attribute, Value);
	SET_IF_TAGMATCHES(FuelAvailable, Attribute, Value);
	SET_IF_TAGMATCHES(FuelNeeded, Attribute, Value);
	SET_IF_TAGMATCHES(MaxPowerOutput, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UReactorAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(PowerOutput, Attribute);
	CHECK_IF_ATTRIBUTE(FuelAvailable, Attribute);
	CHECK_IF_ATTRIBUTE(FuelNeeded, Attribute);
	CHECK_IF_ATTRIBUTE(MaxPowerOutput, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UReactorAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UReactorAttributeSet, PowerOutput, COND_None, REPNOTIFY_Always);
}

void UReactorAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
}

ATTRIBUTE_IMPLEMENT(UReactorAttributeSet, PowerOutput);

