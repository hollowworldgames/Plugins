// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/DataAccessComponent.h"
#include "Records/CharacterRecord.h"
#include "FantasyFixedDataComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FANTASYDATABASE_API UFantasyFixedDataComponent : public UDataAccessComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFantasyFixedDataComponent();
	virtual void LoadActorState(uint64 ActorId) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	FCharacterRecord Record;
};
