// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpaceCharacter.h"
#include "SpaceCharacterAI.generated.h"

class USpaceCharacterAttributes;
class UGameplayAbilitySystemComponent;

UCLASS()
class CHARACTER_API ASpaceCharacterAI : public ASpaceCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpaceCharacterAI();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UGameplayAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<USpaceCharacterAttributes> Attributes;
};
