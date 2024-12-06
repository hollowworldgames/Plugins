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
	UFUNCTION(BlueprintCallable)
	UGameplayAbilitySystemComponent* GetSystemAbilityComponent(FGameplayTag System);
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToSystem(FGameplayTag System, TSubclassOf<UGameplayEffect> Effect);
	UFUNCTION(BlueprintCallable)
	void ApplyEffectsToSystem();
	UFUNCTION(BlueprintCallable)
	void RemoveEffectFromSystem(FGameplayTag System, TSubclassOf<UGameplayEffect> Effect);
	UFUNCTION(BlueprintCallable)
	void RemoveEffectsFromSystem();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
	FGameplayTag SystemTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
	TArray<TSubclassOf<UGameplayEffect>> EffectsToApply;
};
