// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SystemGameplayAbility.generated.h"

class UGameplayAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class SPACECRAFT_API USystemGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public :
	void SetSystemTag(FGameplayTag Tag) { SystemTag = Tag; }
protected :
	UFUNCTION(BlueprintCallable, Category = "System Gameplay Ability")
	UGameplayAbilitySystemComponent* GetSystemAbilityComponent(FGameplayTag System);
	UFUNCTION(BlueprintCallable, Category = "System Gameplay Ability")
	void ApplyEffectToSystem(FGameplayTag System, TSubclassOf<UGameplayEffect> Effect);
	UFUNCTION(BlueprintCallable, Category = "System Gameplay Ability")
	void ApplyEffectsToSystem();
	UFUNCTION(BlueprintCallable, Category = "System Gameplay Ability")
	void RemoveEffectFromSystem(FGameplayTag System, TSubclassOf<UGameplayEffect> Effect);
	UFUNCTION(BlueprintCallable, Category = "System Gameplay Ability")
	void RemoveEffectsFromSystem();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
	FGameplayTag SystemTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
	TArray<TSubclassOf<UGameplayEffect>> EffectsToApply;
};
