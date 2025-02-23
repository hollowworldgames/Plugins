// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSetBase.h"
#include "AttributeTags.h"
#include "CombatAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API UCombatAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, Penetration);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, PenetrationValue);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, CriticalChance);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, CriticalValue);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, CriticalDefense);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, Armor);
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Armor, Category=Combat)
	FGameplayAttributeData Armor;
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Penetration, Category=Combat)
	FGameplayAttributeData Penetration;

	UFUNCTION()
	void OnRep_Penetration(const FGameplayAttributeData& OldPenetration) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_PenetrationValue, Category=Combat)
	FGameplayAttributeData PenetrationValue;

	UFUNCTION()
	void OnRep_PenetrationValue(const FGameplayAttributeData& OldPenetrationValue) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CriticalChance, Category=Combat)
	FGameplayAttributeData CriticalChance;

	UFUNCTION()
	void OnRep_CriticalChance(const FGameplayAttributeData& OldCriticalChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CriticalValue, Category=Combat)
	FGameplayAttributeData CriticalValue;

	UFUNCTION()
	void OnRep_CriticalValue(const FGameplayAttributeData& OldCriticalValue) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CriticalDefense, Category=Combat)
	FGameplayAttributeData CriticalDefense;

	UFUNCTION()
	void OnRep_CriticalDefense(const FGameplayAttributeData& OldCriticalDefense) const;
};
