// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/QuestGiverInteractionComponent.h"

#include "Components/QuestGiverComponent.h"
#include "Interfaces/QuestReceiverInterface.h"


// Sets default values for this component's properties
UQuestGiverInteractionComponent::UQuestGiverInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UQuestGiverInteractionComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->Implements<UQuestReceiverInterface>())
	{
		TScriptInterface<IQuestReceiverInterface> Receiver = TObjectPtr<AActor>(OtherActor);
		if(Receiver)
		{
			Receiver->QuestInteractionAvailable(TObjectPtr<AActor>(GetOwner()));
		}
	}
}


void UQuestGiverInteractionComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor->Implements<UQuestReceiverInterface>())
	{
		TScriptInterface<IQuestReceiverInterface> Receiver = TObjectPtr<AActor>(OtherActor);
		if(Receiver)
		{
			Receiver->QuestInteractionUnavailable(TObjectPtr<AActor>(GetOwner()));
		}
	}
}

// Called when the game starts
void UQuestGiverInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UQuestGiverInteractionComponent::OnBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UQuestGiverInteractionComponent::OnEndOverlap);
	
}


