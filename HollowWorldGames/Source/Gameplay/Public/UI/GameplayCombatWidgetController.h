// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayWidgetController.h"
#include "GameplayCombatWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API UGameplayCombatWidgetController : public UGameplayWidgetController
{
	GENERATED_BODY()
public :
	virtual void BindToAttributes() override;
	virtual void PulseAttributes() override;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnPenetrationChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnPenetrationValueChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnCriticalChanceChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnCriticalValueChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnCriticalDefenseChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnArmorChanged;
};

UCLASS()
class GAMEPLAY_API UGameplayRPGCombatWidgetController : public UGameplayCombatWidgetController
{
	GENERATED_BODY()
public :
	virtual void BindToAttributes() override;
	virtual void PulseAttributes() override;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnHitChanceChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnGlancingBlowChanceChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnGlancingBlowValueChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnEvadeChanceChanged;
};


