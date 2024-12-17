// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QuestData.generated.h"

UENUM()
enum class EQuestStageObjective : uint8
{
	Reach,
	Acquire,
	Loot,
	Defeat,
	GiveTo,
};

USTRUCT(BlueprintType)
struct FQuestStage
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FString ShortDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FString LongDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FString StartText;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FString StopText;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	TObjectPtr<USoundClass> StartSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	TObjectPtr<USoundClass> StopSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	EQuestStageObjective Objective;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	int StageId = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	int CountNeeded = 0;
};

UCLASS(Blueprintable, BlueprintType)
class QUESTS_API UQuestData : public UDataAsset
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	TArray<FQuestStage> Stages;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FString StartText;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FString StopText;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	TObjectPtr<USoundClass> StartSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	TObjectPtr<USoundClass> StopSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	int QuestId = 0;
};
