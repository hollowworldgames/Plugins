// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSetBase.h"
#include "Attributes/AttributeTags.h"
#include "RPGCombatAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API URPGCombatAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, DamageBoost1);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, DamageBoost1);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, DamageBoost2);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, DamageBoost2);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, DamageBoost3);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, DamageBoost3);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, DamageBoost4);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, DamageBoost4);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, Mitigation1);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, Mitigation1);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, Mitigation2);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, Mitigation2);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, Mitigation3);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, Mitigation3);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, Mitigation4);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, Mitigation4);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, Resistance1);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, Resistance1);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, Resistance2);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, Resistance2);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, Resistance3);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, Resistance3);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, Resistance4);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, Resistance4);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, HitChance);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, HitChance);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, GlancingBlowChance);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, GlancingBlowChance);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, GlancingBlowValue);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, GlancingBlowValue);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, EvadeChance);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, EvadeChance);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, Penetration);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, Penetration);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, CriticalChance);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, CriticalChance);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, CriticalValue);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, CriticalValue);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, CriticalDefense);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, CriticalDefense);
	ATTRIBUTE_ACCESSORS(URPGCombatAttributeSet, Armor);
	ATTRIBUTE_TAG_ACCESSOR(URPGCombatAttributeSet, Armor);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_DamageBoost1, Category=Damage)
	FGameplayAttributeData DamageBoost1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag DamageBoost1Tag = ::DamageBoost1Tag;
	UFUNCTION()
	void OnRep_DamageBoost1(const FGameplayAttributeData& OldDamageBoost1) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_DamageBoost2, Category=Damage)
	FGameplayAttributeData DamageBoost2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag DamageBoost2Tag = ::DamageBoost2Tag;
	UFUNCTION()
	void OnRep_DamageBoost2(const FGameplayAttributeData& OldDamageBoost1) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_DamageBoost3, Category=Damage)
	FGameplayAttributeData DamageBoost3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag DamageBoost3Tag = ::DamageBoost3Tag;
	UFUNCTION()
	void OnRep_DamageBoost3(const FGameplayAttributeData& OldDamageBoost3) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_DamageBoost4, Category=Damage)
	FGameplayAttributeData DamageBoost4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag DamageBoost4Tag = ::DamageBoost4Tag;
	UFUNCTION()
	void OnRep_DamageBoost4(const FGameplayAttributeData& OldDamageBoost4) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Mitigation1, Category=Damage)
	FGameplayAttributeData Mitigation1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag Mitigation1Tag = ::Mitigation1Tag;
	UFUNCTION()
	void OnRep_Mitigation1(const FGameplayAttributeData& OldMitigation1) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Mitigation2, Category=Damage)
	FGameplayAttributeData Mitigation2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag Mitigation2Tag = ::Mitigation2Tag;
	UFUNCTION()
	void OnRep_Mitigation2(const FGameplayAttributeData& OldMitigation2) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Mitigation3, Category=Damage)
	FGameplayAttributeData Mitigation3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag Mitigation3Tag = ::Mitigation3Tag;
	UFUNCTION()
	void OnRep_Mitigation3(const FGameplayAttributeData& OldMitigation3) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Mitigation4, Category=Damage)
	FGameplayAttributeData Mitigation4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag Mitigation4Tag = ::Mitigation4Tag;
	UFUNCTION()
	void OnRep_Mitigation4(const FGameplayAttributeData& OldMitigation4) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Resistance1, Category=Damage)
	FGameplayAttributeData Resistance1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag Resistance1Tag = ::Resistance1Tag;
	UFUNCTION()
	void OnRep_Resistance1(const FGameplayAttributeData& OldResistance1) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Resistance2, Category=Damage)
	FGameplayAttributeData Resistance2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag Resistance2Tag = ::Resistance2Tag;
	UFUNCTION()
	void OnRep_Resistance2(const FGameplayAttributeData& OldResistance2) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Resistance3, Category=Damage)
	FGameplayAttributeData Resistance3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag Resistance3Tag = ::Resistance3Tag;
	UFUNCTION()
	void OnRep_Resistance3(const FGameplayAttributeData& OldResistance3) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Resistance4, Category=Damage)
	FGameplayAttributeData Resistance4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag Resistance4Tag = ::Resistance4Tag;
	UFUNCTION()
	void OnRep_Resistance4(const FGameplayAttributeData& OldResistance4) const;
	
	//Combat Attributes
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Armor, Category=Combat)
	FGameplayAttributeData Armor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag ArmorTag = ::ArmorTag;
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HitChance, Category=Combat)
	FGameplayAttributeData HitChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag HitChanceTag = ::HitChanceTag;
	UFUNCTION()
	void OnRep_HitChance(const FGameplayAttributeData& OldHitChance) const;
	
	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_GlancingBlowChance, Category=Combat)
	FGameplayAttributeData GlancingBlowChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag GlancingBlowChanceTag = ::GlancingBlowChanceTag;
	UFUNCTION()
	void OnRep_GlancingBlowChance(const FGameplayAttributeData& OldGlancingBlowChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_GlancingBlowValue, Category=Combat)
	FGameplayAttributeData GlancingBlowValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag GlancingBlowValueTag = ::GlancingBlowValueTag;
	UFUNCTION()
	void OnRep_GlancingBlowValue(const FGameplayAttributeData& OldGlancingBlowValue) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EvadeChance, Category=Combat)
	FGameplayAttributeData EvadeChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag EvadeChanceTag = ::EvadeChanceTag;
	UFUNCTION()
	void OnRep_EvadeChance(const FGameplayAttributeData& OldEvadeChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Penetration, Category=Combat)
	FGameplayAttributeData Penetration;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag PenetrationTag = ::PenetrationTag;
	UFUNCTION()
	void OnRep_Penetration(const FGameplayAttributeData& OldPenetration) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_PenetrationValue, Category=Combat)
	FGameplayAttributeData PenetrationValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag PenetrationValueTag = ::PenetrationValueTag;
	UFUNCTION()
	void OnRep_PenetrationValue(const FGameplayAttributeData& OldPenetrationValue) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CriticalChance, Category=Combat)
	FGameplayAttributeData CriticalChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag CriticalChanceTag = ::CriticalChanceTag;
	UFUNCTION()
	void OnRep_CriticalChance(const FGameplayAttributeData& OldCriticalChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CriticalValue, Category=Combat)
	FGameplayAttributeData CriticalValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag CriticalValueTag = ::CriticalValueTag;
	UFUNCTION()
	void OnRep_CriticalValue(const FGameplayAttributeData& OldCriticalValue) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CriticalDefense, Category=Combat)
	FGameplayAttributeData CriticalDefense;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag CriticalDefenseTag = ::CriticalDefenseTag;
	UFUNCTION()
	void OnRep_CriticalDefense(const FGameplayAttributeData& OldCriticalDefense) const;
};

