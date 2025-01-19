// Copyright (c) 2024 Hollow World Games llc All Rights Reserved


#include "Components/MouseInteractorComponent.h"
#include "Components/MouseInteractionComponent.h"
#include "Interfaces/Highlightable.h"
#include "Interfaces/Interactable.h"


// Sets default values for this component's properties
UMouseInteractorComponent::UMouseInteractorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UMouseInteractorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

AActor* UMouseInteractorComponent::GetActorUnderCursor(APlayerController* Controller) const
{
	FHitResult Hit;
	if (Controller->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), false, Hit))
	{
		AActor * Actor = Hit.GetActor();
		if (Actor->Implements<UInteractable>() || Actor->GetComponentByClass<UMouseInteractionComponent>())
		{
			return Hit.GetActor();
		}
	}
	return nullptr;
}


void UMouseInteractorComponent::Clear()
{
	if (Highlightable)
	{
		Highlightable->RemoveHighlighted();
		Highlightable.SetObject(nullptr);
        Highlightable.SetInterface(nullptr);
	}
	if (Interactable)
	{
		Interactable->OnMouseLeft(GetOwner());
		Interactable.SetObject(nullptr);
        Interactable.SetInterface(nullptr);
	}
	if (Component)
	{
		Component->MouseLeft(GetOwner());
		Component = nullptr;
	}
}

// Called every frame
void UMouseInteractorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	APawn * Pawn = GetOwner<APawn>();
	if (ensure(Pawn))
	{
		if (APlayerController * Controller = Cast<APlayerController>(Pawn->GetController()))
		{
			if (Controller->bShowMouseCursor)
			{
				if (TObjectPtr<AActor> Actor = GetActorUnderCursor(Controller))
				{
					if (Actor->Implements<UInteractable>())
					{
						if (Actor != Interactable.GetObject())
						{
							Clear();
							Highlightable = Actor;
							Interactable = Actor;
							Interactable->OnMouseEntered(GetOwner());
							Highlightable->SetHighlighted();
						}
						else
						{
							Interactable->SetLeftMouse(Controller->IsInputKeyDown(EKeys::LeftMouseButton), GetOwner());
							Interactable->SetRightMouse(Controller->IsInputKeyDown(EKeys::RightMouseButton), GetOwner());
						}
					}
					else
					{
						UMouseInteractionComponent * NewComponent = Actor->GetComponentByClass<UMouseInteractionComponent>();
						if (Component != NewComponent)
						{
							Clear();
							Component = NewComponent;
							Component->MouseEntered(GetOwner());
						}
						if (Component)
						{
							Component->SetLeftMouse(Controller->IsInputKeyDown(EKeys::LeftMouseButton), GetOwner());
							Component->SetRightMouse(Controller->IsInputKeyDown(EKeys::RightMouseButton), GetOwner());
						}
					}
				}
				else
				{
					Clear();
				}
			}
			else
			{
				Clear();
			}
		}
	}
}

