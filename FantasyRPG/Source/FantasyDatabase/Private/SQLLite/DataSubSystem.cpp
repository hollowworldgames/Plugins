// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "SQLLite/DataSubSystem.h"

bool UDataSubSystem::Login(FString User, int PasswordHash)
{
	return true;
}

void UDataSubSystem::LogOut()
{
}

TArray<FAccountsRecord> UDataSubSystem::GetAccounts()
{
	return TArray<FAccountsRecord>();
}

TArray<FCharacterRecord> UDataSubSystem::GetPlayerCharacters()
{
	return TArray<FCharacterRecord>();
}

FCharacterRecord UDataSubSystem::GetCharacter(int CharacterId)
{
	return FCharacterRecord();
}

bool UDataSubSystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return false;
}
