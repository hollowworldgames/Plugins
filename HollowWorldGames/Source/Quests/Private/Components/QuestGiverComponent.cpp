// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/QuestGiverComponent.h"

#include "Components/QuestReceiverComponent.h"


// Sets default values for this component's properties
UQuestGiverComponent::UQuestGiverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

TArray<UQuestData*> UQuestGiverComponent::GetAvailableQuests(UQuestReceiverComponent* Receiver)
{
	TArray<UQuestData*> Quests;
	for (auto Quest : QuestsOffered)
	{
		if (!Receiver->HasQuest(Quest))
		{
			Quests.Add(Quest);
		}
	}
	return Quests;
}


// Called when the game starts
void UQuestGiverComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
