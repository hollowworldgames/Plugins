// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/PrimaryAttributeSet.h"

#include "EditorDirectories.h"
#include "Attributes/VitalAttributeSet.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"


UPrimaryAttributeCalculation::UPrimaryAttributeCalculation()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UVitalAttributeSet, Level, Target, false, true);
}

void UPrimaryAttributeCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
                                                          FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);
	INITIALIZE_EXECUTION_CALC2(ACharacter, ACharacter, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(Level, ExecutionParams);

	const float Strength = StrengthCurve.GetValueAtLevel(Level) + Spec.GetSetByCallerMagnitude(StrengthTag);
	const float Agility = StrengthCurve.GetValueAtLevel(Level) + Spec.GetSetByCallerMagnitude(AgilityTag);
	const float Precision = StrengthCurve.GetValueAtLevel(Level) + Spec.GetSetByCallerMagnitude(PrecisionTag);
	const float Wisdom = StrengthCurve.GetValueAtLevel(Level) + Spec.GetSetByCallerMagnitude(WisdomTag);
	const float Intelligence = StrengthCurve.GetValueAtLevel(Level) + Spec.GetSetByCallerMagnitude(IntelligenceTag);
	const float Luck = StrengthCurve.GetValueAtLevel(Level) + Spec.GetSetByCallerMagnitude(LuckTag);
	const float Constitution = StrengthCurve.GetValueAtLevel(Level) + Spec.GetSetByCallerMagnitude(ConstitutionTag);
	const float Endurance = StrengthCurve.GetValueAtLevel(Level) * Spec.GetSetByCallerMagnitude(EnduranceTag);
	const float Charisma = StrengthCurve.GetValueAtLevel(Level) * Spec.GetSetByCallerMagnitude(CharismaTag);

	WRITE_EXECUTION_ATTRIBUTE(UPrimaryAttributeSet, Strength, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(UPrimaryAttributeSet, Agility, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(UPrimaryAttributeSet, Precision, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(UPrimaryAttributeSet, Wisdom, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(UPrimaryAttributeSet, Intelligence, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(UPrimaryAttributeSet, Luck, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(UPrimaryAttributeSet, Constitution, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(UPrimaryAttributeSet, Endurance, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE(UPrimaryAttributeSet, Charisma, OutExecutionOutput);
}

float UPrimaryAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	return Super::GetAttributeValue(AttributeTag);
}

void UPrimaryAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UPrimaryAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	return Super::GetAttributeTag(Attribute);
}

void UPrimaryAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Agility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Precision, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Wisdom, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Luck, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Constitution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Endurance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Charisma, COND_None, REPNOTIFY_Always);
}

void UPrimaryAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Strength);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Agility);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Precision);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Intelligence);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Wisdom);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Luck);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Constitution);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Endurance);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Charisma);
