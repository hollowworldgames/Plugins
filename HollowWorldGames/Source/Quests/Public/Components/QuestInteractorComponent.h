// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestInteractorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractedWith, AActor*, actor);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class QUESTS_API UQuestInteractorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UQuestInteractorComponent();
	void OnInteracted(AActor * Interactor) const;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Quest)
	int QuestId = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Quest)
	int StageId = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Quest)
	bool Give = true;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FInteractedWith OnInteractedWith;
};
