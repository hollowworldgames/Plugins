// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "UObject/Object.h"
#include "RaceDataRow.generated.h"

class UGameplayEffect;
class UGameplayAbility;

USTRUCT()
struct GAMEPLAY_API FRaceDataRow : public FTableRowBase
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RaceName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MultiLine="true"))
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USoundBase> Introduction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> RaceIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> Mannequin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Effects)
	TArray<TSubclassOf<UGameplayEffect>> InitialEffects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Abilities)
	TArray<FAbilityData> Abilities;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeBonus)
	float StrengthBonus = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeBonus)
	float AgilityBonus = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeBonus)
	float PrecisionBonus = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeBonus)
	float IntelligenceBonus = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeBonus)
	float WisdomBonus = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeBonus)
	float LuckBonus = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeBonus)
	float ConstitutionBonus = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeBonus)
	float EnduranceBonus = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeBonus)
	float Charisma = 1;
};
