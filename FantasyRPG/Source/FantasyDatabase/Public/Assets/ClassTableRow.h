// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ScalableFloat.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "ClassTableRow.generated.h"


struct FAbilityData;
class UGameplayEffect;

USTRUCT(BlueprintType)
struct FANTASYDATABASE_API FClassTableRow : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PrimaryAttributes)
	FScalableFloat StrengthValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PrimaryAttributes)
	FScalableFloat AgilityValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PrimaryAttributes)
	FScalableFloat PrecisionValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PrimaryAttributes)
	FScalableFloat IntelligenceValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PrimaryAttributes)
	FScalableFloat WisdomValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PrimaryAttributes)
	FScalableFloat LuckValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PrimaryAttributes)
	FScalableFloat ConstitutionValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PrimaryAttributes)
	FScalableFloat EnduranceValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PrimaryAttributes)
	FScalableFloat CharismaValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=InitializeEffect)
	TSubclassOf<UGameplayEffect> CalculateSecondary;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=InitializeEffect)
	TSubclassOf<UGameplayEffect> SelfHeal;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=ClassAbilities)
	TArray<FAbilityData> ClassAbilities;
};
