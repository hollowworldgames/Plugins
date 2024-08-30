// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "Records/QuestRecord.h"
#include "Components/DataAccessComponent.h"
#include "CharacterRecord.generated.h"


UENUM(BlueprintType)
enum class EGender : uint8
{
	Male UMETA(DisplayName = "Male"),
	Female UMETA(DisplayName = "Female")
};

USTRUCT(BlueprintType)
struct FANTASYDATABASE_API FSkillRecord : public FRecord
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	int CharacterId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	FGameplayTag SkillId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	float Level = 0;
};

USTRUCT(BlueprintType)
struct FANTASYDATABASE_API FCharacterRecord  : public FRecord
{
	GENERATED_BODY()
	FCharacterRecord(int AccountId, FString CharacterName, float Level, FVector Location, int World, int Race, EGender Gender, FString Class);
	FCharacterRecord(FSQLitePreparedStatement& Statement);
	FCharacterRecord() {}
	void WriteToStatement(FSQLitePreparedStatement& Statement);
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
    int CharacterId = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	int AccountId = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	FString CharacterName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	float Level = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	int World;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	int Race;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Class)
	FName Class;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data);
	EGender Gender;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Skills)
	TArray<FSkillRecord> Skills;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Quests)
	TArray<FQuestRecord> Quests;
};
