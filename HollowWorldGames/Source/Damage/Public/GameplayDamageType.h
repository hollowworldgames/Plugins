// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "GameplayDamageType.generated.h"

/**
 * 
 */
UCLASS()
class DAMAGE_API UGameplayDamageType : public UDamageType
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	TArray<TSubclassOf<class UGameplayEffect>> Effects;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Damage)
	TArray<float> EffectLevels;
};
