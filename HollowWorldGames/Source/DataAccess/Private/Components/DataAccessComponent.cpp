// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/DataAccessComponent.h"


void FNumericValue::SetValue(float NewValue)
{
	Value = NewValue;
	Dirty = true;
}

void FStringValue::SetValue(FString NewValue)
{
	Value = NewValue;
	Dirty = true;
}

// Sets default values for this component's properties
UDataAccessComponent::UDataAccessComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UDataAccessComponent::LoadActorState(uint64 ActorId)
{
	ensureMsgf(false, TEXT("Load Actor State Not Override"));
}

void UDataAccessComponent::SaveActorState()
{
	ensureMsgf(false, TEXT("Save Actor State Not Override"));
}

float UDataAccessComponent::GetFloatAttribute(FString Attribute)
{
	if(NumericAttributes.Contains(Attribute))
	{
		return NumericAttributes[Attribute].Value;
	}
	return 0;
}

FString UDataAccessComponent::GetStringAttribute(FString Attribute)
{
	if(StringAttributes.Contains(Attribute))
	{
		return StringAttributes[Attribute].Value;
	}
	return FString();
}

int UDataAccessComponent::GetIntAttribute(FString Attribute)
{
	if(NumericAttributes.Contains(Attribute))
	{
		return static_cast<int>(NumericAttributes[Attribute].Value);
	}
	return 0;
}

float UDataAccessComponent::SetFloatAttribute(FString Attribute, float Value)
{
	NumericAttributes[Attribute].SetValue(Value);
	return Value;
}

FString UDataAccessComponent::SetStringAttribute(FString Attribute, FString Value)
{
	StringAttributes[Attribute].SetValue(Value);
	return Value;
}

int UDataAccessComponent::SetIntAttribute(FString Attribute, int Value)
{
	NumericAttributes[Attribute].SetValue(Value);
	return Value;
}

