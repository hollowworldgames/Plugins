// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/FantasyMountCharacter.h"
#include "FantasyPlayerMountCharacter.generated.h"

class UFantasyMountInputComponent;

UCLASS()
class FANTASYCHARACTER_API AFantasyPlayerMountCharacter : public AFantasyMountCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyPlayerMountCharacter();

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Component)
	TObjectPtr<UFantasyMountInputComponent> MountInputComponent;
};
