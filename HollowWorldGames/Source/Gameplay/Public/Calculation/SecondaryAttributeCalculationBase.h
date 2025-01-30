// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "GameplayEffectExecutionCalculation.h"
#include "SecondaryAttributeCalculationBase.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API USecondaryAttributeCalculationBase : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public :
	USecondaryAttributeCalculationBase();
	UFUNCTION(BlueprintNativeEvent)
	float ComputeHealth(float Level, float Strength, float Agility, float Precision, float Intelligence, float Wisdom,
	                  float Luck, float Constitution, float Endurance, float Charisma, float Armor) const;
	UFUNCTION(BlueprintNativeEvent)
	float ComputeEnergy(float Level, float Strength, float Agility, float Precision, float Intelligence, float Wisdom,
					  float Luck, float Constitution, float Endurance, float Charisma, float Armor) const;
	UFUNCTION(BlueprintNativeEvent)
	float ComputeBlockChance(float Level, float Strength, float Agility, float Precision, float Intelligence, float Wisdom,
					  float Luck, float Constitution, float Endurance, float Charisma, float Armor) const;
	UFUNCTION(BlueprintNativeEvent)
	float ComputeBlockValue(float Level, float Strength, float Agility, float Precision, float Intelligence, float Wisdom,
					  float Luck, float Constitution, float Endurance, float Charisma, float Armor) const;
	UFUNCTION(BlueprintNativeEvent)
	float ComputeGlanceChance(float Level, float Strength, float Agility, float Precision, float Intelligence, float Wisdom,
					  float Luck, float Constitution, float Endurance, float Charisma, float Armor) const;
	UFUNCTION(BlueprintNativeEvent)
	float ComputeEvadeChance(float Level, float Strength, float Agility, float Precision, float Intelligence, float Wisdom,
					  float Luck, float Constitution, float Endurance, float Charisma, float Armor) const;
	UFUNCTION(BlueprintNativeEvent)
	float ComputeParryChance(float Level, float Strength, float Agility, float Precision, float Intelligence, float Wisdom,
					  float Luck, float Constitution, float Endurance, float Charisma, float Armor) const;
	UFUNCTION(BlueprintNativeEvent)
	float ComputeCriticalChance(float Level, float Strength, float Agility, float Precision, float Intelligence, float Wisdom,
					  float Luck, float Constitution, float Endurance, float Charisma, float Armor) const;
	UFUNCTION(BlueprintNativeEvent)
    float ComputeCriticalValue(float Level, float Strength, float Agility, float Precision, float Intelligence, float Wisdom,
    				  float Luck, float Constitution, float Endurance, float Charisma, float Armor) const;
	UFUNCTION(BlueprintNativeEvent)
	float ComputeCriticalDefense(float Level, float Strength, float Agility, float Precision, float Intelligence, float Wisdom,
					  float Luck, float Constitution, float Endurance, float Charisma, float Armor) const;
	UFUNCTION(BlueprintNativeEvent)
	float ComputeAccuracy(float Level, float Strength, float Agility, float Precision, float Intelligence, float Wisdom,
					  float Luck, float Constitution, float Endurance, float Charisma, float Armor) const;
	UFUNCTION(BlueprintNativeEvent)
	float GetAttributeFromGear(FGameplayTag Attribute, const ACharacter * Character) const;
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

	virtual float CalculateAttribute(TObjectPtr<UCurveTable> Table, float Level, float Strength, float Agility, float Precision, float Intelligence, float Wisdom,
					  float Luck, float Constitution, float Endurance, float Charisma, float Armor) const;
protected :
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Level);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Strength);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Agility);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Precision);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Intelligence);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Wisdom);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Luck);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Constitution);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Endurance);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Charisma);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Armor);
	//Primary Attributes	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag StrengthTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag AgilityTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag PrecisionTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag IntelligenceTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag WisdomTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag LuckTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag ConstitutionTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag EnduranceTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag CharismaTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag ArmorTag;
	//Vital Attributes
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> HealthTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag HealthMaxTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> EnergyTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag EnergyMaxTag;
	//Combat Attributes
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> AccuracyTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag AccuracyTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> BlockChanceTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag BlockChanceTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> BlockValueTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag BlockValueTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> GlanceChanceTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag GlanceChanceTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> ParryChanceTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag ParryChanceTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> EvadeChanceTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag EvadeChanceTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> CriticalChanceTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag CriticalChanceTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> CriticalValueTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag CriticalValueTag;
	//Defense Attributes
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> CriticalDefenseTable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag CriticalDefenseTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> Mitigation1Table;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag Mitigation1Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> Mitigation2Table;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag Mitigation2Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> Mitigation3Table;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag Mitigation3Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> Mitigation4Table;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag Mitigation4Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> Resistance1Table;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag Resistance1Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> Resistance2Table;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag Resistance2Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> Resistance3Table;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag Resistance3Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tables)
	TObjectPtr<UCurveTable> Resistance4Table;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Tags)
	FGameplayTag Resistance4Tag;
};





