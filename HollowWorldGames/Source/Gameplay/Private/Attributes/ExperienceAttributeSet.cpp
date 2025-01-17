// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/ExperienceAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Attributes/VitalAttributeSet.h"
#include "Net/UnrealNetwork.h"

float UExperienceAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(Experience, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UExperienceAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(Experience, Attribute, Value);
	if (Attribute == ExperienceTag)//set level if experience changed
	{
		if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetOwningAbilitySystemComponent()))
		{
			AbilitySystemComponent->SetAttributeValue(LevelTag, LevelFromXP.GetValueAtLevel(Value));
		}
		else
		{
			ensureMsgf(false, TEXT("Experience Attribute Set is Missing Vital Attribute Set"));
		}
	}
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UExperienceAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(Experience, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UExperienceAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UExperienceAttributeSet, Experience, COND_None, REPNOTIFY_Always);
}

void UExperienceAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	bool Found = false;
	float Level = Data.Target.GetGameplayAttributeValue(UVitalAttributeSet::GetLevelAttribute(), Found);
	
	PROCESS_INCOMING_EXPERIENCE_NOTIFY_ONLY(IncomingExperience, Experience, LevelFromXP, Level, OnLevelChanged, Data);

	Data.Target.SetNumericAttributeBase(UVitalAttributeSet::GetLevelAttribute(), Level);
}

ATTRIBUTE_IMPLEMENT(UExperienceAttributeSet, Experience);