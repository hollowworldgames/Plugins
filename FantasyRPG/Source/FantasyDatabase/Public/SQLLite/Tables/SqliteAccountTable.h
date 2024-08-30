// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "SQLitePreparedStatement.h"
#include "Records/AccountsRecord.h"
#include "UObject/Object.h"
#include "SqliteAccountTable.generated.h"

class FSQLiteDatabase;
UCLASS()
class FANTASYDATABASE_API USqliteAccountTable : public UObject
{
	GENERATED_BODY()
	void Initialize(FSQLiteDatabase * Database);
	TArray<FAccountsRecord> GetAccounts();
	bool LoginAccount(FString UserName, int PasswordHash);
	void DeleteAccount(FString UserName);
	void CreateAccount(FString UserName, int PasswordHash, FString Email);
protected :
	FSQLitePreparedStatement AccountsStatement;
	FSQLitePreparedStatement ValidateStatement;
	FSQLitePreparedStatement AddAccount;
	FSQLitePreparedStatement RemoveAccount;
};
