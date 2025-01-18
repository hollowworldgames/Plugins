// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "PowerAttributeSet.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(PowerGeneratedTag);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(PowerMaxGeneratedTag);

UCLASS()
class VEHICLES_API UPowerAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UPowerAttributeSet, PowerGenerated);
	ATTRIBUTE_TAG_ACCESSOR(UPowerAttributeSet, PowerGenerated);
	ATTRIBUTE_ACCESSORS(UPowerAttributeSet, PowerMaxGenerated);
	ATTRIBUTE_TAG_ACCESSOR(UPowerAttributeSet, PowerMaxGenerated);
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_PowerGenerated, Category = Power)
	FGameplayAttributeData PowerGenerated;

	UFUNCTION()
	void OnRep_PowerGenerated(const FGameplayAttributeData& OldPowerGenerated) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_PowerMaxGenerated, Category = Power)
	FGameplayAttributeData PowerMaxGenerated;

	UFUNCTION()
	void OnRep_PowerMaxGenerated(const FGameplayAttributeData& OldPowerMaxGenerated) const;
};
