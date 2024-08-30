// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "SQLitePreparedStatement.h"
#include "Records/QuestRecord.h"
#include "UObject/Object.h"
#include "SQLiteQuestTable.generated.h"

/**
 * 
 */
UCLASS()
class FANTASYDATABASE_API USQLiteQuestTable : public UObject
{
	GENERATED_BODY()
public :
	void Initialize(FSQLiteDatabase * Database);
	TArray<FQuestRecord> GetQuestRecords(int CharacterId);
	void UpdateQuestRecord(int CharacterId, FQuestRecord Record);
	void DeleteQuestRecord(int CharacterId);
protected :
	FSQLitePreparedStatement CharacterQuestStatement;
	FSQLitePreparedStatement UpdateQuestStatement;
	FSQLitePreparedStatement DeleteQuestsStatement;
};
