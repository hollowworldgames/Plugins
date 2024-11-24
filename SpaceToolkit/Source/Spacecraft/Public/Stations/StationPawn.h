// (c) Copyright 2023 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Actors/ViewablePawn.h"
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
protected:
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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<class UInteractableComponent> EntryComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UTextRenderComponent> EntryText;
	UPROPERTY(Transient, BlueprintReadOnly, Category=Occupant)
	TObjectPtr<ACharacter> Occupant;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Component)
	TObjectPtr<UMotionControllerComponent> LeftHand;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Component)
	TObjectPtr<UMotionControllerComponent> RightHand;
};
