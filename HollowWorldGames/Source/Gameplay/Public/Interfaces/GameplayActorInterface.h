// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "Attributes/AttributeSetBase.h"
#include "GenericTeamAgentInterface.h"
#include "GameplayActorInterface.generated.h"

class UGameplayEffect;



USTRUCT(BlueprintType)
struct FAttributeValue
{
	GENERATED_BODY()
	UPROPERTY()
	FGameplayTag AttributeTag;
	UPROPERTY()
	float NewValue;
};

class UGameplayAbilitySystemComponent;
// This class does not need to be modified.
UINTERFACE()
class GAMEPLAY_API UGameplayActorInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAMEPLAY_API IGameplayActorInterface
{
	GENERATED_BODY()
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual float GetAttributeBonus(FGameplayTag Attribute) = 0;
	virtual FAttributeChanged& GetAttributeChangedNotify() = 0;
	virtual TScriptInterface<IGameplayActorInterface> GetAbilityTarget() = 0;
	virtual float GetAttributeValue(FGameplayTag Attribute) = 0;
	virtual void ApplyEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level, UGameplayAbilitySystemComponent * Source) = 0;
};
