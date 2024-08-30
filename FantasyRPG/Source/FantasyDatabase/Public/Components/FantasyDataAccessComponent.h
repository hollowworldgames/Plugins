// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/DataAccessComponent.h"
#include "Records/CharacterRecord.h"
#include "Records/QuestRecord.h"
#include "FantasyDataAccessComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FANTASYDATABASE_API UFantasyDataAccessComponent : public UDataAccessComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFantasyDataAccessComponent();
	virtual void LoadActorState(uint64 ActorId) override;
	virtual void SaveActorState() override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
