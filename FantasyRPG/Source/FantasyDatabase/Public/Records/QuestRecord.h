// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SQLitePreparedStatement.h"
#include "Components/DataAccessComponent.h"
#include "QuestRecord.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FANTASYDATABASE_API FQuestStageRecord
{
	GENERATED_BODY()
	FQuestStageRecord() {}
	FQuestStageRecord(const FSQLitePreparedStatement& Statement);
	FQuestStageRecord(int Stage, int Qty, bool bComplete);
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int StageId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Count;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Complete;
	void WriteToStatement(FSQLitePreparedStatement& Statement) const;
};

USTRUCT(BlueprintType)
struct FANTASYDATABASE_API FQuestRecord : public FRecord
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	int CharacterId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	int QuestId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Stages)
	TArray<FQuestStageRecord> Stages;
	void WriteToStatement(FSQLitePreparedStatement& UpdateQuestStatement);
};

