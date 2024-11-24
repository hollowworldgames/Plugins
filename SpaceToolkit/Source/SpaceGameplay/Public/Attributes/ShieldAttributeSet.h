// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "NativeGameplayTags.h"
#include "AbilitySystemComponent.h"
#include "Attributes/AttributeSetBase.h"
#include "ShieldAttributeSet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShieldDead);

SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ShieldFrontHitPointsTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ShieldMaxFrontHitPointsTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ShieldBackHitPointsTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ShieldMaxBackHitPointsTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ShieldPowerTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ShieldDistributionTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ShieldOnTag);

UCLASS()
class SPACEGAMEPLAY_API UShieldAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UShieldAttributeSet, ShieldFrontHitPoints);
	ATTRIBUTE_TAG_ACCESSOR(UShieldAttributeSet, ShieldFrontHitPoints);
	ATTRIBUTE_ACCESSORS(UShieldAttributeSet, ShieldMaxFrontHitPoints);
	ATTRIBUTE_TAG_ACCESSOR(UShieldAttributeSet, ShieldMaxFrontHitPoints);
	ATTRIBUTE_ACCESSORS(UShieldAttributeSet, ShieldBackHitPoints);
	ATTRIBUTE_TAG_ACCESSOR(UShieldAttributeSet, ShieldBackHitPoints);
	ATTRIBUTE_ACCESSORS(UShieldAttributeSet, ShieldMaxBackHitPoints);
	ATTRIBUTE_TAG_ACCESSOR(UShieldAttributeSet, ShieldMaxBackHitPoints);
	ATTRIBUTE_ACCESSORS(UShieldAttributeSet, ShieldIncomingFrontDamage);
	ATTRIBUTE_ACCESSORS(UShieldAttributeSet, ShieldIncomingBackDamage);
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
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldFrontHitPoints, Category=Shield)
	FGameplayAttributeData ShieldFrontHitPoints;
	UFUNCTION()
	void OnRep_ShieldFrontHitPoints(const FGameplayAttributeData& OldFrontShieldHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldMaxFrontHitPoints, Category=Shield)
	FGameplayAttributeData ShieldMaxFrontHitPoints;
	UFUNCTION()
	void OnRep_ShieldMaxFrontHitPoints(const FGameplayAttributeData& OldShieldMaxFrontHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldBackHitPoints, Category=Shield)
	FGameplayAttributeData ShieldBackHitPoints;
	UFUNCTION()
	void OnRep_ShieldBackHitPoints(const FGameplayAttributeData& OldBackShieldHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldMaxBackHitPoints, Category=Shield)
	FGameplayAttributeData ShieldMaxBackHitPoints;
	UFUNCTION()
	void OnRep_ShieldMaxBackHitPoints(const FGameplayAttributeData& OldShieldMaxBackHealth) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldDistribution, Category=Power)
	FGameplayAttributeData ShieldDistribution;
	UFUNCTION()
	void OnRep_ShieldDistribution(const FGameplayAttributeData& OldShieldDistribution) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldPower, Category=Power)
	FGameplayAttributeData ShieldPower;
	UFUNCTION()
	void OnRep_ShieldPower(const FGameplayAttributeData& OldShieldPower) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData ShieldIncomingFrontDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayAttributeData ShieldIncomingBackDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Power)
	FGameplayAttributeData PowerToHitPoints;
};
