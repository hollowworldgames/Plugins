// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/GameplayWidgetController.h"
#include "FantasyCraftingWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class FANTASYCRAFTING_API UFantasyCraftingWidgetController : public UGameplayWidgetController
{
	GENERATED_BODY()
public :
	virtual void BindToAttributes() override;
	virtual void PulseAttributes() override;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnProspectingLevelChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnForestryLevelChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnFarmingLevelChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnJewelerLevelChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnHerbalistLevelChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnCookLevelChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnBlacksmithLevelChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnWoodWorkerLevelChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnLoreMasterLevelChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChangedNotify OnTailorLevelChanged;
};
