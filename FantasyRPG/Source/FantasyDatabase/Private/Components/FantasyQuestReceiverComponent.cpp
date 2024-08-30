// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/FantasyQuestReceiverComponent.h"

#include "Components/FantasyDataAccessComponent.h"
#include "Data/QuestListData.h"
#include "Records/QuestRecord.h"


// Sets default values for this component's properties
UFantasyQuestReceiverComponent::UFantasyQuestReceiverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UFantasyQuestReceiverComponent::LoadQuests()
{
	if(UDataAccessComponent * DataAccessComponent = GetOwner()->GetComponentByClass<UDataAccessComponent>())
	{
		TArray<FRecord> Quests = DataAccessComponent->GetRecordsOfType(1);
		for(FRecord& Record : Quests)
		{
			LoadQuest(Record);
		}
	}
	
}


// Called when the game starts
void UFantasyQuestReceiverComponent::BeginPlay()
{
	Super::BeginPlay();

	if(UDataAccessComponent * DataAccessComponent = GetOwner()->GetComponentByClass<UDataAccessComponent>())
	{
		DataAccessComponent->GetDataLoaded().AddDynamic(this, &UFantasyQuestReceiverComponent::LoadQuests);
	}
	
}

void UFantasyQuestReceiverComponent::LoadQuest(const FRecord& QuestRecord)
{
	int QuestId = QuestRecord.NumericValues["Quest"].Value;
	if(!QuestStates.Contains(QuestId))
	{
		FQuestState& State = QuestStates.Add(QuestId);
		State.QuestData = QuestList->GetQuest(QuestId);
		for(FQuestStage Stage : State.QuestData->Stages)
		{
			FQuestStageState& StageState = State.Stages.Add(Stage.StageId);
			StageState.Objective = Stage.Objective;
			StageState.Needed = Stage.CountNeeded;
			StageState.Count = 0;
			StageState.Complete = false;
		}
		UpdateQuestStage(State, QuestRecord);		
	}
	else
	{
		UpdateQuestStage(QuestStates[QuestId], QuestRecord);
	}
}

void UFantasyQuestReceiverComponent::UpdateQuestStage(FQuestState& State, const FRecord& Record)
{
	int StageId = Record.NumericValues["Stage"].Value;
	FQuestStageState& StageState = State.Stages[StageId];
	StageState.Count = Record.NumericValues["Count"].Value;
	StageState.Complete = Record.NumericValues["Complete"].Value == 1;
}

void UFantasyQuestReceiverComponent::WriteQuestStage(int QuestId, int StageId, bool Complete, int Qty)
{
	UFantasyDataAccessComponent * FantasyDataAccessComponent = GetOwner()->GetComponentByClass<UFantasyDataAccessComponent>();
	if(ensure(FantasyDataAccessComponent) && GetOwner()->HasAuthority())
	{
		FRecord Record;
		Record.RecordType = 1;
		Record.NumericValues["Quest"] = FNumericValue(QuestId);
		Record.NumericValues["Stage"] = FNumericValue(StageId);
		Record.NumericValues["Count"] = FNumericValue(Qty);
		Record.NumericValues["Complete"] = FNumericValue(Complete ? 1 : 0);
		FantasyDataAccessComponent->WriteRecord(Record);
	}
}

