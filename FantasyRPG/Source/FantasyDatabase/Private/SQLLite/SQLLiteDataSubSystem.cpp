// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "SQLLite/SQLLiteDataSubSystem.h"

bool USQLLiteDataSubSystem::Login(FString User, int PasswordHash)
{
	return Super::Login(User, PasswordHash);
}

void USQLLiteDataSubSystem::LogOut()
{
	Super::LogOut();
}

TArray<FAccountsRecord> USQLLiteDataSubSystem::GetAccounts()
{
	return Super::GetAccounts();
}

TArray<FCharacterRecord> USQLLiteDataSubSystem::GetPlayerCharacters()
{
	return Super::GetPlayerCharacters();
}

FCharacterRecord USQLLiteDataSubSystem::GetCharacter(int CharacterId)
{
	return Super::GetCharacter(CharacterId);
}

bool USQLLiteDataSubSystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void USQLLiteDataSubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Database = new FSQLiteDatabase();
	if(Database->Open(*FilePath))
	{
		
	}
}

void USQLLiteDataSubSystem::Deinitialize()
{
	Super::Deinitialize();
	if(Database && Database->IsValid())
	{
		
	}
}

void USQLLiteDataSubSystem::WriteCharacterRecord(int CharacterId, FCharacterRecord Record)
{
	
}

void USQLLiteDataSubSystem::WriteQuestRecord(int QuestId, FQuestStageRecord Record)
{
	
}

void USQLLiteDataSubSystem::WriteSkillRecord(int CharacterId, FSkillRecord Skill)
{
	
}

TArray<FSkillRecord> USQLLiteDataSubSystem::GetCharacterSkills(uint64 CharacterId)
{
	TArray<FSkillRecord> Skills;
	return Skills;
}

TArray<FQuestRecord> USQLLiteDataSubSystem::GetQuests(uint64 CharacterId)
{
	TArray<FQuestRecord> Quests;
	return Quests;
}
