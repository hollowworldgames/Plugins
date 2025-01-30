// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "UObject/Object.h"
#include "ProfessionDataRow.generated.h"

class UGameplayEffect;
class UGameplayAbility;
/**
 * 
 */
USTRUCT()
struct GAMEPLAY_API FProfessionDataRow : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ProfessionName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MultiLine="true"))
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USoundBase> Introduction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> ProfessionIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Effects)
	TArray<TSubclassOf<UGameplayEffect>> InitialEffects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Abilities)
	TArray<FAbilityData> Abilities;
};
