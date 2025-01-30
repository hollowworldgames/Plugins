// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestGiverComponent.generated.h"


class UQuestReceiverComponent;
class UQuestData;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class QUESTS_API UQuestGiverComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UQuestGiverComponent();
	TArray<UQuestData*> GetAvailableQuests(UQuestReceiverComponent * Receiver);
	UFUNCTION(BlueprintImplementableEvent)
	void DoQuestStart(UQuestData * Quest);
	UFUNCTION(BlueprintImplementableEvent)
	void DoInteractStart();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
	TArray<TObjectPtr<UQuestData>> QuestsOffered;
};
