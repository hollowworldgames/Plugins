// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "FantasyDataAccessComponent.h"
#include "GameplayTagContainer.h"
#include "Components/DataAccessComponent.h"
#include "Records/CharacterRecord.h"

#include "FantasyStandaloneDataAccessComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FANTASYDATABASE_API UFantasyStandaloneDataAccessComponent : public UFantasyDataAccessComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFantasyStandaloneDataAccessComponent();
	virtual void LoadActorState(uint64 ActorId) override;
	virtual void SaveActorState() override;
	virtual void WriteRecord(FRecord& Record) override;
	virtual float SetFloatAttribute(FString Attribute, float Value) override;
	virtual FString SetStringAttribute(FString Attribute, FString Value) override;
	virtual int SetIntAttribute(FString Attribute, int Value) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