UCLASS()
class URPGMeleeCombatAttributeSet : public URPGCombatAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(URPGMeleeCombatAttributeSet, BlockChance);
	ATTRIBUTE_TAG_ACCESSOR(URPGMeleeCombatAttributeSet, BlockChance);
	ATTRIBUTE_ACCESSORS(URPGMeleeCombatAttributeSet, BlockValue);
	ATTRIBUTE_TAG_ACCESSOR(URPGMeleeCombatAttributeSet, BlockValue);
	ATTRIBUTE_ACCESSORS(URPGMeleeCombatAttributeSet, ParryChance);
	ATTRIBUTE_TAG_ACCESSOR(URPGMeleeCombatAttributeSet, ParryChance);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BlockChance, Category=Combat)
	FGameplayAttributeData BlockChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag BlockChanceTag = ::BlockChanceTag;
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BlockValue, Category=Combat)
	FGameplayAttributeData BlockValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag BlockValueTag = BlockValueTag;
	UFUNCTION()
	void OnRep_BlockValue(const FGameplayAttributeData& OldBlockValue) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ParryChance, Category=Combat)
	FGameplayAttributeData ParryChance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayTag ParryChanceTag = ParryChanceTag;
	UFUNCTION()
	void OnRep_ParryChance(const FGameplayAttributeData& OldParryChance) const;
};
