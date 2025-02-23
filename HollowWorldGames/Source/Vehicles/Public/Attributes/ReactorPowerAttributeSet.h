// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PowerAttributeSet.h"
#include "ReactorPowerAttributeSet.generated.h"


VEHICLES_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ReactorFuelAvailableTag);

UCLASS()
class VEHICLES_API UReactorPowerAttributeSet : public UPowerAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UReactorPowerAttributeSet, ReactorFuelAvailable)
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_ReactorFuelAvailable, Category = Fuel)
	FGameplayAttributeData ReactorFuelAvailable;

	UFUNCTION()
	void OnRep_ReactorFuelAvailable(const FGameplayAttributeData& OldPowerMaxGenerated) const;
};
