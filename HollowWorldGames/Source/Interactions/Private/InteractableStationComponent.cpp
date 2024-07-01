// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "InteractableStationComponent.h"
#include "UtilityStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/WidgetComponent.h"
#include "Interactor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UInteractableStationComponent::UInteractableStationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractableStationComponent::BeginPlay()
{
	Super::BeginPlay();

	UTextRenderComponent * text = Cast<UTextRenderComponent>(GetChildComponent(0));
	if(text)
	{
		text->SetVisibility(false);
	}
	Widget = Cast<UWidgetComponent>(GetChildComponent(1));
	OnComponentBeginOverlap.AddDynamic(this, &UInteractableStationComponent::OnBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UInteractableStationComponent::OnEndOverlap);
	
}

void UInteractableStationComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IInteractor * character = Cast<IInteractor>(OtherActor);
	if(character)
	{
		character->OnInteractableAvailable(TObjectPtr<UInteractableStationComponent>(this));
		UTextRenderComponent * text = Cast<UTextRenderComponent>(GetChildComponent(0));
		if(text)
		{
			text->SetVisibility(true);
		}
	}
}

void UInteractableStationComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	IInteractor * character = Cast<IInteractor>(OtherActor);
	if(character)
	{
		character->OnInteractableUnavailable(TObjectPtr<UInteractableStationComponent>(this));
		UTextRenderComponent * text = Cast<UTextRenderComponent>(GetChildComponent(0));
		if(text)
		{
			text->SetVisibility(false);
		}
	}
}

void UInteractableStationComponent::OnInteraction(TScriptInterface<IInteractor> interactor)
{
	
	UCameraComponent * camera = GetCamera();
	if(ensure(camera))
	{
		APlayerController * controller = Cast<APlayerController>(interactor->GetInteractingController());
		if(ensure(controller))
		{
			if(PreviousTarget)
			{
				LogStart(LogSeverity::Information, true) << TEXT("interacting stopped") << LogStop();
				controller->SetViewTargetWithBlend(PreviousTarget, 1);
				controller->bShowMouseCursor = false;
				UWidgetBlueprintLibrary::SetInputMode_GameOnly(controller);
				PreviousTarget = nullptr;
			}
			else
			{
				LogStart(LogSeverity::Information, true) << TEXT("interacting Started") << LogStop();
				PreviousTarget = controller->GetViewTarget();
				controller->SetViewTargetWithBlend(GetOwner(), 1);
				UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(controller);
				controller->bShowMouseCursor = true;
				//controller->InitializeInteractableStation(this);
			}
		}
	}
}

UCameraComponent* UInteractableStationComponent::GetCamera()
{
	if(GetOwner())
	{
		return GetOwner()->GetComponentByClass<UCameraComponent>();
	}
	return nullptr;
}
