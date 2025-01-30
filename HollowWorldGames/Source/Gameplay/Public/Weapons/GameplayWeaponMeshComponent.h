// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameplayWeaponMeshComponent.generated.h"

class UGameplayAbility;



UCLASS()
class GAMEPLAY_API UGameplayWeaponMeshComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()
public :
	void SetCurrentAbility(const FGameplayTag AbilityTag) { CurrentAbility = AbilityTag; }
	void SetDamage(const float Min, const float Max) { MinDamage = Min; MaxDamage = Max; }
	static bool AbilityLaunchOnImpact;
protected :
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Damage)
	float MinDamage = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Damage)
	float MaxDamage = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Damage)
	FGameplayTag CurrentAbility;
};
