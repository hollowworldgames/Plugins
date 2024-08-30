// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/QuestTargetComponent.h"
#include "UtilityStatics.h"
#include "Components/QuestReceiverComponent.h"


// Sets default values for this component's properties
UQuestTargetComponent::UQuestTargetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQuestTargetComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UQuestTargetComponent::OnDefeated(AActor* Winner)
{
	if(UQuestReceiverComponent * QuestComponent = Winner->GetComponentByClass<UQuestReceiverComponent>())
	{
		if(DropsLootItem && UUtilityStatics::Roll1000(DropRate))
		{
			QuestComponent->OnQuestReceiveItem(QuestId, StageId, GetOwner());
		}
		QuestComponent->OnQuestTargetDefeated(QuestId, StageId, this);
	}
	
}

