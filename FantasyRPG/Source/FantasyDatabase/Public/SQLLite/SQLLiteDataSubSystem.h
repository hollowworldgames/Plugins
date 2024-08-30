// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataSubSystem.h"
#include "Records/AccountsRecord.h"
#include "Records/CharacterRecord.h"
#include "SQLiteCore/Public/SQLiteDatabase.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SQLLiteDataSubSystem.generated.h"

/**
 * 
 */
UCLASS()
class FANTASYDATABASE_API USQLLiteDataSubSystem : public UDataSubSystem
{
	GENERATED_BODY()
public :
    virtual bool Login(FString User, int PasswordHash) override;
	virtual void LogOut() override;
	virtual TArray<FAccountsRecord> GetAccounts() override;
	virtual TArray<FCharacterRecord> GetPlayerCharacters() override;
	virtual FCharacterRecord GetCharacter(int CharacterId) override;
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	void WriteCharacterRecord(int CharacterId, FCharacterRecord Record);
	void WriteQuestRecord(int QuestId, FQuestStageRecord Record);
	void WriteSkillRecord(int CharacterId, FSkillRecord Skill);
	TArray<FSkillRecord> GetCharacterSkills(uint64 CharacterId);
	TArray<FQuestRecord> GetQuests(uint64 CharacterId);
protected :
	FString FilePath = TEXT("");
	FSQLiteDatabase * Database;
};
