// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "NativeGameplayTags.h"
#include "Attributes/AttributeSetBase.h"
#include "Attributes/SpaceGameplayTags.h"
#include "BatteryAttributeSet.generated.h"



UCLASS()
class SPACEGAMEPLAY_API UBatteryAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UBatteryAttributeSet, PowerCapacity);
	ATTRIBUTE_TAG_ACCESSOR(UBatteryAttributeSet, PowerCapacity);
	ATTRIBUTE_ACCESSORS(UBatteryAttributeSet, StoredPower);
	ATTRIBUTE_TAG_ACCESSOR(UBatteryAttributeSet, StoredPower);
	ATTRIBUTE_ACCESSORS(UBatteryAttributeSet, BatteryPower);
	ATTRIBUTE_TAG_ACCESSOR(UBatteryAttributeSet, BatteryPower);
	ATTRIBUTE_ACCESSORS(UBatteryAttributeSet, BatteryDistribution);
	ATTRIBUTE_TAG_ACCESSOR(UBatteryAttributeSet, BatteryDistribution);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_PowerCapacity, Category=Battery)
	FGameplayAttributeData PowerCapacity;
	UFUNCTION()
	void OnRep_PowerCapacity(const FGameplayAttributeData& OldPowerCapacity) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_StoredPower, Category=Battery)
	FGameplayAttributeData StoredPower;
	UFUNCTION()
	void OnRep_StoredPower(const FGameplayAttributeData& OldStoredPower) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Power)
	FGameplayAttributeData BatteryPower;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Power)
	FGameplayAttributeData BatteryDistribution;
};
