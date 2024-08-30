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
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString ShortDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString LongDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString StartText;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString StopText;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USoundClass> StartSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USoundClass> StopSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EQuestStageObjective Objective;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int StageId = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int CountNeeded = 0;
};

UCLASS(Blueprintable, BlueprintType)
class QUESTS_API UQuestData : public UDataAsset
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FQuestStage> Stages;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString StartText;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString StopText;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USoundClass> StartSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USoundClass> StopSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int QuestId = 0;
};
