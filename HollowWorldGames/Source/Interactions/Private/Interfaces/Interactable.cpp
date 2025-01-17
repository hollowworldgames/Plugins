// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "Interfaces/Interactable.h"

// Add default functionality here for any IInteractable functions that are not pure virtual.
void IInteractable::OnLeftMouseUp(AActor * Interactor)
{
	LeftMouseDown = false;
}

void IInteractable::OnLeftMouseDown(AActor * Interactor)
{
	LeftMouseDown = true;
}

void IInteractable::OnRightMouseUp(AActor * Interactor)
{
	RightMouseDown = true;
}

void IInteractable::OnRightMouseDown(AActor * Interactor)
{
	RightMouseDown = false;
}


void IInteractable::OnMouseLeft(AActor * Interactor)
{
	if (LeftMouseDown)
	{
		OnLeftMouseUp(Interactor);
	}
	if (RightMouseDown)
	{
		OnRightMouseUp(Interactor);
	}
}

void IInteractable::OnMouseEntered(AActor * Interactor)
{
}

void IInteractable::SetRightMouse(bool State, AActor * Interactor)
{
	if (!State && RightMouseDown)
	{
		OnRightMouseUp(Interactor);
	}
	if (State && !RightMouseDown)
	{
		OnRightMouseDown(Interactor);
	}
}

void IInteractable::SetLeftMouse(bool State, AActor * Interactor)
{
	if (!State && LeftMouseDown)
	{
		OnLeftMouseUp(Interactor);
	}
	if (State && !LeftMouseDown)
	{
		OnLeftMouseDown(Interactor);
	}
}
