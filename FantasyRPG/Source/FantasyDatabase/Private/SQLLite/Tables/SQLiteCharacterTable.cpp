// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "SQLLite/Tables/SQLiteCharacterTable.h"

void USQLiteCharacterTable::Initialize(FSQLiteDatabase* Database)
{
	if(!CharactersStatement.Create(*Database, TEXT("Select * from Characters where AccountId = $AccountId")))
	{
		ensure(false);
	}
	if(!CharacterStatement.Create(*Database, TEXT("Select * from Characters where CharacterId = $CharacterId")))
	{
		ensure(false);
	}
	if(!AddCharacterStatement.Create(*Database, TEXT("Insert into Characters (AccountId, CharacterName ) Value (@AccountId, CharacterName)")))
	{
		ensure(false);
	}
	if(!UpdateCharacterStatement.Create(*Database, TEXT("Update Characters Set where CharacterId = &CharacterId")))
	{
		ensure(false);
	}
	if(!DeleteCharacterStatement.Create(*Database, TEXT("Delete from Characters where CharacterId = $CharacterId")))
	{
		ensure(false);
	}
}

TArray<FCharacterRecord> USQLiteCharacterTable::GetCharacters(int AccountId)
{
	TArray<FCharacterRecord> Characters;
	CharactersStatement.SetBindingValueByIndex(0, AccountId);
	if(CharactersStatement.Execute())
	{
		while(CharactersStatement.Step() == ESQLitePreparedStatementStepResult::Row)
		{
			Characters.Add(FCharacterRecord(CharactersStatement));
		}
	}
	return Characters;
}

FCharacterRecord USQLiteCharacterTable::GetCharacter(int CharacterId)
{
	return FCharacterRecord();
}

void USQLiteCharacterTable::AddCharacter(int AccountId, FCharacterRecord Record)
{
}

void USQLiteCharacterTable::UpdateCharacter(FCharacterRecord Record)
{
}

void USQLiteCharacterTable::DeleteCharacter(int CharacterId)
{
}


bool USQLiteCharacterTable::ValidCharacterName(FString CharacterName)
{
	return false;
}
