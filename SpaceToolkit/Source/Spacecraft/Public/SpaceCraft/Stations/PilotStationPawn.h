// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "StationPawn.h"
#include "PilotStationPawn.generated.h"

class USpaceFlightModelComponent;
class UInputAction;
class UInputContext;

UCLASS()
class SPACECRAFT_API APilotStationPawn : public AStationPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APilotStationPawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnPitchYaw(const FInputActionValue& InputActionValue);
	void OnRoll(const FInputActionValue& InputActionValue);
	void OnLiftSlide(const FInputActionValue& InputActionValue);
	void OnThrottle(const FInputActionValue& InputActionValue);
	void OnThrottleIncrement(const FInputActionValue& InputActionValue);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void SetOwningShip(TObjectPtr<AActor> OwningShip) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<USpaceFlightModelComponent> SpaceFlightModelComponent; 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<UInputAction> PitchYaw;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<UInputAction> Roll;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<UInputAction> LiftSlide;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<UInputAction> Throttle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<UInputAction> ThrottleIncrement;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<UInputMappingContext> Context;
	float ThrottleValue = 0;
};
