// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "Attributes/SpaceGameplayTags.h"
#include "PowerAttributeSet2.generated.h"

UCLASS()
class SPACEGAMEPLAY_API UPowerAttributeSet2 : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UPowerAttributeSet2, ShieldPower);
	ATTRIBUTE_TAG_ACCESSOR(UPowerAttributeSet, ShieldPower);
	ATTRIBUTE_ACCESSORS(UPowerAttributeSet2, ShieldDistribution);
	ATTRIBUTE_TAG_ACCESSOR(UPowerAttributeSet, ShieldDistribution);
	ATTRIBUTE_ACCESSORS(UPowerAttributeSet2, EnginePower);
	ATTRIBUTE_TAG_ACCESSOR(UPowerAttributeSet, EnginePower);
	ATTRIBUTE_ACCESSORS(UPowerAttributeSet2, EngineDistribution);
	ATTRIBUTE_TAG_ACCESSOR(UPowerAttributeSet, EngineDistribution);
	ATTRIBUTE_ACCESSORS(UPowerAttributeSet2, BatteryPower);
	ATTRIBUTE_TAG_ACCESSOR(UPowerAttributeSet, BatteryPower);
	ATTRIBUTE_ACCESSORS(UPowerAttributeSet2, BatteryDistribution);
	ATTRIBUTE_TAG_ACCESSOR(UPowerAttributeSet, BatteryDistribution);
	ATTRIBUTE_ACCESSORS(UPowerAttributeSet2, LifeSupportPower);
	ATTRIBUTE_TAG_ACCESSOR(UPowerAttributeSet, LifeSupportPower);
	ATTRIBUTE_ACCESSORS(UPowerAttributeSet2, LifeSupportDistribution);
	ATTRIBUTE_TAG_ACCESSOR(UPowerAttributeSet, LifeSupportDistribution);
	ATTRIBUTE_ACCESSORS(UPowerAttributeSet2, SensorPower);
	ATTRIBUTE_TAG_ACCESSOR(UPowerAttributeSet, SensorPower);
	ATTRIBUTE_ACCESSORS(UPowerAttributeSet2, SensorDistribution);
	ATTRIBUTE_TAG_ACCESSOR(UPowerAttributeSet, SensorDistribution);
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EngineDistribution, Category=Power)
	FGameplayAttributeData EngineDistribution;
	UFUNCTION()
	void OnRep_EngineDistribution(const FGameplayAttributeData& OldEngineDistribution) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EnginePower, Category=Power)
	FGameplayAttributeData EnginePower;
	UFUNCTION()
	void OnRep_EnginePower(const FGameplayAttributeData& OldEnginePower) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BatteryDistribution, Category=Power)
	FGameplayAttributeData BatteryDistribution;
	UFUNCTION()
	void OnRep_BatteryDistribution(const FGameplayAttributeData& OldBatteryDistribution) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BatteryPower, Category=Power)
	FGameplayAttributeData BatteryPower;
	UFUNCTION()
	void OnRep_BatteryPower(const FGameplayAttributeData& OldBatteryPower) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LifeSupportDistribution, Category=Power)
	FGameplayAttributeData LifeSupportDistribution;
	UFUNCTION()
	void OnRep_LifeSupportDistribution(const FGameplayAttributeData& OldLifeSupportDistribution) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LifeSupportPower, Category=Power)
	FGameplayAttributeData LifeSupportPower;
	UFUNCTION()
	void OnRep_LifeSupportPower(const FGameplayAttributeData& OldLifeSupportPower) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_SensorDistribution, Category=Power)
	FGameplayAttributeData SensorDistribution;
	UFUNCTION()
	void OnRep_SensorDistribution(const FGameplayAttributeData& OldSensorDistribution) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_SensorPower, Category=Power)
	FGameplayAttributeData SensorPower;
	UFUNCTION()
	void OnRep_SensorPower(const FGameplayAttributeData& OldSensorPower) const;
};
