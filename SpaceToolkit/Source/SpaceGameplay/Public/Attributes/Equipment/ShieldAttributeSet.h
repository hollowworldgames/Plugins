// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "AbilitySystemComponent.h"
#include "Attributes/AttributeSetBase.h"
#include "Attributes/SpaceGameplayTags.h"
#include "ShieldAttributeSet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShieldDead);

UCLASS()
class SPACEGAMEPLAY_API UShieldAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UShieldAttributeSet, ShieldPower);
	ATTRIBUTE_TAG_ACCESSOR(UShieldAttributeSet, ShieldPower);
	ATTRIBUTE_ACCESSORS(UShieldAttributeSet, ShieldDistribution);
	ATTRIBUTE_TAG_ACCESSOR(UShieldAttributeSet, ShieldDistribution);
	ATTRIBUTE_ACCESSORS(UShieldAttributeSet, PowerToHitPoints);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldDistribution, Category=Power)
	FGameplayAttributeData ShieldDistribution;
	UFUNCTION()
	void OnRep_ShieldDistribution(const FGameplayAttributeData& OldShieldDistribution) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldPower, Category=Power)
	FGameplayAttributeData ShieldPower;
	UFUNCTION()
	void OnRep_ShieldPower(const FGameplayAttributeData& OldShieldPower) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Power)
	FGameplayAttributeData PowerToHitPoints;
};
