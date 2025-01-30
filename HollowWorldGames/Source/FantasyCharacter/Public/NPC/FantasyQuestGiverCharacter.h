// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/FantasyCharacterBase.h"
#include "Components/QuestGiverComponent.h"
#include "FantasyQuestGiverCharacter.generated.h"

UCLASS()
class FANTASYCHARACTER_API AFantasyQuestGiverCharacter : public AFantasyCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyQuestGiverCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UQuestGiverComponent> QuestComponent;
};
