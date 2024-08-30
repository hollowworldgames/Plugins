// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "SQLLite/Tables/SQLiteQuestTable.h"

void USQLiteQuestTable::Initialize(FSQLiteDatabase* Database)
{
}

TArray<FQuestRecord> USQLiteQuestTable::GetQuestRecords(int CharacterId)
{
	TArray<FQuestRecord> Records;
	return Records;
}

void USQLiteQuestTable::UpdateQuestRecord(int CharacterId, FQuestRecord Record)
{
	Record.WriteToStatement(UpdateQuestStatement);
	if(UpdateQuestStatement.Execute())
	{
		
	}
}

void USQLiteQuestTable::DeleteQuestRecord(int CharacterId)
{
	DeleteQuestsStatement.SetBindingValueByIndex(0, CharacterId);
	if(!DeleteQuestsStatement.Execute())
	{
		ensure(false);
	}
}
