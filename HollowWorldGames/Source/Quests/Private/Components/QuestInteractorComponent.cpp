// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/QuestInteractorComponent.h"
#include "Components/QuestReceiverComponent.h"


// Sets default values for this component's properties
UQuestInteractorComponent::UQuestInteractorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UQuestInteractorComponent::OnInteracted(AActor* Interactor) const
{
	if(UQuestReceiverComponent * QuestComponent = Interactor->GetComponentByClass<UQuestReceiverComponent>())
	{
		if(Give)
		{
			QuestComponent->OnQuestGiveItem(QuestId, StageId, GetOwner());
		}
		else
		{
			QuestComponent->OnQuestReceiveItem(QuestId, StageId, GetOwner());
		}
		OnInteractedWith.Broadcast(Interactor);
	}
}
