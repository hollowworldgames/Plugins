// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/QuestReceiverComponent.h"
#include "NativeGameplayTags.h"
#include "Components/CapsuleComponent.h"
#include "Components/QuestGiverComponent.h"
#include "Data/QuestListData.h"
#include "GameFramework/Character.h"
#include "Interfaces/DataComponentInterface.h"
#include "Interfaces/QuestGiverInterface.h"
#include "Trace/Detail/Transport.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(QuestTag, "Quest", "Quest");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(QuestStageTag,"Quest.Stage","Quest Stage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(QuestCompleteTag,"Quest.Complete","Quest Complete");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(QuestNeededTag,"Quest.Needed","Quest Needed");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(QuestActiveTag,"Quest.Active","Quest Active");

bool FQuestStageState::OnMarkerReached(AActor* Actor)
{
	if(Objective == EQuestStageObjective::Reach)
	{
		Complete = true;
		return Complete;
	}
	return false;
}

bool FQuestStageState::OnTargetDefeated(const UQuestTargetComponent* Target)
{
	if(Objective == EQuestStageObjective::Defeat)
	{
		if(Target)
		{
			Count++;
			Complete = Count >= Needed;
			return Complete;
		}
	}
	return false;
}

bool FQuestStageState::OnReceiveItem(AActor* Actor)
{
	if(Objective == EQuestStageObjective::Acquire)
	{
		Complete = true;
		return Complete;
	}
	return false;
}

bool FQuestStageState::OnGiveItem(AActor* Actor)
{
	if(Objective == EQuestStageObjective::GiveTo)
	{
		Complete = true;
		return Complete;
	}
	return false;
}

void FQuestStageState::Update(bool bComplete, int Qty)
{
	Complete = bComplete;
	Count = Qty;
}

void FQuestState::OnMarkerReached(int StageId, AActor* Actor)
{
	if(Stages[StageId].OnMarkerReached(Actor))
	{
		NextStage();
	}
}

void FQuestState::NextStage()
{
	ActiveStage++;
	if(ActiveStage < QuestData->Stages.Num())
	{
		ActiveStageId = QuestData->Stages[ActiveStage].StageId;
	}
	else
	{
		//done
		OnComplete.Broadcast(QuestData->QuestId);
	}
}

void FQuestState::OnTargetDefeated(int StageId, const UQuestTargetComponent* Target)
{
	if(Stages[StageId].OnTargetDefeated(Target))
	{
		NextStage();
	}
}

FQuestStage FQuestState::GetCurrentStage() const
{
	if(ActiveStage < QuestData->Stages.Num())
	{
		return QuestData->Stages[ActiveStage];
	}
	return FQuestStage();
}

void FQuestState::OnQuestReceiveItem(int StageId, AActor* Giver)
{
	if(Stages[StageId].OnReceiveItem(Giver))
	{
		NextStage();
	}
}

void FQuestState::OnQuestGiveItem(int StageId, AActor* Receiver)
{
	if(Stages[StageId].OnGiveItem(Receiver))
	{
		NextStage();
	}
}

void FQuestState::UpdateStage(int StageId, bool bComplete, int Qty)
{
	Stages[StageId].Update(bComplete, Qty);
}

void FQuestState::SetStageIndex()
{
	int Index = 0;
	for(FQuestStage& Stage : QuestData->Stages)
	{
		if(Stage.StageId == ActiveStageId)
		{
			ActiveStage = Index;
			return;
		}
		Index++;
	}
}

bool FQuestState::HasQuest(UQuestData* Quest) const
{
	
	return false;
}

// Sets default values for this component's properties
UQuestReceiverComponent::UQuestReceiverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UQuestReceiverComponent::OnQuestAccepted_Server_Implementation(const UQuestData* Quest)
{
	
	OnQuestAccepted_Client(Quest);
}

void UQuestReceiverComponent::OnQuestAccepted_Client_Implementation(const UQuestData* Quest)
{
	if (Giver)
	{
		Giver->Accept(nullptr, Quest);
	}
}

void UQuestReceiverComponent::OnQuestTargetDefeated(int QuestId, int StageId, TObjectPtr<UQuestTargetComponent> Target)
{
	QuestStates[QuestId].OnTargetDefeated(StageId, Target);
	OnQuestTargetDefeated_Client(QuestId, StageId, Target);
	FQuestState& State = QuestStates[QuestId];
	WriteQuestStage(QuestId, StageId, State.Stages[StageId].Complete, State.Stages[StageId].Count);
}

void UQuestReceiverComponent::OnQuestMarkerReached(int QuestId, int StageId, AActor* Marker)
{
	QuestStates[QuestId].OnMarkerReached(StageId, Marker);
	OnQuestMarkerReached_Client(QuestId, StageId, Marker);
	FQuestState& State = QuestStates[QuestId];
	WriteQuestStage(QuestId, StageId, State.Stages[StageId].Complete, State.Stages[StageId].Count);
}

