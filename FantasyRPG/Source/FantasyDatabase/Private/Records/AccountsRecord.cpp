// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Records/AccountsRecord.h"

FAccountsRecord::FAccountsRecord(const FSQLitePreparedStatement& AccountsStatement)
{
	AccountsStatement.GetColumnValueByIndex(0, AccountId);
	AccountsStatement.GetColumnValueByIndex(1, UserId);
	AccountsStatement.GetColumnValueByIndex(2, PasswordHash);
	AccountsStatement.GetColumnValueByIndex(3, Email);
}
