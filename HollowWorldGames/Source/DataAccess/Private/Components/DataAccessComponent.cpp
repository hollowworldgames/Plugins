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

float FRecord::GetFloatValue(const FGameplayTag Tag) const
{
	if (NumericValues.Contains(Tag))
	{
		return NumericValues[Tag].Value;
	}
	return 0;
}

int FRecord::GetIntValue(const FGameplayTag Tag) const
{
	if (NumericValues.Contains(Tag))
	{
		return NumericValues[Tag].Value;
	}
	return 0;
}

FName FRecord::GetNameValue(const FGameplayTag Tag) const
{
	if (StringValues.Contains(Tag))
	{
		return FName(StringValues[Tag].Value);
	}
	return NAME_None;
}

FString FRecord::GetStringValue(const FGameplayTag Tag) const
{
	if (StringValues.Contains(Tag))
	{
		return StringValues[Tag].Value;
	}
	return "";
}

void FRecord::AddNumericValue(const FGameplayTag& Tag, int Value)
{
	NumericValues[Tag].Value = Value;
}

void FRecord::AddNumericValue(const FGameplayTag& Tag, float Value)
{
	NumericValues[Tag].Value = Value;
}

void FRecord::AddNumericValue(const FGameplayTag& Tag, bool Value)
{
	NumericValues[Tag].Value = (Value) ?  1.0f : 0.0f;
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


FName UDataAccessComponent::GetNameAttribute(FGameplayTag Attribute)
{
	if (StringAttributes.Contains(Attribute))
	{
		return FName(StringAttributes[Attribute].Value);
	}
	return NAME_None;
}

void UDataAccessComponent::SaveActorState()
{
	ensureMsgf(false, TEXT("Save Actor State Not Override"));
}

float UDataAccessComponent::GetFloatAttribute(FGameplayTag Attribute)
{
	if(NumericAttributes.Contains(Attribute))
	{
		return NumericAttributes[Attribute].Value;
	}
	return 0;
}

FString UDataAccessComponent::GetStringAttribute(FGameplayTag Attribute)
{
	if(StringAttributes.Contains(Attribute))
	{
		return StringAttributes[Attribute].Value;
	}
	return FString();
}

int UDataAccessComponent::GetIntAttribute(FGameplayTag Attribute)
{
	if(NumericAttributes.Contains(Attribute))
	{
		return static_cast<int>(NumericAttributes[Attribute].Value);
	}
	return 0;
}


bool UDataAccessComponent::GetBoolAttribute(FGameplayTag Attribute)
{
	if(NumericAttributes.Contains(Attribute))
	{
		return static_cast<int>(NumericAttributes[Attribute].Value) == 1;
	}
	return true;
}

float UDataAccessComponent::SetFloatAttribute(FGameplayTag Attribute, float Value)
{
	NumericAttributes[Attribute].SetValue(Value);
	return Value;
}

FString UDataAccessComponent::SetStringAttribute(FGameplayTag Attribute, FString Value)
{
	StringAttributes[Attribute].SetValue(Value);
	return Value;
}

int UDataAccessComponent::SetIntAttribute(FGameplayTag Attribute, int Value)
{
	NumericAttributes[Attribute].SetValue(Value);
	return Value;
}

bool UDataAccessComponent::SetBoolAttribute(FGameplayTag Attribute, bool Value)
{
	NumericAttributes[Attribute].SetValue((Value) ?  1.0f : 0.0f);
	return Value;
}

TArray<FRecord> UDataAccessComponent::GetRecordsOfType(FGameplayTag Type) const
{
	TArray<FRecord> OutRecords;
	for(const FRecord& Record : Records)
	{
		if (Record.RecordTag.MatchesTag(Type))
		{
			OutRecords.Add(Record);
		}
	}
	return OutRecords;
}

void UDataAccessComponent::WriteRecord(FRecord& Record)
{
	Records.AddUnique(Record);
}


