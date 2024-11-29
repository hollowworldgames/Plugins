// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/PlayerController.h"
#include "SpacePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTER_API ASpacePlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
public :
	virtual void SetGenericTeamId(const FGenericTeamId& NewTeamID) override { TeamId = NewTeamID; }
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }
protected :
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Replicated)
	FGenericTeamId TeamId;
};
