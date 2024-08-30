// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "FantasyPlayerCharacter.h"
#include "FantasyPlayerTopDownCharacter.generated.h"

UCLASS()
class FANTASYCHARACTER_API AFantasyPlayerTopDownCharacter : public AFantasyPlayerCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyPlayerTopDownCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
