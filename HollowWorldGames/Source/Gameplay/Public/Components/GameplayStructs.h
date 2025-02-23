#pragma once
#include "CoreMinimal.h"
#include "GameplayTags.h"
#include "GameplayStructs.generated.h"

UENUM(BlueprintType)
enum ECombatRollResult
{
	Miss UMETA(DisplayName = "Miss"),
	Hit UMETA(DisplayName = "Hit"),
	Glance UMETA(DisplayName = "Glance"),
	Block UMETA(DisplayName = "Block"),
	Parry UMETA(DisplayName = "Parry"),
	Evade UMETA(DisplayName = "Evade"),
	CriticalHit UMETA(DisplayName = "Critical Hit"),
	PenetratingHit UMETA(DisplayName = "Penetrating Hit"),
	DamageOverTime UMETA(Displayname = "Damage Over Time")
};

USTRUCT(BlueprintType)
struct FCustomEffectValue
{
	GENERATED_BODY()
	FCustomEffectValue(){}
	FCustomEffectValue(FGameplayTag Tag, float NewValue)
	{
		ValueTag = Tag;
		Value = NewValue;
	}
	UPROPERTY()
	FGameplayTag ValueTag;
	UPROPERTY()
	float Value = 0;
};