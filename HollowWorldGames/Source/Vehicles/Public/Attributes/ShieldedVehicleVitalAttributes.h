// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "ShieldedVehicleVitalAttributes.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(FuselageHealthTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(FuselageMaxHealthTag);

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
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

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
};
