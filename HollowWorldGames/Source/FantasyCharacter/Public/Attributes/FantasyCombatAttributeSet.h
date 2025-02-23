// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "Attributes/RPGCombatAttributeSet.h"
#include "FantasyCombatAttributeSet.generated.h"

FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PhysicalMitigationTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ElementalMitigationTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MagicalMitigationTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PhysicalDamageTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ElementalDamageTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MagicalDamageTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PhysicalResistanceTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ElementalResistanceTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MagicalResistanceTag);

FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PhysicalTypeTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ElementalTypeTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MagicalTypeTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PhysicalBoostTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ElementalBoostTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MagicalBoostTag);

UCLASS()
class FANTASYCHARACTER_API UFantasyCombatAttributeSet : public URPGMeleeCombatAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UFantasyCombatAttributeSet, PhysicalMitigation);
	ATTRIBUTE_ACCESSORS(UFantasyCombatAttributeSet, ElementalMitigation);
	ATTRIBUTE_ACCESSORS(UFantasyCombatAttributeSet, MagicalMitigation);
	ATTRIBUTE_ACCESSORS(UFantasyCombatAttributeSet, PhysicalResistance);
	ATTRIBUTE_ACCESSORS(UFantasyCombatAttributeSet, ElementalResistance);
	ATTRIBUTE_ACCESSORS(UFantasyCombatAttributeSet, MagicalResistance);
	ATTRIBUTE_ACCESSORS(UFantasyCombatAttributeSet, PhysicalDamage);
	ATTRIBUTE_ACCESSORS(UFantasyCombatAttributeSet, ElementalDamage);
	ATTRIBUTE_ACCESSORS(UFantasyCombatAttributeSet, MagicalDamage);
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_PhysicalMitigation, Category=Combat)
	FGameplayAttributeData PhysicalMitigation;
	
	UFUNCTION()
	void OnRep_PhysicalMitigation(const FGameplayAttributeData& OldPhysicalMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ElementalMitigation, Category=Combat)
	FGameplayAttributeData ElementalMitigation;
	
	UFUNCTION()
	void OnRep_ElementalMitigation(const FGameplayAttributeData& OldElementalMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MagicalMitigation, Category=Combat)
	FGameplayAttributeData MagicalMitigation;
	
	UFUNCTION()
	void OnRep_MagicalMitigation(const FGameplayAttributeData& OldMagicalMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_PhysicalDamage, Category=Combat)
	FGameplayAttributeData PhysicalDamage;
	
	UFUNCTION()
	void OnRep_PhysicalDamage(const FGameplayAttributeData& OldPhysicalDamage) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ElementalDamage, Category=Combat)
	FGameplayAttributeData ElementalDamage;
	
	UFUNCTION()
	void OnRep_ElementalDamage(const FGameplayAttributeData& OldElementalDamage) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MagicalDamage, Category=Combat)
	FGameplayAttributeData MagicalDamage;
	
	UFUNCTION()
	void OnRep_MagicalDamage(const FGameplayAttributeData& OldMagicalDamage) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_PhysicalResistance, Category=Combat)
	FGameplayAttributeData PhysicalResistance;
	
	UFUNCTION()
	void OnRep_PhysicalResistance(const FGameplayAttributeData& OldPhysicalResistance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ElementalResistance, Category=Combat)
	FGameplayAttributeData ElementalResistance;
	
	UFUNCTION()
	void OnRep_ElementalResistance(const FGameplayAttributeData& OldElementalResistance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MagicalResistance, Category=Combat)
	FGameplayAttributeData MagicalResistance;

	UFUNCTION()
	void OnRep_MagicalResistance(const FGameplayAttributeData& OldMagicalResistance) const;
};
