// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "AttributeSet.h"
#include "NativeGameplayTags.h"
#include "Attributes/AttributeSetBase.h"
#include "ConstructionAttributeSet.generated.h"

ECONOMY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ConstructionSpeedTag);
ECONOMY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ConstructionEfficiencyTag);

UCLASS()
class ECONOMY_API UConstructionAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UConstructionAttributeSet, ConstructionSpeed);
	ATTRIBUTE_TAG_ACCESSOR(UConstructionAttributeSet, ConstructionSpeed);
	ATTRIBUTE_ACCESSORS(UConstructionAttributeSet, ConstructionEfficiency);
	ATTRIBUTE_TAG_ACCESSOR(UConstructionAttributeSet, ConstructionEfficiency);

	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	protected :
		virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ConstructionSpeed, Category=Health)
	FGameplayAttributeData ConstructionSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Construction)
	FGameplayTag ConstructionSpeedTag = ::ConstructionSpeedTag;
	UFUNCTION()
	void OnRep_ConstructionSpeed(const FGameplayAttributeData& OldConstructionSpeed) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ConstructionEfficiency, Category=Health)
	FGameplayAttributeData ConstructionEfficiency;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Construction)
	FGameplayTag ConstructionEfficiencyTag = ::ConstructionSpeedTag;
	UFUNCTION()
	void OnRep_ConstructionEfficiency(const FGameplayAttributeData& OldConstructionEfficiency) const;
};
