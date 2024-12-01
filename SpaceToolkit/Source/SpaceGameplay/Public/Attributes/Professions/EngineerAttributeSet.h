// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "Attributes/SpaceGameplayTags.h"
#include "EngineerAttributeSet.generated.h"



UCLASS()
class SPACEGAMEPLAY_API UEngineerAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UEngineerAttributeSet, ReactorPower);
	ATTRIBUTE_TAG_ACCESSOR(UEngineerAttributeSet, ReactorPower);
	ATTRIBUTE_ACCESSORS(UEngineerAttributeSet, ReactorEfficiency);
	ATTRIBUTE_TAG_ACCESSOR(UEngineerAttributeSet, ReactorEfficiency);
	ATTRIBUTE_ACCESSORS(UEngineerAttributeSet, ShieldEfficiency);
	ATTRIBUTE_TAG_ACCESSOR(UEngineerAttributeSet, ShieldEfficiency);
	ATTRIBUTE_ACCESSORS(UEngineerAttributeSet, ShieldReinforcement);
	ATTRIBUTE_TAG_ACCESSOR(UEngineerAttributeSet, ShieldReinforcement);
	ATTRIBUTE_ACCESSORS(UEngineerAttributeSet, ShieldStrength);
	ATTRIBUTE_TAG_ACCESSOR(UEngineerAttributeSet, ShieldStrength);
	ATTRIBUTE_ACCESSORS(UEngineerAttributeSet, BatteryEfficiency);
	ATTRIBUTE_TAG_ACCESSOR(UEngineerAttributeSet, BatteryEfficiency);
	ATTRIBUTE_ACCESSORS(UEngineerAttributeSet, HullStrength);
	ATTRIBUTE_TAG_ACCESSOR(UEngineerAttributeSet, HullStrength);
	ATTRIBUTE_ACCESSORS(UEngineerAttributeSet, HullReinforcement);
	ATTRIBUTE_TAG_ACCESSOR(UEngineerAttributeSet, HullReinforcement);
	ATTRIBUTE_ACCESSORS(UEngineerAttributeSet, ComponentStrength);
	ATTRIBUTE_TAG_ACCESSOR(UEngineerAttributeSet, ComponentStrength);
	ATTRIBUTE_ACCESSORS(UEngineerAttributeSet, ArmorReinforcement);
	ATTRIBUTE_TAG_ACCESSOR(UEngineerAttributeSet, ArmorReinforcement);
	ATTRIBUTE_ACCESSORS(UEngineerAttributeSet, ArmorMass);
	ATTRIBUTE_TAG_ACCESSOR(UEngineerAttributeSet, ArmorMass);
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ReactorPower, Category=Engineer)
	FGameplayAttributeData ReactorPower;
	UFUNCTION()
	void OnRep_ReactorPower(const FGameplayAttributeData& OldReactorPower) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ReactorEfficiency, Category=Engineer)
	FGameplayAttributeData ReactorEfficiency;
	UFUNCTION()
	void OnRep_ReactorEfficiency(const FGameplayAttributeData& OldReactorEfficiency) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldEfficiency, Category=Engineer)
	FGameplayAttributeData ShieldEfficiency;
	UFUNCTION()
	void OnRep_ShieldEfficiency(const FGameplayAttributeData& OldShieldEfficiency) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldStrength, Category=Engineer)
	FGameplayAttributeData ShieldStrength;
	UFUNCTION()
	void OnRep_ShieldStrength(const FGameplayAttributeData& OldShieldStrength) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldReinforcement, Category=Engineer)
	FGameplayAttributeData ShieldReinforcement;
	UFUNCTION()
	void OnRep_ShieldReinforcement(const FGameplayAttributeData& OldShieldReinforcement) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BatteryEfficiency, Category=Engineer)
	FGameplayAttributeData BatteryEfficiency;
	UFUNCTION()
	void OnRep_BatteryEfficiency(const FGameplayAttributeData& OldBatteryEfficiency) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HullStrength, Category=Engineer)
	FGameplayAttributeData HullStrength;
	UFUNCTION()
	void OnRep_HullStrength(const FGameplayAttributeData& OldHullStrength) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_HullReinforcement, Category=Engineer)
	FGameplayAttributeData HullReinforcement;
	UFUNCTION()
	void OnRep_HullReinforcement(const FGameplayAttributeData& OldHullReinforcement) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ArmorReinforcement, Category=Engineer)
	FGameplayAttributeData ArmorReinforcement;
	UFUNCTION()
	void OnRep_ArmorReinforcement(const FGameplayAttributeData& OldArmorReinforcement) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ArmorMass, Category=Engineer)
	FGameplayAttributeData ArmorMass;
	UFUNCTION()
	void OnRep_ArmorMass(const FGameplayAttributeData& OldArmorMass) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ComponentStrength, Category=Engineer)
	FGameplayAttributeData ComponentStrength;
	UFUNCTION()
	void OnRep_ComponentStrength(const FGameplayAttributeData& OldComponentStrength) const;
};
