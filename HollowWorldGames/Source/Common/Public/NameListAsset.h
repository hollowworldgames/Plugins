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
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
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

	UFUNCTION(BlueprintCallable)
	TArray<FName> GetFirstNames();
	UFUNCTION(BlueprintCallable)
	TArray<FName> GetMiddleNames();
	UFUNCTION(BlueprintCallable)
	TArray<FName> GetLastNames();
	UFUNCTION(BlueprintCallable)
	FName GetRandomFirstName();
	UFUNCTION(BlueprintCallable)
	FName GetRandomMiddleName();
	UFUNCTION(BlueprintCallable)
	FName GetRandomLastName();
};
