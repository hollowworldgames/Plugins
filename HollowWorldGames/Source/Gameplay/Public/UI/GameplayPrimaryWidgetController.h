// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayWidgetController.h"
#include "GameplayPrimaryWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API UGameplayPrimaryWidgetController : public UGameplayWidgetController
{
	GENERATED_BODY()
public :
	virtual void BindToAttributes() override;
	virtual void PulseAttributes() override;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnStrengthChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnAgilityChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnPrecisionChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnIntelligenceChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnWisdomChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnLuckChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnConstitutionChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnEnduranceChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnCharismaChanged;
};
