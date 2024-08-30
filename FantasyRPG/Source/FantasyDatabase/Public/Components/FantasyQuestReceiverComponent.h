// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Quests/Public/Components/QuestReceiverComponent.h"
#include "Records/CharacterRecord.h"
#include "Records/QuestRecord.h"
#include "FantasyQuestReceiverComponent.generated.h"


class UDataAccessComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FANTASYDATABASE_API UFantasyQuestReceiverComponent : public UQuestReceiverComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	UFantasyQuestReceiverComponent();
	UFUNCTION()
	void LoadQuests();
	void LoadQuest(const FRecord& QuestRecord);
	void UpdateQuestStage(FQuestState& State, const FRecord& Record);
	virtual void WriteQuestStage(int QuestId, int StageId, bool Complete, int Qty) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
