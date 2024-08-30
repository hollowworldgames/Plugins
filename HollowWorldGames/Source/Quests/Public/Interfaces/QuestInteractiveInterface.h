﻿// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "QuestInteractiveInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UQuestInteractiveInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class QUESTS_API IQuestInteractiveInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void OnInteract(AActor * Actor) = 0;
};
