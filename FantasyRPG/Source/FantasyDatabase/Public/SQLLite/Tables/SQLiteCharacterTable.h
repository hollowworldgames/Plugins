// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "SQLitePreparedStatement.h"
#include "Records/CharacterRecord.h"
#include "UObject/Object.h"
#include "SQLiteCharacterTable.generated.h"

/**
 * 
 */
UCLASS()
class FANTASYDATABASE_API USQLiteCharacterTable : public UObject
{
	GENERATED_BODY()
public :
	void Initialize(FSQLiteDatabase * Database);
	TArray<FCharacterRecord> GetCharacters(int AccountId);
	FCharacterRecord GetCharacter(int CharacterId);
	void AddCharacter(int AccountId, FCharacterRecord Record);
	void UpdateCharacter(FCharacterRecord Record);
	void DeleteCharacter(int CharacterId);
	bool ValidCharacterName(FString CharacterName);
protected :
	FSQLitePreparedStatement CharactersStatement;
	FSQLitePreparedStatement CharacterStatement;
	FSQLitePreparedStatement UpdateCharacterStatement;
	FSQLitePreparedStatement AddCharacterStatement;
	FSQLitePreparedStatement DeleteCharacterStatement;
};

