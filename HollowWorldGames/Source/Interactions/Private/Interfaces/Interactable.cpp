// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "Interfaces/Interactable.h"

// Add default functionality here for any IInteractable functions that are not pure virtual.
void IInteractable::OnLeftMouseUp(AActor * Interactor)
{
	
}

void IInteractable::OnLeftMouseDown(AActor * Interactor)
{
	
}

void IInteractable::OnRightMouseUp(AActor * Interactor)
{
	
}

void IInteractable::OnRightMouseDown(AActor * Interactor)
{
	
}

void IInteractable::OnTouchUp(AActor* Interactor)
{
	
}

void IInteractable::OnTouchDown(AActor* Interactor)
{
	
}


void IInteractable::OnMouseLeft(AActor * Interactor)
{
	LeftMouseDown = false;
	RightMouseDown = false;
	TouchDown = false;
}

void IInteractable::OnMouseEntered(AActor * Interactor)
{
	
}

void IInteractable::SetRightMouse(const bool State, AActor * Interactor)
{
	if (!State && RightMouseDown)
	{
		OnRightMouseUp(Interactor);
	}
	if (State && !RightMouseDown)
	{
		OnRightMouseDown(Interactor);
	}
	RightMouseDown = State;
}

void IInteractable::SetLeftMouse(const bool State, AActor * Interactor)
{
	if (!State && LeftMouseDown)
	{
		OnLeftMouseUp(Interactor);
	}
	if (State && !LeftMouseDown)
	{
		OnLeftMouseDown(Interactor);
	}
	LeftMouseDown = State;
}

void IInteractable::SetTouch(const bool State, AActor* Interactor)
{
	if (!State && TouchDown)
	{
		OnTouchUp(Interactor);
	}
	if (State && !TouchDown)
	{
		OnTouchDown(Interactor);
	}
	TouchDown = State;
}
