// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "UObject/Object.h"
#include "SkillTableRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FANTASYDATABASE_API FSkillTableRow : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	float MaxLevel = 4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Abilities)
	TArray<FAbilityData> Abilities;
};
