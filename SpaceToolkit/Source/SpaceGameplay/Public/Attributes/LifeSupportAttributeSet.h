// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Attributes/AttributeSetBase.h"
#include "LifeSupportAttributeSet.generated.h"


SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LifeSupportPowerTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LifeSupportPowerNeedTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(AirQualityTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PurificationRateTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LifeSupportOnTag);

UCLASS()
class SPACEGAMEPLAY_API ULifeSupportAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(ULifeSupportAttributeSet, LifeSupportPower);
	ATTRIBUTE_TAG_ACCESSOR(ULifeSupportAttributeSet, LifeSupportPower);
	ATTRIBUTE_ACCESSORS(ULifeSupportAttributeSet, LifeSupportPowerNeed);
	ATTRIBUTE_TAG_ACCESSOR(ULifeSupportAttributeSet, LifeSupportPowerNeed);
	ATTRIBUTE_ACCESSORS(ULifeSupportAttributeSet, AirQuality);
	ATTRIBUTE_TAG_ACCESSOR(ULifeSupportAttributeSet, AirQuality);
	ATTRIBUTE_ACCESSORS(ULifeSupportAttributeSet, PurificationRate);
	ATTRIBUTE_TAG_ACCESSOR(ULifeSupportAttributeSet, PurificationRate);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LifeSupportPower, Category=LifeSupport)
	FGameplayAttributeData LifeSupportPower;
	UFUNCTION()
	void OnRep_LifeSupportPower(const FGameplayAttributeData& OldLifeSupportPower) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LifeSupport")
	FGameplayAttributeData LifeSupportPowerNeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LifeSupport")
	FGameplayAttributeData PurificationRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_AirQuality, Category=LifeSupport)
	FGameplayAttributeData AirQuality;
	UFUNCTION()
	void OnRep_AirQuality(const FGameplayAttributeData& OldAirQuality) const;
};
