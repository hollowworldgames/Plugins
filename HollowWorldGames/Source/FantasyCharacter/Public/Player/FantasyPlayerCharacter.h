// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/FantasyCombatCharacter.h"
#include "Components/CharacterInputComponent.h"
#include "FantasyPlayerCharacter.generated.h"

UCLASS()
class FANTASYCHARACTER_API AFantasyPlayerCharacter : public AFantasyCombatCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyPlayerCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void OnRep_PlayerState() override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UCharacterInputComponent> CharacterInputComponent;
};
