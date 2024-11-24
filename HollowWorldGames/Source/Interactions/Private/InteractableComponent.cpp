// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "InteractableComponent.h"

#include "Components/TextRenderComponent.h"
#include "GameFramework/Character.h"
#include "Interactor.h"

// Sets default values for this component's properties
UInteractableComponent::UInteractableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractableComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UInteractableComponent::OnBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UInteractableComponent::OnEndOverlap);

	USceneComponent * Text = GetChildComponent(0);
	if(ensure(Text))
	{
		Text->SetVisibility(false);
	}
}

bool UInteractableComponent::CanInteract(TScriptInterface<IInteractor> interactor)
{
	return true;
}

void UInteractableComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IInteractor * character = Cast<IInteractor>(OtherActor);
	if(character && CanInteract(TObjectPtr<AActor>(OtherActor)))
	{
		character->OnInteractableAvailable(TObjectPtr<UInteractableComponent>(this));
		OnInteractorEntered.Broadcast(Cast<ACharacter>(OtherActor), this);
		Interactor.SetInterface(character);
		Interactor.SetObject(Cast<ACharacter>(OtherActor));
		USceneComponent * Text = GetChildComponent(0);
		if(ensure(Text))
		{
			Text->SetVisibility(true);
		}
	}
}

void UInteractableComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	IInteractor * character = Cast<IInteractor>(OtherActor);
	if(character)
	{
		character->OnInteractableUnavailable(TObjectPtr<UInteractableComponent>(this));
		OnInteractorExited.Broadcast(Cast<ACharacter>(OtherActor), this);
		Interactor.SetInterface(nullptr);
		Interactor.SetObject(nullptr);
		USceneComponent * Text = GetChildComponent(0);
		if(ensure(Text))
		{
			Text->SetVisibility(false);
		}
	}
}

void UInteractableComponent::OnInteraction(TScriptInterface<IInteractor> interactor)
{
	if(interactor)
	{
		interactor->OnInteractionBegin(TObjectPtr<UInteractableComponent>(this));
		OnBeginInteract.Broadcast(Cast<ACharacter>(interactor->GetInteractingPawn()), this);
	}
}

void UInteractableComponent::OnInteractComplete()
{
	if(Interactor)
	{
		Interactor->OnInteractionEnd(TObjectPtr<UInteractableComponent>(this));
		OnCompleteInteract.Broadcast(Cast<ACharacter>(Interactor.GetObject()), this);
	}
}

