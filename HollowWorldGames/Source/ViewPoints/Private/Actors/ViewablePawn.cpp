// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "Actors/ViewablePawn.h"
#include "EnhancedInputComponent.h"
#include "UtilityStatics.h"
#include "Kismet/GameplayStatics.h"
#include "ViewableWorldSubsystem.h"
#include "Components/ViewPointComponent.h"

// Sets default values
AViewablePawn::AViewablePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AViewablePawn::BeginPlay()
{
	Super::BeginPlay();
	GetComponents(ViewPoints);
	if(ViewPoints.Num() > 0)
	{
		UViewableWorldSubsystem * ViewableWorldSubsystem = GetWorld()->GetSubsystem<UViewableWorldSubsystem>();
		if(ensure(ViewableWorldSubsystem))
		{
			ViewableWorldSubsystem->AddViewable(TScriptInterface<IViewable>(TObjectPtr<AViewablePawn>(this)));
		}

		for(TObjectPtr<UViewPointComponent> ViewPoint : ViewPoints)
		{
			if(ViewPoint->IsMainViewPoint())
			{
				MainViewPoint = ViewPoint;
				break;
			}
		}
	}
}

void AViewablePawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UViewableWorldSubsystem * ViewableWorldSubsystem = GetWorld()->GetSubsystem<UViewableWorldSubsystem>();
	if(ensure(ViewableWorldSubsystem))
	{
		ViewableWorldSubsystem->RemoveViewable(TScriptInterface<IViewable>(this));
	}
}

void AViewablePawn::CycleViewable()
{
	UViewableWorldSubsystem * ViewableWorldSubsystem = GetWorld()->GetSubsystem<UViewableWorldSubsystem>();
	if(ensure(ViewableWorldSubsystem))
	{
		ViewableWorldSubsystem->CycleToNextViewable();
	}
}

void AViewablePawn::CycleViewPoint()
{
	UViewableWorldSubsystem * ViewableWorldSubsystem = GetWorld()->GetSubsystem<UViewableWorldSubsystem>();
	if(ensure(ViewableWorldSubsystem))
	{
		ViewableWorldSubsystem->CycleToNextViewPoint();
	}
}

void AViewablePawn::ChangeViewPoint()
{
	
	TObjectPtr<UViewPointComponent> Next = UUtilityStatics::GetNextItem<TObjectPtr<UViewPointComponent>>(ViewPoints, CurrentViewPoint);
	if(CurrentViewPoint == Next)
	{
		Next = ViewPoints[0];
	}
	CurrentViewPoint->MakeInactive();
	Next->MakeActive();
	CurrentViewPoint = Next;
}

void AViewablePawn::MakeActiveViewable()
{
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (ensure(controller))
	{
		controller->SetViewTargetWithBlend(this, 2);//TODO : Change to global setting
			
		if(MainViewPoint)
		{
			MainViewPoint->MakeActive();
			CurrentViewPoint = MainViewPoint;
		}
	}
}

void AViewablePawn::MakeInactive()
{
	if(CurrentViewPoint)
	{
		CurrentViewPoint->MakeInactive();
		CurrentViewPoint = nullptr;
	}
}

void AViewablePawn::ResetToMain()
{
	if(CurrentViewPoint != MainViewPoint)
	{
		if(CurrentViewPoint)
		{
			CurrentViewPoint->MakeInactive();
		}
		MainViewPoint->MakeActive();
		CurrentViewPoint = MainViewPoint;
	}
}