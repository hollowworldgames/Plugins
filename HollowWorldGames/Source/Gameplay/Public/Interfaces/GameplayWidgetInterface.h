// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayWidgetInterface.generated.h"

class IGameplayActorInterface;
// This class does not need to be modified.
UINTERFACE(BlueprintType, Blueprintable)
class UGameplayWidgetInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAMEPLAY_API IGameplayWidgetInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent, Category=Events)
	void InitializeWidget(ACharacter * Character);
};
