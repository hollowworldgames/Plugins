// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "Actors/ViewableActor.h"

#include "UtilityStatics.h"
#include "ViewableWorldSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ViewPointComponent.h"

// Sets default values
AViewableActor::AViewableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AViewableActor::ChangeViewPoint()
{
	if(CurrentViewPoint)
	{
		CurrentViewPoint->MakeInactive();
	}
	CurrentViewPoint = UUtilityStatics::GetNextItem<TObjectPtr<UViewPointComponent>>(ViewPoints, CurrentViewPoint);
	if(CurrentViewPoint)
	{
		CurrentViewPoint->MakeActive();
	}
}

void AViewableActor::MakeActiveViewable()
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

void AViewableActor::MakeInactive()
{
	if(CurrentViewPoint)
	{
		CurrentViewPoint->MakeInactive();
		CurrentViewPoint = nullptr;
	}
}

void AViewableActor::ResetToMain()
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
void AViewableActor::BeginPlay()
{
	Super::BeginPlay();

	GetComponents(ViewPoints);
	if(ViewPoints.Num() > 0)
	{
		UViewableWorldSubsystem * ViewableWorldSubsystem = GetWorld()->GetSubsystem<UViewableWorldSubsystem>();
		if(ensure(ViewableWorldSubsystem))
		{
			ViewableWorldSubsystem->AddViewable(TScriptInterface<IViewable>(TObjectPtr<AViewableActor>(this)));
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

