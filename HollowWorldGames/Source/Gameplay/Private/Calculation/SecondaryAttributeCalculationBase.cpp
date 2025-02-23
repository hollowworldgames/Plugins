// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Calculation/SecondaryAttributeCalculationBase.h"

#include "Attributes/ExperienceAttributeSet.h"
#include "Attributes/PrimaryAttributeSet.h"
#include "Attributes/RPGAttributeSet.h"
#include "Attributes/RPGCombatAttributeSet.h"
#include "Attributes/VitalAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "UObject/FastReferenceCollector.h"

USecondaryAttributeCalculationBase::USecondaryAttributeCalculationBase()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UExperienceAttributeSet, Level, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UPrimaryAttributeSet, Strength, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UPrimaryAttributeSet, Agility, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UPrimaryAttributeSet, Precision, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UPrimaryAttributeSet, Wisdom, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UPrimaryAttributeSet, Intelligence, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UPrimaryAttributeSet, Luck, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UPrimaryAttributeSet, Constitution, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UPrimaryAttributeSet, Endurance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(UPrimaryAttributeSet, Charisma, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGCombatAttributeSet, Armor, Source, false, true);
}

float USecondaryAttributeCalculationBase::ComputeEnergy_Implementation(float Level, float Strength, float Agility,
                                                                       float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
                                                                       float Armor) const
{
	return CalculateAttribute(HealthTable, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeHealth_Implementation(float Level, float Strength, float Agility,
                                                                       float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
                                                                       float Armor) const
{
	return CalculateAttribute(HealthTable, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::GetAttributeFromGear_Implementation(FGameplayTag Attribute, const ACharacter * Character) const
{
	return 0;
}

float USecondaryAttributeCalculationBase::ComputeBlockChance_Implementation(float Level, float Strength, float Agility,
	float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
	float Armor) const
{
	return CalculateAttribute(BlockChanceTable, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeBlockValue_Implementation(float Level, float Strength, float Agility,
	float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
	float Armor) const
{
	return CalculateAttribute(BlockValueTable, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}


inline float USecondaryAttributeCalculationBase::ComputeGlanceChance_Implementation(float Level, float Strength,
	float Agility, float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance,
	float Charisma, float Armor) const
{
	return CalculateAttribute(BlockValueTable, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeEvadeChance_Implementation(float Level, float Strength, float Agility,
	float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
	float Armor) const
{
	return CalculateAttribute(EvadeChanceTable, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeParryChance_Implementation(float Level, float Strength, float Agility,
	float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
	float Armor) const
{
	return CalculateAttribute(ParryChanceTable, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeCriticalChance_Implementation(float Level, float Strength,
	float Agility, float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance,
	float Charisma, float Armor) const
{
	return CalculateAttribute(CriticalChanceTable, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeCriticalValue_Implementation(float Level, float Strength,
	float Agility, float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance,
	float Charisma, float Armor) const
{
	return CalculateAttribute(CriticalValueTable, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeCriticalDefense_Implementation(float Level, float Strength,
	float Agility, float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance,
	float Charisma, float Armor) const
{
	return CalculateAttribute(CriticalDefenseTable, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeAccuracy_Implementation(float Level, float Strength,
	float Agility, float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance,
	float Charisma, float Armor) const
{
	return CalculateAttribute(AccuracyTable, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

void USecondaryAttributeCalculationBase::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);
	INITIALIZE_EXECUTION_CALC2(ACharacter, ACharacter, ExecutionParams);

	GET_EXECUTION_ATTRIBUTE(Level, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Strength, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Agility, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Precision, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Wisdom, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Intelligence, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Luck, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Constitution, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Endurance, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Charisma, ExecutionParams);
	GET_EXECUTION_ATTRIBUTE(Armor, ExecutionParams);

	float MaxHealth = ComputeHealth(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	MaxHealth += GetAttributeFromGear(HealthMaxTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(UVitalAttributeSet, MaxHealth, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE_LOCAL(UVitalAttributeSet, Health, OutExecutionOutput, MaxHealth);

	float MaxEnergy = ComputeEnergy(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	MaxEnergy += GetAttributeFromGear(EnergyMaxTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(UVitalAttributeSet, MaxEnergy, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE_LOCAL(UVitalAttributeSet, Energy, OutExecutionOutput, MaxEnergy);

	float BlockChance = ComputeBlockChance(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	BlockChance += GetAttributeFromGear(BlockChanceTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGMeleeCombatAttributeSet, BlockChance, OutExecutionOutput);

	float BlockValue = ComputeBlockValue(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	BlockValue += GetAttributeFromGear(BlockValueTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGMeleeCombatAttributeSet, BlockValue, OutExecutionOutput);

	float GlancingBlowChance = ComputeGlanceChance(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	GlancingBlowChance += GetAttributeFromGear(GlanceChanceTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGCombatAttributeSet, GlancingBlowChance, OutExecutionOutput);

	float ParryChance = ComputeParryChance(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	ParryChance += GetAttributeFromGear(ParryChanceTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGMeleeCombatAttributeSet, ParryChance, OutExecutionOutput);
	
	float EvadeChance = ComputeEvadeChance(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	EvadeChance += GetAttributeFromGear(EvadeChanceTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGCombatAttributeSet, EvadeChance, OutExecutionOutput);

	float CriticalChance = ComputeCriticalChance(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	CriticalChance += GetAttributeFromGear(CriticalChanceTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGCombatAttributeSet, CriticalChance, OutExecutionOutput);

	float CriticalValue = ComputeCriticalValue(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	CriticalValue += GetAttributeFromGear(CriticalValueTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGCombatAttributeSet, CriticalValue, OutExecutionOutput);

	float CriticalDefense = ComputeCriticalDefense(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	CriticalDefense += GetAttributeFromGear(CriticalDefenseTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGCombatAttributeSet, CriticalDefense, OutExecutionOutput);
	
	float HitChance = ComputeAccuracy(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	HitChance += GetAttributeFromGear(AccuracyTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGCombatAttributeSet, HitChance, OutExecutionOutput);
}

float USecondaryAttributeCalculationBase::CalculateAttribute(TObjectPtr<UCurveTable> Table, float Level, float Strength,
	float Agility, float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance,
	float Charisma, float Armor) const
{
	float Value = 0;
	FString Context;
	if(FRealCurve * BaseCurve = Table->FindCurve("Base", Context))
	{
		Value = BaseCurve->Eval(Level);
	}

	if(FRealCurve * StrengthCurve = Table->FindCurve(StrengthTag.GetTagName(), Context))
	{
		Value += StrengthCurve->Eval(Strength);
	}

	if(FRealCurve * AgilityCurve = Table->FindCurve(AgilityTag.GetTagName(), Context))
	{
		Value += AgilityCurve->Eval(Strength);
	}

	if(FRealCurve * PrecisionCurve = Table->FindCurve(PrecisionTag.GetTagName(), Context))
	{
		Value += PrecisionCurve->Eval(Precision);
	}

	if(FRealCurve * WisdomCurve = Table->FindCurve(WisdomTag.GetTagName(), Context))
	{
		Value += WisdomCurve->Eval(Wisdom);
	}

	if(FRealCurve * IntelligenceCurve = Table->FindCurve(IntelligenceTag.GetTagName(), Context))
	{
		Value += IntelligenceCurve->Eval(Precision);
	}

	if(FRealCurve * LuckCurve = Table->FindCurve(LuckTag.GetTagName(), Context))
	{
		Value += LuckCurve->Eval(Luck);
	}

	if(FRealCurve * ArmorCurve = Table->FindCurve(ArmorTag.GetTagName(), Context))
	{
		Value += ArmorCurve->Eval(Armor);
	}
	return Value;
}
