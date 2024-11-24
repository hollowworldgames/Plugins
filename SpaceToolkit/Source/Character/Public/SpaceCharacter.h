// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/DataCharacter.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/GameplayActorInterface.h"
#include "SpaceCharacter.generated.h"

UCLASS()
class CHARACTER_API ASpaceCharacter : public ADataCharacter, public IAbilitySystemInterface, public IGameplayActorInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpaceCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;
	virtual FAttributeChanged& GetAttributeChangedNotify();
	virtual TScriptInterface<IGameplayActorInterface> GetAbilityTarget();
	virtual float GetAttributeValue(FGameplayTag Attribute);
	virtual void ApplyEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level, UGameplayAbilitySystemComponent * Source);
	virtual void SetAttributes(TArray<FAttributeValue> Attributes);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = Events)
	FAttributeChanged OnAttributeChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Target)
	TObjectPtr<AActor> Target;
};
