// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "SpaceAIController.generated.h"

UCLASS()
class CHARACTER_API ASpaceAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpaceAIController();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void SetGenericTeamId(const FGenericTeamId& NewTeamID) override { TeamID = NewTeamID; }
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamID; }
protected:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Replicated, Category = "Team")
	FGenericTeamId TeamID;
};
