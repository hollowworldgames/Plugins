// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "Attributes/AttributeSetBase.h"
#include "Attributes/SpaceGameplayTags.h"
#include "SensorAttributeSet.generated.h"

UCLASS()
class SPACEGAMEPLAY_API USensorAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(USensorAttributeSet, SensorStrength);
	ATTRIBUTE_TAG_ACCESSOR(USensorAttributeSet, SensorStrength);
	ATTRIBUTE_ACCESSORS(USensorAttributeSet, SensorResolution);
	ATTRIBUTE_TAG_ACCESSOR(USensorAttributeSet, SensorResolution);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_SensorStrength, Category=Sensor)
	FGameplayAttributeData SensorStrength;
	
	UFUNCTION()
	void OnRep_SensorStrength(const FGameplayAttributeData& OldSensorStrength) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_SensorResolution, Category=Sensor)
	FGameplayAttributeData SensorResolution;
	
	UFUNCTION()
	void OnRep_SensorResolution(const FGameplayAttributeData& OldSensorResolution) const;
};
