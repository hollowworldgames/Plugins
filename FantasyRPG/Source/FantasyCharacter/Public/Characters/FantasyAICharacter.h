// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "FantasyCharacterBase.h"
#include "FantasyAICharacter.generated.h"

class URPGAttributeSet;

UCLASS()
class FANTASYCHARACTER_API AFantasyAICharacter : public AFantasyCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyAICharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<URPGAttributeSet> Attributes;
};
