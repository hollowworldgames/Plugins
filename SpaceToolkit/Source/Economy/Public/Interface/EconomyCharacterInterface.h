// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "EconomyCharacterInterface.generated.h"

class UGameplayAbilitySystemComponent;
// This class does not need to be modified.
UINTERFACE()
class UEconomyCharacterInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ECONOMY_API IEconomyCharacterInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual bool CanRefine(FGameplayTag Material) = 0;
	virtual bool CanConstruct(FGameplayTag Object, float Level) = 0;
	virtual FGameplayTag GetCurrentConstructObject() = 0;
	virtual FGameplayTag GetCurrentRefineMaterial() = 0;
	virtual void OnMaterialRefined(FGameplayTag Material, float Qty) = 0;
	virtual UGameplayAbilitySystemComponent * GetGameplayAbilitySystemComponent() = 0;
};
