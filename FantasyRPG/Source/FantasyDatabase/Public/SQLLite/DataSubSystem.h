// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Records/CharacterRecord.h"
#include "Records/AccountsRecord.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DataSubSystem.generated.h"

/**
 * 
 */
UCLASS()
class FANTASYDATABASE_API UDataSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public :
	virtual bool Login(FString User, int PasswordHash);
	virtual void LogOut();
	virtual TArray<FAccountsRecord> GetAccounts();
	virtual TArray<FCharacterRecord> GetPlayerCharacters();
	virtual FCharacterRecord GetCharacter(int CharacterId);
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
};
