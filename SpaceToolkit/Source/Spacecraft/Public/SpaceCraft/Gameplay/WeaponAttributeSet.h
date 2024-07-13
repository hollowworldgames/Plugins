// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeMacros.h"
#include "AttributeSet.h"
#include "WeaponAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class SPACECRAFT_API UWeaponAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponLevel);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponAccuracy);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponMinRange);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponMaxRange);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponMinDamage);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponMaxDamage);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponCriticalChance);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, WeaponCriticalDamage);
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponLevel, Category=Health)
	FGameplayAttributeData WeaponLevel;
	UFUNCTION()
	void OnRep_WeaponLevel(const FGameplayAttributeData& OldWeaponLevel) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Boost)
	FGameplayAttributeData WeaponHealthBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Boost)
	FGameplayAttributeData WeaponAccuracyBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Boost)
	FGameplayAttributeData WeaponMinRangeBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Boost)
	FGameplayAttributeData WeaponMaxRangeBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Boost)
	FGameplayAttributeData WeaponCriticalChanceBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Boost)
	FGameplayAttributeData WeaponCriticalDamageBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Boost)
	FGameplayAttributeData WeaponMaxDamageBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Boost)
	FGameplayAttributeData WeaponMinDamageBoost;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponHealth, Category=Health)
	FGameplayAttributeData WeaponHealth;
	UFUNCTION()
	void OnRep_WeaponHealth(const FGameplayAttributeData& OldWeaponHealth) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxWeaponHealth, Category=Health)
	FGameplayAttributeData MaxWeaponHealth;
	UFUNCTION()
	void OnRep_MaxWeaponHealth(const FGameplayAttributeData& OldMaxWeaponHealth) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponAccuracy, Category=Health)
	FGameplayAttributeData WeaponAccuracy;
	UFUNCTION()
	void OnRep_WeaponAccuracy(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponMinRange, Category=Health)
	FGameplayAttributeData WeaponMinRange;
	UFUNCTION()
	void OnRep_WeaponMinRange(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponMaxRange, Category=Health)
	FGameplayAttributeData WeaponMaxRange;
	UFUNCTION()
	void OnRep_WeaponMaxRange(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponCriticalChance, Category=Health)
	FGameplayAttributeData WeaponCriticalChance;
	UFUNCTION()
	void OnRep_WeaponCriticalChance(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponCriticalDamage, Category=Health)
	FGameplayAttributeData WeaponCriticalDamage;
	UFUNCTION()
	void OnRep_WeaponCriticalDamage(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponMinDamage, Category=Health)
	FGameplayAttributeData WeaponMinDamage;
	UFUNCTION()
	void OnRep_WeaponMinDamage(const FGameplayAttributeData& OldWeaponLevel) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_WeaponMaxDamage, Category=Health)
	FGameplayAttributeData WeaponMaxDamage;
	UFUNCTION()
	void OnRep_WeaponMaxDamage(const FGameplayAttributeData& OldWeaponLevel) const;
};
