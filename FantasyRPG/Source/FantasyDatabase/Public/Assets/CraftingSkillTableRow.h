// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "CraftingSkillTableRow.generated.h"

class UGameplayAbility;
/**
 * 
 */
USTRUCT(BlueprintType)
struct FANTASYDATABASE_API FCraftingSkillTableRow
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	FGameplayTag CraftingSkill;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Abilities)
	TArray<FAbilityData> Abilities;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	FString Description;
};
