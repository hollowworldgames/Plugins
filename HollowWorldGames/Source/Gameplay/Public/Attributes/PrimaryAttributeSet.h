// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSetBase.h"
#include "AttributeTags.h"
#include "PrimaryAttributeSet.generated.h"



UCLASS()
class GAMEPLAY_API UPrimaryAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UPrimaryAttributeSet, Strength);
	ATTRIBUTE_TAG_ACCESSOR(UPrimaryAttributeSet, Strength);
	ATTRIBUTE_ACCESSORS(UPrimaryAttributeSet, Agility);
	ATTRIBUTE_TAG_ACCESSOR(UPrimaryAttributeSet, Agility);
	ATTRIBUTE_ACCESSORS(UPrimaryAttributeSet, Precision);
	ATTRIBUTE_TAG_ACCESSOR(UPrimaryAttributeSet, Precision);
	ATTRIBUTE_ACCESSORS(UPrimaryAttributeSet, Intelligence);
	ATTRIBUTE_TAG_ACCESSOR(UPrimaryAttributeSet, Intelligence);
	ATTRIBUTE_ACCESSORS(UPrimaryAttributeSet, Wisdom);
	ATTRIBUTE_TAG_ACCESSOR(UPrimaryAttributeSet, Wisdom);
	ATTRIBUTE_ACCESSORS(UPrimaryAttributeSet, Luck);
	ATTRIBUTE_TAG_ACCESSOR(UPrimaryAttributeSet, Luck);
	ATTRIBUTE_ACCESSORS(UPrimaryAttributeSet, Constitution);
	ATTRIBUTE_TAG_ACCESSOR(UPrimaryAttributeSet, Constitution);
	ATTRIBUTE_ACCESSORS(UPrimaryAttributeSet, Endurance);
	ATTRIBUTE_TAG_ACCESSOR(UPrimaryAttributeSet, Endurance);
	ATTRIBUTE_ACCESSORS(UPrimaryAttributeSet, Charisma);
	ATTRIBUTE_TAG_ACCESSOR(UPrimaryAttributeSet, Charisma);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Strength, Category=Primary)
	FGameplayAttributeData Strength;
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Agility, Category=Attributes)
	FGameplayAttributeData Agility;
	UFUNCTION()
	void OnRep_Agility(const FGameplayAttributeData& OldAgility) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Precision, Category=Attributes)
	FGameplayAttributeData Precision;
	UFUNCTION()
	void OnRep_Precision(const FGameplayAttributeData& OldPrecision) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Luck, Category=Attributes)
	FGameplayAttributeData Luck;
	UFUNCTION()
	void OnRep_Luck(const FGameplayAttributeData& OldLuck) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Intelligence, Category=Attributes)
	FGameplayAttributeData Intelligence;
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Wisdom, Category=Attributes)
	FGameplayAttributeData Wisdom;
	UFUNCTION()
	void OnRep_Wisdom(const FGameplayAttributeData& OldWisdom) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Constitution, Category=Attributes)
	FGameplayAttributeData Constitution;
	UFUNCTION()
	void OnRep_Constitution(const FGameplayAttributeData& OldConstitution) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Endurance, Category=Attributes)
	FGameplayAttributeData Endurance;
	UFUNCTION()
	void OnRep_Endurance(const FGameplayAttributeData& OldEndurance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Charisma, Category=Attributes)
	FGameplayAttributeData Charisma;
	UFUNCTION()
	void OnRep_Charisma(const FGameplayAttributeData& OldCharisma) const;
};
