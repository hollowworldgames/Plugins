// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactor.generated.h"

class IInteractable;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INTERACTIONS_API IInteractor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void OnInteractableAvailable(TScriptInterface<IInteractable> Interactable) = 0;
	virtual void OnInteractableUnavailable(TScriptInterface<IInteractable> Interactable) = 0;
	virtual void OnInteractionBegin(TScriptInterface<IInteractable> Interactable) = 0;
	virtual void OnInteractionEnd(TScriptInterface<IInteractable> Interactable) = 0;
	virtual APawn * GetInteractingPawn() = 0;
	virtual AController * GetInteractingController() = 0;
};
