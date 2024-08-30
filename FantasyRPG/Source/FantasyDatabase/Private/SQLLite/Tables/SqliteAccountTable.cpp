// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "SQLLite/Tables/SqliteAccountTable.h"

void USqliteAccountTable::Initialize(FSQLiteDatabase* Database)
{
	if(!AccountsStatement.Create(*Database, TEXT("select * from Accounts")))
	{
		ensure(false);
	}
	if(!ValidateStatement.Create(*Database, TEXT("select PasswordHash from Accounts where AccountName = $UserId")))
	{
		ensure(false);
	}
	if(!AddAccount.Create(*Database, TEXT("insert into Accounts (AccountName, PasswordHash, EmailAddress) Values ($UserId, $PasswordHash, $EmailAddress)")))
	{
		ensure(false);
	}
	if(!RemoveAccount.Create(*Database, TEXT("Delete from Accounts where AccountId = $AccountId")))
	{
		ensure(false);
	}
}

TArray<FAccountsRecord> USqliteAccountTable::GetAccounts()
{
	TArray<FAccountsRecord> Records;
	if(AccountsStatement.Execute())
	{
		while(AccountsStatement.Step() == ESQLitePreparedStatementStepResult::Row)
		{
			FAccountsRecord Record(AccountsStatement);
			Records.Add(Record);
		}
	}
	AccountsStatement.Reset();
	return Records;
}

bool USqliteAccountTable::LoginAccount(FString UserName, int PasswordHash)
{
	ValidateStatement.SetBindingValueByIndex(0, UserName);
	if(ValidateStatement.Execute())
	{
		if(ValidateStatement.Step() == ESQLitePreparedStatementStepResult::Row)
		{
			int Hash = 0;
			ValidateStatement.GetColumnValueByIndex(0, Hash);
			return Hash == PasswordHash;
		}
	}
	ValidateStatement.Reset();
	return false;
}

void USqliteAccountTable::DeleteAccount(FString UserName)
{
	RemoveAccount.SetBindingValueByIndex(0, UserName);
	if(!RemoveAccount.Execute())
	{
		ensure(false);
	}
	RemoveAccount.Reset();
}

void USqliteAccountTable::CreateAccount(FString UserName, int PasswordHash, FString Email)
{
	AddAccount.SetBindingValueByIndex(0, UserName);
	AddAccount.SetBindingValueByIndex(1, PasswordHash);
	AddAccount.SetBindingValueByIndex(2, Email);
	if(!AddAccount.Execute())
	{
		ensure(false);
	}
	AddAccount.Reset();
}
