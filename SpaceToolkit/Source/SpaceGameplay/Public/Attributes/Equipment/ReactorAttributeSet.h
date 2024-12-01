// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "NativeGameplayTags.h"
#include "Attributes/AttributeSetBase.h"
#include "Attributes/SpaceGameplayTags.h"
#include "ReactorAttributeSet.generated.h"

UCLASS()
class SPACEGAMEPLAY_API UReactorAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UReactorAttributeSet, PowerOutput);
	ATTRIBUTE_TAG_ACCESSOR(UReactorAttributeSet, PowerOutput);
	ATTRIBUTE_ACCESSORS(UReactorAttributeSet, FuelAvailable);
	ATTRIBUTE_TAG_ACCESSOR(UReactorAttributeSet, FuelAvailable);
	ATTRIBUTE_ACCESSORS(UReactorAttributeSet, FuelNeeded);
	ATTRIBUTE_TAG_ACCESSOR(UReactorAttributeSet, FuelNeeded);
	ATTRIBUTE_ACCESSORS(UReactorAttributeSet, MaxPowerOutput);
	ATTRIBUTE_TAG_ACCESSOR(UReactorAttributeSet, MaxPowerOutput);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_PowerOutput, Category=Reactor)
	FGameplayAttributeData PowerOutput;
	UFUNCTION()
	void OnRep_PowerOutput(const FGameplayAttributeData& OldPowerOutput) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Fuel)
	FGameplayAttributeData MaxPowerOutput;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Fuel)
	FGameplayAttributeData FuelAvailable;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Fuel)
	FGameplayAttributeData FuelNeeded;
};
