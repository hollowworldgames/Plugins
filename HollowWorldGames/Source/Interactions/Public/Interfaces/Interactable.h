// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

class IInteractor;
class ACommonPlayerController;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INTERACTIONS_API IInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void OnInteraction(TScriptInterface<IInteractor> interactor) = 0;
	virtual void OnLeftMouseUp(AActor * Interactor);
	virtual void OnLeftMouseDown(AActor * Interactor);
	virtual void OnRightMouseUp(AActor * Interactor);
    virtual void OnRightMouseDown(AActor * Interactor);
	virtual void OnTouchUp(AActor * Interactor);
	virtual void OnTouchDown(AActor * Interactor);
	virtual void OnMouseLeft(AActor * Interactor);
	virtual void OnMouseEntered(AActor * Interactor);
	virtual void SetRightMouse(bool State, AActor * Interactor);
	virtual void SetLeftMouse(bool State, AActor * Interactor);
	virtual void SetTouch(bool State, AActor * Interactor);
protected :
	bool LeftMouseDown = false;
	bool RightMouseDown = false;
	bool TouchDown = false;
};
