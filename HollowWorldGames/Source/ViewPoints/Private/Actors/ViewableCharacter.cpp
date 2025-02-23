// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Actors/ViewableCharacter.h"
#include "UtilityStatics.h"
#include "ViewableWorldSubsystem.h"
#include "Components/ViewPointComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AViewableCharacter::AViewableCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AViewableCharacter::CycleViewable()
{
	UViewableWorldSubsystem * ViewableWorldSubsystem = GetWorld()->GetSubsystem<UViewableWorldSubsystem>();
	if(IsValidEnsure(ViewableWorldSubsystem))
	{
		ViewableWorldSubsystem->CycleToNextViewable();
	}
}

void AViewableCharacter::CycleViewPoint()
{
	UViewableWorldSubsystem * ViewableWorldSubsystem = GetWorld()->GetSubsystem<UViewableWorldSubsystem>();
	if(IsValidEnsure(ViewableWorldSubsystem))
	{
		ViewableWorldSubsystem->CycleToNextViewPoint();
	}
}

void AViewableCharacter::ChangeViewPoint()
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

void AViewableCharacter::MakeActiveViewable()
{
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (IsValidEnsure(controller))
	{
		controller->SetViewTargetWithBlend(this, 2);//TODO : Change to global setting
			
		if(MainViewPoint)
		{
			MainViewPoint->MakeActive();
			CurrentViewPoint = MainViewPoint;
		}
	}
}

void AViewableCharacter::MakeInactive()
{
	if(CurrentViewPoint)
	{
		CurrentViewPoint->MakeInactive();
		CurrentViewPoint = nullptr;
	}
}

void AViewableCharacter::ResetToMain()
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

// Called when the game starts or when spawned
void AViewableCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetComponents(ViewPoints);

	if(ViewPoints.Num() > 0)
	{
		UViewableWorldSubsystem * ViewableWorldSubsystem = GetWorld()->GetSubsystem<UViewableWorldSubsystem>();
		if(IsValidEnsure(ViewableWorldSubsystem))
		{
			ViewableWorldSubsystem->AddViewable(TScriptInterface<IViewable>(TObjectPtr<AViewableCharacter>(this)));
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

void AViewableCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UViewableWorldSubsystem * ViewableWorldSubsystem = GetWorld()->GetSubsystem<UViewableWorldSubsystem>();
	if(IsValidEnsure(ViewableWorldSubsystem))
	{
		ViewableWorldSubsystem->RemoveViewable(TScriptInterface<IViewable>(this));
	}
}


