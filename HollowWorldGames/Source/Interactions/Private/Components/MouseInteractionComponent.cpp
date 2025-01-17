// Copyright (c) 2024 Hollow World Games llc All Rights Reserved


#include "Components/MouseInteractionComponent.h"


// Sets default values for this component's properties
UMouseInteractionComponent::UMouseInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMouseInteractionComponent::RightMouseUp(AActor * Interactor) const
{
	OnRightMouseUp.Broadcast(Interactor);
}

void UMouseInteractionComponent::RightMouseDown(AActor * Interactor) const
{
	OnRightMouseDown.Broadcast(Interactor);
}

void UMouseInteractionComponent::LeftMouseUp(AActor * Interactor) const
{
	OnLeftMouseUp.Broadcast(Interactor);
}

void UMouseInteractionComponent::LeftMouseDown(AActor * Interactor) const
{
	OnLeftMouseDown.Broadcast(Interactor);
}

void UMouseInteractionComponent::MouseEntered(AActor * Interactor) const
{
	OnMouseEntered.Broadcast(Interactor);
}

void UMouseInteractionComponent::MouseLeft(AActor * Interactor)
{
	OnMouseLeave.Broadcast(Interactor);
	LeftMouse = RightMouse = false;
}

void UMouseInteractionComponent::SetLeftMouse(const bool State, AActor * Interactor)
{
	if (!LeftMouse && State)
	{
		LeftMouseDown(Interactor);
	}
	else if (LeftMouse && !State)
	{
		LeftMouseUp(Interactor);
	}
	LeftMouse = State;
}

void UMouseInteractionComponent::SetRightMouse(const bool State, AActor * Interactor)
{
	if (!RightMouse && State)
	{
		RightMouseDown(Interactor);
	}
	else if (RightMouse && !State)
	{
		RightMouseUp(Interactor);
	}
	RightMouse = State;
}


