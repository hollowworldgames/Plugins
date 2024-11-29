// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/DataCharacter.h"
#include "AbilitySystemInterface.h"
#include "Interactor.h"
#include "Interfaces/GameplayActorInterface.h"
#include "SpaceCharacter.generated.h"

UCLASS()
class CHARACTER_API ASpaceCharacter : public ADataCharacter, public IAbilitySystemInterface,
	public IGameplayActorInterface, public IInteractor
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
	virtual float GetAttributeValue(FGameplayTag Attribute) override; 
	virtual void ApplyEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level, UGameplayAbilitySystemComponent * Source) override;
	virtual void SetAttributes(TArray<FAttributeValue> Attributes) override;
	virtual void OnInteractableAvailable(TScriptInterface<IInteractable> Interactable) override;
	virtual void OnInteractableUnavailable(TScriptInterface<IInteractable> Interactable) override;
	virtual void OnInteractionBegin(TScriptInterface<IInteractable> Interactable) override;
	virtual void OnInteractionEnd(TScriptInterface<IInteractable> Interactable) override;
	virtual APawn * GetInteractingPawn() override { return this; }
	virtual AController * GetInteractingController() override { return Controller; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = Events)
	FAttributeChanged OnAttributeChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Target)
	TObjectPtr<AActor> Target;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = Interaction)
	TScriptInterface<IInteractable> Candidate;
};
