// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved


#include "ViewableWorldSubsystem.h"

#include "UtilityStatics.h"
#include "Viewable.h"

void UViewableWorldSubsystem::AddViewable(TScriptInterface<IViewable> Viewable)
{
	Viewables.Add(Viewable);
	if(Viewable->IsLocalPlayer())
	{
		Player = Viewable;
		ResetToPlayerViewable();
	}
}

void UViewableWorldSubsystem::RemoveViewable(TScriptInterface<IViewable> Viewable)
{
	Viewables.Remove(Viewable);
}

void UViewableWorldSubsystem::CycleToNextViewable()
{
	TScriptInterface<IViewable> Next = UUtilityStatics::GetNextItem<TScriptInterface<IViewable>>(Viewables, Current);
	if(Next == Current)
	{
		Next = Viewables[0];	
	}
	Current->MakeInactive();
	Next->MakeActiveViewable();
	Current = Next;
	
}

void UViewableWorldSubsystem::CycleToNextViewPoint() const
{
	if(Current)
	{
		Current->ChangeViewPoint();
	}
}

void UViewableWorldSubsystem::ResetToPlayerViewable()
{
	if(Current != Player)
	{
		Current->MakeInactive();
		Player->MakeActiveViewable();
		Current = Player;
	}
}
