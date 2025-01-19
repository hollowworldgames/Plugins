// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Attributes/AttributeSetBase.h"
#include "FuelAttributeSet.generated.h"

VEHICLES_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FuelCapacityTag);
VEHICLES_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FuelMaxCapacityTag);

UCLASS()
class VEHICLES_API UFuelAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UFuelAttributeSet, FuelCapacity);
	ATTRIBUTE_TAG_ACCESSOR(UFuelAttributeSet, FuelCapacity);
	ATTRIBUTE_ACCESSORS(UFuelAttributeSet, FuelMaxCapacity);
	ATTRIBUTE_TAG_ACCESSOR(UFuelAttributeSet, FuelMaxCapacity);
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_FuelCapacity, Category = Power)
	FGameplayAttributeData FuelCapacity;

	UFUNCTION()
	void OnRep_FuelCapacity(const FGameplayAttributeData& OldFuelCapacity) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_FuelMaxCapacity, Category = Power)
	FGameplayAttributeData FuelMaxCapacity;

	UFUNCTION()
	void OnRep_FuelMaxCapacity(const FGameplayAttributeData& OldFuelMaxCapacity) const;
};
