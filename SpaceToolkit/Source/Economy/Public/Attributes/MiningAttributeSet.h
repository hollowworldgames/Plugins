// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeMacros.h"
#include "AbilitySystemComponent.h"
#include "GameplayTags.h"
#include "NativeGameplayTags.h"
#include "Attributes/AttributeSetBase.h"
#include "MiningAttributeSet.generated.h"

ECONOMY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MiningSpeedTag);
ECONOMY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MiningEfficiencyTag);

UCLASS()
class ECONOMY_API UMiningAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UMiningAttributeSet, MiningSpeed);
	ATTRIBUTE_TAG_ACCESSOR(UMiningAttributeSet, MiningSpeed);
	ATTRIBUTE_ACCESSORS(UMiningAttributeSet, MiningEfficiency);
	ATTRIBUTE_TAG_ACCESSOR(UMiningAttributeSet, MiningEfficiency);

	virtual float GetAttributeValue(FGameplayTag AttributeTag);
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value);
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MiningSpeed, Category=Health)
	FGameplayAttributeData MiningSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Mining)
	FGameplayTag MiningSpeedTag = ::MiningSpeedTag;
	UFUNCTION()
	void OnRep_MiningSpeed(const FGameplayAttributeData& OldMiningSpeed) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MiningEfficiency, Category=Health)
	FGameplayAttributeData MiningEfficiency;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Mining)
	FGameplayTag MiningEfficiencyTag = ::MiningSpeedTag;
	UFUNCTION()
	void OnRep_MiningEfficiency(const FGameplayAttributeData& OldMiningEfficiency) const;
};
