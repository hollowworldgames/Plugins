// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/QuestMarkerComponent.h"

#include "Components/QuestReceiverComponent.h"


// Sets default values for this component's properties
UQuestMarkerComponent::UQuestMarkerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UQuestMarkerComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(UQuestReceiverComponent * ReceiverComponent = OtherActor->GetComponentByClass<UQuestReceiverComponent>())
	{
		ReceiverComponent->OnQuestMarkerReached(QuestId, StageId, GetOwner());
	}
}


// Called when the game starts
void UQuestMarkerComponent::BeginPlay()
{
	Super::BeginPlay();

	if(GetOwner()->GetNetMode() != NM_Client)
	{
		if(UPrimitiveComponent * PrimitiveComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()))
		{
			PrimitiveComponent->OnComponentBeginOverlap.AddDynamic(this, &UQuestMarkerComponent::OnBeginOverlap);
		}
	}
	
	
}

