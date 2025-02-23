// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayWidgetController.h"
#include "GameplayVitalWidgetController.generated.h"



UCLASS()
class GAMEPLAY_API UGameplayVitalWidgetController : public UGameplayWidgetController
{
	GENERATED_BODY()
public :
	virtual void BindToAttributes() override;
	virtual void PulseAttributes() override;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnHealthChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnMaxHealthChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnEnergyChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnMaxEnergyChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnManaChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnMaxManaChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnLevelChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnExperienceChanged;
};
