// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "Attributes/SpaceGameplayTags.h"
#include "GunnerAttributeSet.generated.h"


UCLASS()
class SPACEGAMEPLAY_API UGunnerAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UGunnerAttributeSet, Accuracy);
	ATTRIBUTE_TAG_ACCESSOR(UGunnerAttributeSet, Accuracy);
	ATTRIBUTE_ACCESSORS(UGunnerAttributeSet, Range);
	ATTRIBUTE_TAG_ACCESSOR(UGunnerAttributeSet, Range);
	ATTRIBUTE_ACCESSORS(UGunnerAttributeSet, FireRate);
	ATTRIBUTE_TAG_ACCESSOR(UGunnerAttributeSet, FireRate);
	ATTRIBUTE_ACCESSORS(UGunnerAttributeSet, Efficiency);
	ATTRIBUTE_TAG_ACCESSOR(UGunnerAttributeSet, Efficiency);
	ATTRIBUTE_ACCESSORS(UGunnerAttributeSet, Reflexes);
	ATTRIBUTE_TAG_ACCESSOR(UGunnerAttributeSet, Reflexes);
	ATTRIBUTE_ACCESSORS(UGunnerAttributeSet, TargetAnalysis);
	ATTRIBUTE_TAG_ACCESSOR(UGunnerAttributeSet, TargetAnalysis);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Range, Category=Gunnery)
	FGameplayAttributeData Range;
	UFUNCTION()
	void OnRep_Range(const FGameplayAttributeData& OldRange) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Accuracy, Category=Gunnery)
	FGameplayAttributeData Accuracy;
	UFUNCTION()
	void OnRep_Accuracy(const FGameplayAttributeData& OldAccuracy) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_FireRate, Category=Gunnery)
	FGameplayAttributeData FireRate;
	UFUNCTION()
	void OnRep_FireRate(const FGameplayAttributeData& OldFireRate) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Efficiency, Category=Gunnery)
	FGameplayAttributeData Efficiency;
	UFUNCTION()
	void OnRep_Efficiency(const FGameplayAttributeData& OldEfficiency) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Reflexes, Category=Gunnery)
	FGameplayAttributeData Reflexes;
	UFUNCTION()
	void OnRep_Reflexes(const FGameplayAttributeData& OldREflexes) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_TargetAnalysis, Category=Gunnery)
	FGameplayAttributeData TargetAnalysis;
	UFUNCTION()
	void OnRep_TargetAnalysis(const FGameplayAttributeData& OldTargetAnalysis) const;
};
