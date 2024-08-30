// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestTargetComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class QUESTS_API UQuestTargetComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UQuestTargetComponent();
	void OnDefeated(AActor * Winner);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Quest)
	int QuestId = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Quest)
	int StageId = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Quest)
	bool DropsLootItem = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Quest)
	float DropRate = 1000;
};
