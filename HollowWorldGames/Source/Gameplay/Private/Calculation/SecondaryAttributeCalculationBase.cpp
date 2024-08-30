﻿// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Calculation/SecondaryAttributeCalculationBase.h"
#include "Attributes/RPGAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "UObject/FastReferenceCollector.h"

USecondaryAttributeCalculationBase::USecondaryAttributeCalculationBase()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Level, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Strength, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Agility, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Precision, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Wisdom, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Intelligence, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Luck, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Constitution, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Endurance, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Charisma, Source, false, true);
	DEFINE_ATTRIBUTE_CAPTUREDEF2(URPGAttributeSet, Armor, Source, false, true);
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

float USecondaryAttributeCalculationBase::ComputeMitigation1_Implementation(float Level, float Strength, float Agility,
	float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
	float Armor) const
{
	return CalculateAttribute(Mitigation1Table, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeMitigation2_Implementation(float Level, float Strength, float Agility,
	float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
	float Armor) const
{
	return CalculateAttribute(Mitigation2Table, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeMitigation3_Implementation(float Level, float Strength, float Agility,
	float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
	float Armor) const
{
	return CalculateAttribute(Mitigation3Table, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeMitigation4_Implementation(float Level, float Strength, float Agility,
	float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
	float Armor) const
{
	return CalculateAttribute(Mitigation4Table, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeResistance1_Implementation(float Level, float Strength, float Agility,
	float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
	float Armor) const
{
	return CalculateAttribute(Resistance1Table, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeResistance2_Implementation(float Level, float Strength, float Agility,
	float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
	float Armor) const
{
	return CalculateAttribute(Resistance2Table, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeResistance3_Implementation(float Level, float Strength, float Agility,
	float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
	float Armor) const
{
	return CalculateAttribute(Resistance3Table, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
}

float USecondaryAttributeCalculationBase::ComputeResistance4_Implementation(float Level, float Strength, float Agility,
	float Precision, float Intelligence, float Wisdom, float Luck, float Constitution, float Endurance, float Charisma,
	float Armor) const
{
	return CalculateAttribute(Resistance4Table, Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Luck);
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

	float HealthMax = ComputeHealth(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	HealthMax += GetAttributeFromGear(HealthMaxTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, HealthMax, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE_LOCAL(URPGAttributeSet, Health, OutExecutionOutput, HealthMax);

	float EnergyMax = ComputeEnergy(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	EnergyMax += GetAttributeFromGear(EnergyMaxTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, EnergyMax, OutExecutionOutput);
	WRITE_EXECUTION_ATTRIBUTE_LOCAL(URPGAttributeSet, Energy, OutExecutionOutput, EnergyMax);

	float BlockChance = ComputeBlockChance(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	BlockChance += GetAttributeFromGear(BlockChanceTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, BlockChance, OutExecutionOutput);

	float BlockValue = ComputeBlockValue(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	BlockValue += GetAttributeFromGear(BlockValueTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, BlockValue, OutExecutionOutput);

	float GlancingBlowChance = ComputeGlanceChance(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	GlancingBlowChance += GetAttributeFromGear(GlanceChanceTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, GlancingBlowChance, OutExecutionOutput);

	float ParryChance = ComputeParryChance(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	ParryChance += GetAttributeFromGear(ParryChanceTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, ParryChance, OutExecutionOutput);
	
	float EvadeChance = ComputeEvadeChance(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	EvadeChance += GetAttributeFromGear(EvadeChanceTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, EvadeChance, OutExecutionOutput);

	float CriticalChance = ComputeCriticalChance(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	CriticalChance += GetAttributeFromGear(CriticalChanceTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, CriticalChance, OutExecutionOutput);

	float CriticalValue = ComputeCriticalValue(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	CriticalValue += GetAttributeFromGear(CriticalValueTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, CriticalValue, OutExecutionOutput);

	float CriticalDefense = ComputeCriticalDefense(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	CriticalDefense += GetAttributeFromGear(CriticalDefenseTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, CriticalDefense, OutExecutionOutput);
	
	float Accuracy = ComputeAccuracy(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	Accuracy += GetAttributeFromGear(AccuracyTag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, Accuracy, OutExecutionOutput);

	float Mitigation1 = ComputeMitigation1(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	Mitigation1 += GetAttributeFromGear(Mitigation1Tag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, Mitigation1, OutExecutionOutput);

	float Mitigation2 = ComputeMitigation2(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	Mitigation2 += GetAttributeFromGear(Mitigation2Tag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, Mitigation2, OutExecutionOutput);

	float Mitigation3 = ComputeMitigation3(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	Mitigation3 += GetAttributeFromGear(Mitigation1Tag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, Mitigation3, OutExecutionOutput);

	float Mitigation4 = ComputeMitigation4(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	Mitigation4 += GetAttributeFromGear(Mitigation4Tag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, Mitigation4, OutExecutionOutput);

	float Resistance1 = ComputeResistance1(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	Resistance1 += GetAttributeFromGear(Resistance1Tag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, Resistance1, OutExecutionOutput);

	float Resistance2 = ComputeResistance2(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	Resistance2 += GetAttributeFromGear(Resistance2Tag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, Resistance2, OutExecutionOutput);

	float Resistance3 = ComputeResistance3(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	Resistance3 += GetAttributeFromGear(Resistance1Tag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, Resistance3, OutExecutionOutput);

	float Resistance4 = ComputeResistance4(Level, Strength, Agility, Precision, Intelligence, Wisdom, Luck, Constitution, Endurance, Charisma, Armor);
	Resistance4 += GetAttributeFromGear(Resistance4Tag, Source);
	WRITE_EXECUTION_ATTRIBUTE(URPGAttributeSet, Resistance4, OutExecutionOutput);
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