// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "UObject/Interface.h"
#include "ComponentContainerInterface.generated.h"

class UGameplayEffect;


// This class does not need to be modified.
UINTERFACE()
class UComponentContainerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPACEGAMEPLAY_API IComponentContainerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual TArray<FGameplayTag> GetComponentTags() const = 0;
	virtual void ApplyEffectToComponent(FGameplayTag Tag, TSubclassOf<UGameplayEffect> Effect, float Level, const AActor * Source) = 0;
	virtual void ApplyDamageToComponent(FGameplayTag Component, float Damage, const AActor * Source) = 0;
};
