// (c) Copyright 2023 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Actors/ViewablePawn.h"
#include "Components/StationComponent.h"
#include "GameFramework/Pawn.h"
#include "StationPawn.generated.h"

class UAbilitySystemComponent;
class UMotionControllerComponent;
class UTextRenderComponent;
class UBoxComponent;

UCLASS()
class SPACECRAFT_API AStationPawn : public AViewablePawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AStationPawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void SetOwningShip(TObjectPtr<AActor> OwningShip);
	UAbilitySystemComponent * GetOccupantAbilitySystemComponent() const;
	void SetInteractor(const TObjectPtr<UInteractableComponent> NewInteractor);
	void ExitStation();
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void EnterStation(ACharacter * Character);
	UFUNCTION(BlueprintImplementableEvent)
	void BeginExitStation(ACharacter * Character);
	UFUNCTION(BlueprintCallable)
    void ExitComplete();
	UFUNCTION()
    void OnBeginInteract(ACharacter* Character, UInteractableComponent* Component);
	UFUNCTION()
    void OnCompleteInteract(ACharacter* Character, UInteractableComponent* Component);
	UFUNCTION()
	void OnInteractorEnter(ACharacter* Character, UInteractableComponent* Component);
	UFUNCTION()
	void OnInteractorExit(ACharacter* Character, UInteractableComponent* Component);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Owner)
	TObjectPtr<AActor> OwningShip;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<USceneComponent> Root;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UViewPointComponent> Seat;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<class UCameraComponent> Camera;
	UPROPERTY(Transient, BlueprintReadOnly, Category=Occupant)
	TObjectPtr<ACharacter> Occupant;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Component)
	TObjectPtr<UMotionControllerComponent> LeftHand;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Component)
	TObjectPtr<UMotionControllerComponent> RightHand;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Component)
	TObjectPtr<UInteractableComponent> EntryComponent;
};
