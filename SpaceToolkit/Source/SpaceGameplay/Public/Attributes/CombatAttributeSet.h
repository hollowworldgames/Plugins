// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpaceGameplayTags.h"
#include "Attributes/AttributeSetBase.h"
#include "CombatAttributeSet.generated.h"


UCLASS()
class SPACEGAMEPLAY_API UCombatAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, HitChance);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, HitChance);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, EvadeChance);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, EvadeChance);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, GlanceChance);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, GlanceChance);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, GlanceValue);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, GlanceValue);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, KineticMitigation);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, KineticMitigation);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, EnergyMitigation);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, EnergyMitigation);

	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, CriticalChance);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, CriticalChance);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, CriticalDamage);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, CriticalDamage);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, CriticalDefense);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, CriticalDefense);

	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, FrontShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, FrontShield);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, MaxFrontShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, MaxFrontShield);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, FrontKineticMitigation);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, FrontKineticMitigation);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, FrontEnergyMitigation);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, FrontEnergyMitigation);

	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, BackShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, BackShield);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, MaxBackShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, MaxBackShield);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, BackKineticMitigation);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, BackKineticMitigation);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, BackEnergyMitigation);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, BackEnergyMitigation);

	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, RightShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, RightShield);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, MaxRightShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, MaxRightShield);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, RightKineticMitigation);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, RightKineticMitigation);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, RightEnergyMitigation);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, RightEnergyMitigation);

	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, LeftShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, LeftShield);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, MaxLeftShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, MaxLeftShield);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, LeftKineticMitigation);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, LeftKineticMitigation);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, LeftEnergyMitigation);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, LeftEnergyMitigation);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, ShieldFaces);	
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, IncomingFrontEnergyDamage);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, IncomingFrontEnergyDamage);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, IncomingFrontKineticDamage);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, IncomingFrontKineticDamage);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, IncomingBackEnergyDamage);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, IncomingBackEnergyDamage);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, IncomingBackKineticDamage);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, IncomingBackKineticDamage);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, IncomingRightEnergyDamage);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, IncomingRightEnergyDamage);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, IncomingRightKineticDamage);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, IncomingRightKineticDamage);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, IncomingLeftEnergyDamage);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, IncomingLeftEnergyDamage);
	ATTRIBUTE_ACCESSORS(UCombatAttributeSet, IncomingLeftKineticDamage);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, IncomingLeftKineticDamage);
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HitChance, Category=Combat)
	FGameplayAttributeData HitChance;
	UFUNCTION()
	void OnRep_HitChance(const FGameplayAttributeData& OldHitChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EvadeChance, Category=Combat)
	FGameplayAttributeData EvadeChance;
	UFUNCTION()
	void OnRep_EvadeChance(const FGameplayAttributeData& OldEvadeChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_GlanceChance, Category=Combat)
	FGameplayAttributeData GlanceChance;
	UFUNCTION()
	void OnRep_GlanceChance(const FGameplayAttributeData& OldGlanceChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_GlanceValue, Category=Combat)
	FGameplayAttributeData GlanceValue;
	UFUNCTION()
	void OnRep_GlanceValue(const FGameplayAttributeData& OldGlanceValue) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_KineticMitigation, Category=Combat)
	FGameplayAttributeData KineticMitigation;
	UFUNCTION()
	void OnRep_KineticMitigation(const FGameplayAttributeData& OldKineticMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EnergyMitigation, Category=Combat)
	FGameplayAttributeData EnergyMitigation;
	UFUNCTION()
	void OnRep_EnergyMitigation(const FGameplayAttributeData& OldEnergyMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CriticalChance, Category=Combat)
	FGameplayAttributeData CriticalChance;
	UFUNCTION()
	void OnRep_CriticalChance(const FGameplayAttributeData& OldCriticalChance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CriticalDamage, Category=Combat)
	FGameplayAttributeData CriticalDamage;
	UFUNCTION()
	void OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_CriticalDefense, Category=Combat)
	FGameplayAttributeData CriticalDefense;
	UFUNCTION()
	void OnRep_CriticalDefense(const FGameplayAttributeData& OldCriticalDefense) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_FrontShield, Category=Combat)
	FGameplayAttributeData FrontShield;
	UFUNCTION()
	void OnRep_FrontShield(const FGameplayAttributeData& OldFrontShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxFrontShield, Category=Combat)
	FGameplayAttributeData MaxFrontShield;
	UFUNCTION()
	void OnRep_MaxFrontShield(const FGameplayAttributeData& OldMaxFrontShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_FrontKineticMitigation, Category=Combat)
	FGameplayAttributeData FrontKineticMitigation;
	UFUNCTION()
	void OnRep_FrontKineticMitigation(const FGameplayAttributeData& OldFrontKineticMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_FrontEnergyMitigation, Category=Combat)
	FGameplayAttributeData FrontEnergyMitigation;
	UFUNCTION()
	void OnRep_FrontEnergyMitigation(const FGameplayAttributeData& OldFrontEnergyMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BackShield, Category=Combat)
	FGameplayAttributeData BackShield;
	UFUNCTION()
	void OnRep_BackShield(const FGameplayAttributeData& OldBackShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxBackShield, Category=Combat)
	FGameplayAttributeData MaxBackShield;
	UFUNCTION()
	void OnRep_MaxBackShield(const FGameplayAttributeData& OldMaxBackShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BackKineticMitigation, Category=Combat)
	FGameplayAttributeData BackKineticMitigation;
	UFUNCTION()
	void OnRep_BackKineticMitigation(const FGameplayAttributeData& OldBackKineticMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BackEnergyMitigation, Category=Combat)
	FGameplayAttributeData BackEnergyMitigation;
	UFUNCTION()
	void OnRep_BackEnergyMitigation(const FGameplayAttributeData& OldBackEnergyMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RightShield, Category=Combat)
	FGameplayAttributeData RightShield;
	UFUNCTION()
	void OnRep_RightShield(const FGameplayAttributeData& OldRightShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxRightShield, Category=Combat)
	FGameplayAttributeData MaxRightShield;
	UFUNCTION()
	void OnRep_MaxRightShield(const FGameplayAttributeData& OldMaxRightShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RightKineticMitigation, Category=Combat)
	FGameplayAttributeData RightKineticMitigation;
	UFUNCTION()
	void OnRep_RightKineticMitigation(const FGameplayAttributeData& OldRightKineticMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RightEnergyMitigation, Category=Combat)
	FGameplayAttributeData RightEnergyMitigation;
	UFUNCTION()
	void OnRep_RightEnergyMitigation(const FGameplayAttributeData& OldRightEnergyMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LeftShield, Category=Combat)
	FGameplayAttributeData LeftShield;
	UFUNCTION()
	void OnRep_LeftShield(const FGameplayAttributeData& OldLeftShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxLeftShield, Category=Combat)
	FGameplayAttributeData MaxLeftShield;
	UFUNCTION()
	void OnRep_MaxLeftShield(const FGameplayAttributeData& OldMaxLeftShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldFaces, Category=Combat)
	FGameplayAttributeData ShieldFaces;
	UFUNCTION()
	void OnRep_ShieldFaces(const FGameplayAttributeData& OldShieldFaces) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LeftKineticMitigation, Category=Combat)
	FGameplayAttributeData LeftKineticMitigation;
	UFUNCTION()
	void OnRep_LeftKineticMitigation(const FGameplayAttributeData& OldLeftKineticMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LeftEnergyMitigation, Category=Combat)
	FGameplayAttributeData LeftEnergyMitigation;
	UFUNCTION()
	void OnRep_LeftEnergyMitigation(const FGameplayAttributeData& OldLeftEnergyMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingFrontKineticDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingFrontEnergyDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingBackKineticDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingBackEnergyDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingRightKineticDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingRightEnergyDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingLeftKineticDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingLeftEnergyDamage;
};
