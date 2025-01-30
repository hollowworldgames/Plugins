// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "QuestTargetComponent.h"
#include "Components/ActorComponent.h"
#include "Data/QuestData.h"
#include "DataAccess/Public/Components/DataAccessComponent.h"
#include "QuestReceiverComponent.generated.h"

class UQuestListData;
class IQuestGiverInterface;
class UQuestTargetComponent;
class UQuestData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FQuestComplete, int , QuestId);

USTRUCT()
struct FQuestStageState
{
	GENERATED_BODY()
	UPROPERTY()
	int Count = 0;
	UPROPERTY()
	int Needed = 0;
	UPROPERTY()
	bool Complete = false;
	UPROPERTY()
	EQuestStageObjective Objective;
	bool OnMarkerReached(AActor * Actor);
	bool OnTargetDefeated(const UQuestTargetComponent* Target);
	bool OnReceiveItem(AActor * Actor);
	bool OnGiveItem(AActor * Actor);
	void Update(bool bComplete, int Qty);
};

USTRUCT(BlueprintType)
struct FQuestState
{
	GENERATED_BODY()
	UPROPERTY()
	TObjectPtr<UQuestData> QuestData;
	UPROPERTY()
	TMap<int, FQuestStageState> Stages;
	void OnMarkerReached(int StageId, AActor* Actor);
	void NextStage();
	void OnTargetDefeated(int StageId, const UQuestTargetComponent* Target);
	FQuestStage GetCurrentStage() const;
	void OnQuestReceiveItem(int StageId, AActor* Giver);
	void OnQuestGiveItem(int StageId, AActor* Receiver);
	void UpdateStage(int StageId, bool bComplete, int Qty);
	void SetStageIndex();
	bool HasQuest(UQuestData * Quest) const;
	UPROPERTY()
	int ActiveStage = 0;
	UPROPERTY()
	int ActiveStageId = 0;
	UPROPERTY()
	FQuestComplete OnComplete;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class QUESTS_API UQuestReceiverComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UQuestReceiverComponent();
	void OnQuestTargetDefeated(int QuestId, int StageId, TObjectPtr<UQuestTargetComponent> Target);
	void OnQuestMarkerReached(int QuestId, int StageId, AActor * Marker);
	void OnQuestReceiveItem(int QuestId, int StageId, AActor * QuestGiver);
	void OnQuestGiveItem(int QuestId, int StageId, AActor * Receiver);
	UFUNCTION(Server, Reliable)
	void OnQuestAccepted_Server(const UQuestData * Quest);
	UFUNCTION(Client, Reliable)
	void OnQuestAccepted_Client(const UQuestData * Quest);
	UFUNCTION(BlueprintCallable, Category = "Quest")
	void OnQuestGiverAvailable(TScriptInterface<IQuestGiverInterface> NewGiver);
	UFUNCTION(BlueprintCallable, Category = "Quest")
	void OnQuestGiverUnavailable(TScriptInterface<IQuestGiverInterface> RemovedGiver);
	UFUNCTION(BlueprintPure, Category = "Quest")
	TScriptInterface<IQuestGiverInterface> GetCurrentGiver() const { return Giver; }
	void UpdateQuestState(int QuestId, int StageId, bool Complete, int Qty, bool Active);
	virtual void LoadQuestState(const FRecord& Record);
	virtual void WriteQuestStage(int QuestId, int StageId, bool Complete, int Qty);
	bool HasQuest(const TObjectPtr<UQuestData>& Quest);

protected:
	UFUNCTION(Client, Reliable)
	void UpdateQuestState_Client(int QuestId, int StageId, bool Complete, int Qty, bool Active);
	UFUNCTION(Client, Reliable)
	void OnQuestTargetDefeated_Client(int QuestId, int StageId,const UQuestTargetComponent * Target);
	UFUNCTION(Client, Reliable)
	void OnQuestMarkerReached_Client(int QuestId, int StageId, AActor * Marker);
	UFUNCTION(Client, Reliable)
	void OnQuestReceiveItem_Client(int QuestId, int StageId, AActor * QuestGiver);
	UFUNCTION(Client, Reliable)
	void OnQuestGiveItem_Client(int QuestId, int StageId, AActor * Receiver);
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY()
	TMap<int, FQuestState> QuestStates;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	TScriptInterface<IQuestGiverInterface> Giver;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	TObjectPtr<UQuestListData> QuestList;
};



