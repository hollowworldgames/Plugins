// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SQLitePreparedStatement.h"
#include "Components/DataAccessComponent.h"
#include "AccountsRecord.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FANTASYDATABASE_API FAccountsRecord : public FRecord
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Data)
	int AccountId = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Data)
	FString UserId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Data)
	int PasswordHash;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Data)
	FString Email;
	FAccountsRecord() = default;
	explicit FAccountsRecord(const FSQLitePreparedStatement& AccountsStatement);
};
