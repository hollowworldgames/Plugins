// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "ShieldedVehicleVitalAttributes.generated.h"

VEHICLES_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FuselageHealthTag);
VEHICLES_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FuselageMaxHealthTag);
VEHICLES_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ForwardShieldHealthTag);
VEHICLES_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ForwardShieldMaxHealthTag);
VEHICLES_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RearShieldHealthTag);
VEHICLES_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RearShieldMaxHealthTag);

UCLASS()
class VEHICLES_API UShieldedVehicleVitalAttributes : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, FuselageHealth);
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, FuselageMaxHealth);
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, IncomingFuselageDamage);

	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, ForwardShieldHealth);
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, ForwardShieldMaxHealth);
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, IncomingForwardShieldDamage);
	
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, RearShieldHealth);
	ATTRIBUTE_ACCESSORS(UShieldedVehicleVitalAttributes, RearShieldMaxHealth);
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
