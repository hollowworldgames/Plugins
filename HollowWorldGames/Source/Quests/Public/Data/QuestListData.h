// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QuestListData.generated.h"

class UQuestData;
/**
 * 
 */
UCLASS()
class QUESTS_API UQuestListData : public UDataAsset
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category=Quests)
	TArray<TObjectPtr<UQuestData>> Quests;
	TObjectPtr<UQuestData> GetQuest(int QuestId);
};
