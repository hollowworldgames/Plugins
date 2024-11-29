// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "ComponentContainerInterface.generated.h"

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
	virtual TArray<FGameplayTag> GetComponents() const = 0;
	virtual void ApplyDamageToComponent(FGameplayTag Component, float Damage, const AActor * Source) = 0;
};
