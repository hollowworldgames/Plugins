// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSetBase.h"
#include "CombatAttributeSet.h"
#include "Attributes/AttributeTags.h"
#include "RPGCombatAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API URPGCombatAttributeSet : public UCombatAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, HitChance);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, GlancingBlowChance);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, GlancingBlowValue);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, EvadeChance);
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	//Combat Attributes

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HitChance, Category=Combat)
	FGameplayAttributeData HitChance;
	UFUNCTION()
	void OnRep_HitChance(const FGameplayAttributeData& OldHitChance) const;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_GlancingBlowChance, Category=Combat)
	FGameplayAttributeData GlancingBlowChance;

	UFUNCTION()
	void OnRep_GlancingBlowChance(const FGameplayAttributeData& OldGlancingBlowChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_GlancingBlowValue, Category=Combat)
	FGameplayAttributeData GlancingBlowValue;
	UFUNCTION()
	void OnRep_GlancingBlowValue(const FGameplayAttributeData& OldGlancingBlowValue) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EvadeChance, Category=Combat)
	FGameplayAttributeData EvadeChance;
	UFUNCTION()
	void OnRep_EvadeChance(const FGameplayAttributeData& OldEvadeChance) const;
};

UCLASS()
class GAMEPLAY_API URPGMeleeCombatAttributeSet : public URPGCombatAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(URPGMeleeCombatAttributeSet, BlockChance);
	ATTRIBUTE_ACCESSORS(URPGMeleeCombatAttributeSet, BlockValue);
	ATTRIBUTE_ACCESSORS(URPGMeleeCombatAttributeSet, ParryChance);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BlockChance, Category=Combat)
	FGameplayAttributeData BlockChance;
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BlockValue, Category=Combat)
	FGameplayAttributeData BlockValue;
	UFUNCTION()
	void OnRep_BlockValue(const FGameplayAttributeData& OldBlockValue) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ParryChance, Category=Combat)
	FGameplayAttributeData ParryChance;
	UFUNCTION()
	void OnRep_ParryChance(const FGameplayAttributeData& OldParryChance) const;
};
