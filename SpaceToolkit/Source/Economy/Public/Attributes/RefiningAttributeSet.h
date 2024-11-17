// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "AttributeSet.h"
#include "NativeGameplayTags.h"
#include "Attributes/AttributeSetBase.h"
#include "RefiningAttributeSet.generated.h"

ECONOMY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RefiningSpeedTag);
ECONOMY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RefiningEfficiencyTag);
ECONOMY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RefiningQualityTag);

UCLASS()
class ECONOMY_API URefiningAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(URefiningAttributeSet, RefiningSpeed);
	ATTRIBUTE_TAG_ACCESSOR(URefiningAttributeSet, RefiningSpeed);
	ATTRIBUTE_ACCESSORS(URefiningAttributeSet, RefiningEfficiency);
	ATTRIBUTE_TAG_ACCESSOR(URefiningAttributeSet, RefiningEfficiency);
	ATTRIBUTE_ACCESSORS(URefiningAttributeSet, RefiningQuality);
	ATTRIBUTE_TAG_ACCESSOR(URefiningAttributeSet, RefiningQuality);

	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RefiningSpeed, Category=Health)
	FGameplayAttributeData RefiningSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Refining)
	FGameplayTag RefiningSpeedTag = ::RefiningSpeedTag;
	UFUNCTION()
	void OnRep_RefiningSpeed(const FGameplayAttributeData& OldRefiningSpeed) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RefiningEfficiency, Category=Health)
	FGameplayAttributeData RefiningEfficiency;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Refining)
	FGameplayTag RefiningEfficiencyTag = ::RefiningEfficiencyTag;
	UFUNCTION()
	void OnRep_RefiningEfficiency(const FGameplayAttributeData& OldRefiningEfficiency) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RefiningQuality, Category=Health)
	FGameplayAttributeData RefiningQuality;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Refining)
	FGameplayTag RefiningQualityTag = ::RefiningQualityTag;
	UFUNCTION()
	void OnRep_RefiningQuality(const FGameplayAttributeData& OldRefiningQuality) const;
};