void UQuestReceiverComponent::OnQuestReceiveItem(int QuestId, int StageId, AActor* QuestGiver)
{
	QuestStates[QuestId].OnQuestReceiveItem(StageId, QuestGiver);
	OnQuestReceiveItem_Client(QuestId, StageId, QuestGiver);
	FQuestState& State = QuestStates[QuestId];
	WriteQuestStage(QuestId, StageId, State.Stages[StageId].Complete, State.Stages[StageId].Count);
}

void UQuestReceiverComponent::OnQuestGiveItem(int QuestId, int StageId, AActor* Receiver)
{
	QuestStates[QuestId].OnQuestGiveItem(StageId, Receiver);
	OnQuestGiveItem_Client_Implementation(QuestId, StageId, Receiver);
	FQuestState& State = QuestStates[QuestId];
	WriteQuestStage(QuestId, StageId, State.Stages[StageId].Complete, State.Stages[StageId].Count);
}

void UQuestReceiverComponent::OnQuestGiverAvailable(TScriptInterface<IQuestGiverInterface> NewGiver)
{
	Giver = NewGiver;
}

void UQuestReceiverComponent::OnQuestGiverUnavailable(TScriptInterface<IQuestGiverInterface> RemoveGiver)
{
	if(Giver == RemoveGiver)
	{
		Giver = nullptr;
	}
}

void UQuestReceiverComponent::UpdateQuestState(int QuestId, int StageId, bool Complete, int Qty, bool Active)
{
	if(!QuestStates.Contains(QuestId))
	{
		FQuestState &State = QuestStates.Add(QuestId, FQuestState());
		State.UpdateStage(StageId, Complete, Qty);
		if(Active)
		{
			State.ActiveStageId = StageId;
			State.SetStageIndex();
		}
		State.QuestData = QuestList->GetQuest(QuestId);
	}
	else
	{
		QuestStates[QuestId].UpdateStage(StageId, Complete, Qty);
		if(Active)
		{
			QuestStates[QuestId].ActiveStageId = StageId;
			QuestStates[QuestId].SetStageIndex();
		}
	}
}

void UQuestReceiverComponent::LoadQuestState(const FRecord& Record)
{
	int QuestId = Record.GetIntValue(QuestTag);
	int StageId = Record.GetIntValue(QuestStageTag);
	bool Complete = Record.GetBoolValue(QuestCompleteTag);
	int Qty = Record.GetIntValue(QuestNeededTag);
	bool Active = Record.GetBoolValue(QuestActiveTag);
	UpdateQuestState(QuestId, StageId, Complete, Qty, Active);
	UpdateQuestState_Client(QuestId, StageId, Complete, Qty, Active);
}

void UQuestReceiverComponent::WriteQuestStage(int QuestId, int StageId, bool Complete, int Qty)
{
	if (ensure(IsValid(GetOwner())) && GetOwner()->HasAuthority()) //should only be called on the server
	{
		if (TScriptInterface<IDataComponentInterface> DataInterface = TObjectPtr<AActor>(GetOwner()))
		{
			if (UDataAccessComponent * DataComponent = DataInterface->GetDataAccessComponent())
			{
				FRecord Record;
				Record.AddNumericValue(QuestTag, QuestId);
				Record.AddNumericValue(QuestStageTag, StageId);
				Record.AddNumericValue(QuestCompleteTag, Complete);
				Record.AddNumericValue(QuestNeededTag, Qty);
				Record.AddNumericValue(QuestActiveTag, false);
				DataComponent->WriteRecord(Record);
			}
		}
	}
}

bool UQuestReceiverComponent::HasQuest(const TObjectPtr<UQuestData>& Quest)
{
	return QuestStates.Contains(Quest->QuestId);
}

void UQuestReceiverComponent::UpdateQuestState_Client_Implementation(int QuestId, int StageId, bool Complete, int Qty, bool Active)
{
	UpdateQuestState(QuestId, StageId, Complete, Qty, Active);
}

void UQuestReceiverComponent::OnQuestTargetDefeated_Client_Implementation(int QuestId, int StageId,
                                                                          const UQuestTargetComponent* Target)
{
	QuestStates[QuestId].OnTargetDefeated(StageId, Target);
}

void UQuestReceiverComponent::OnQuestMarkerReached_Client_Implementation(int QuestId, int StageId, AActor* Marker)
{
	QuestStates[QuestId].OnMarkerReached(StageId, Marker);
}

void UQuestReceiverComponent::OnQuestReceiveItem_Client_Implementation(int QuestId, int StageId, AActor* QuestGiver)
{
	QuestStates[QuestId].OnQuestReceiveItem(StageId, QuestGiver);
}

void UQuestReceiverComponent::OnQuestGiveItem_Client_Implementation(int QuestId, int StageId, AActor* Receiver)
{
	QuestStates[QuestId].OnQuestGiveItem(StageId, Receiver);
}

// Called when the game starts
void UQuestReceiverComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


