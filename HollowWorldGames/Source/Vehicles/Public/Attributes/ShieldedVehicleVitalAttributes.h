// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "ShieldedVehicleVitalAttributes.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(FuselageHealthTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(FuselageMaxHealthTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(ForwardShieldHealthTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(ForwardShieldMaxHealthTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(RearShieldHealthTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(RearShieldMaxHealthTag);

UCLASS()
class VEHICLES_API UShieldedVehicleVitalAttributes : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, FuselageHealth);
	ATTRIBUTE_TAG_ACCESSOR(UShieldedVehicleVitalAttributes, FuselageHealth);
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, FuselageMaxHealth);
	ATTRIBUTE_TAG_ACCESSOR(UShieldedVehicleVitalAttributes, FuselageMaxHealth);
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, IncomingFuselageDamage);

	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, ForwardShieldHealth);
	ATTRIBUTE_TAG_ACCESSOR(UShieldedVehicleVitalAttributes, ForwardShieldHealth);
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, ForwardShieldMaxHealth);
	ATTRIBUTE_TAG_ACCESSOR(UShieldedVehicleVitalAttributes, ForwardShieldMaxHealth);
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, IncomingForwardShieldDamage);
	
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, RearShieldHealth);
	ATTRIBUTE_TAG_ACCESSOR(UShieldedVehicleVitalAttributes, RearShieldHealth);
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, RearShieldMaxHealth);
	ATTRIBUTE_TAG_ACCESSOR(UShieldedVehicleVitalAttributes, RearShieldMaxHealth);
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, IncomingRearShieldDamage);
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	//Fuselage
	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_FuselageHealth, Category = VitalAttributes)
	FGameplayAttributeData FuselageHealth;

	UFUNCTION()
	void OnRep_FuselageHealth(const FGameplayAttributeData& OldFuselageHealth) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_FuselageMaxHealth, Category = VitalAttributes)
	FGameplayAttributeData FuselageMaxHealth;

	UFUNCTION()
	void OnRep_FuselageMaxHealth(const FGameplayAttributeData& OldFuselageMaxHealth) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
	FGameplayAttributeData IncomingFuselageDamage;
    //Shield
	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_ForwardShieldHealth, Category = Shields)
	FGameplayAttributeData ForwardShieldHealth;

	UFUNCTION()
	void OnRep_ForwardShieldHealth(const FGameplayAttributeData& OldForwardShieldHealth) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_ForwardShieldMaxHealth, Category = Shields)
	FGameplayAttributeData ForwardShieldMaxHealth;

	UFUNCTION()
	void OnRep_ForwardShieldMaxHealth(const FGameplayAttributeData& OldForwardShieldMaxHealth) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
	FGameplayAttributeData IncomingForwardShieldDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_RearShieldHealth, Category = Shields)
	FGameplayAttributeData RearShieldHealth;

	UFUNCTION()
	void OnRep_RearShieldHealth(const FGameplayAttributeData& OldRearShieldHealth) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_RearShieldMaxHealth, Category = Shields)
	FGameplayAttributeData RearShieldMaxHealth;

	UFUNCTION()
	void OnRep_RearShieldMaxHealth(const FGameplayAttributeData& OldRearShieldMaxHealth) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
	FGameplayAttributeData IncomingRearShieldDamage;
};
