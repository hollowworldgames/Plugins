// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NameListAsset.generated.h"

USTRUCT(BlueprintType)
struct FNameTableRow : public FTableRowBase
{
	GENERATED_BODY()
	public :
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Names")
	FName Name;
};

UCLASS(BlueprintType)
class COMMON_API UNameListAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UDataTable* First;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UDataTable* Middle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UDataTable* Last;

	UFUNCTION(BlueprintCallable, Category = "Name List")
	TArray<FName> GetFirstNames();
	UFUNCTION(BlueprintCallable, Category = "Name List")
	TArray<FName> GetMiddleNames();
	UFUNCTION(BlueprintCallable, Category = "Name List")
	TArray<FName> GetLastNames();
	UFUNCTION(BlueprintCallable, Category = "Name List")
	FName GetRandomFirstName();
	UFUNCTION(BlueprintCallable, Category = "Name List")
	FName GetRandomMiddleName();
	UFUNCTION(BlueprintCallable, Category = "Name List")
	FName GetRandomLastName();
};
