// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "StationPawn.h"
#include "PilotStationPawn.generated.h"

class USpaceFlightModelComponent;
class UInputAction;
class UInputMappingContext;

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
	void OnGearToggle();
	void OnStartToggle();
	UFUNCTION(Server, Unreliable)
	void OnPitchYaw_Server(float Pitch, float Yaw);
	UFUNCTION(Server, Unreliable)
	void OnRoll_Server(float RollValue);
	UFUNCTION(Server, Unreliable)
	void OnLiftSlide_Server(float Lift, float Slide);
	UFUNCTION(Server, Unreliable)
	void OnSetThrottle_Server(float ThrottleInputValue);
	UFUNCTION(Server, Reliable)
	void OnGearToggle_Server();
	UFUNCTION(Server, Reliable)
	void OnStartToggle_Server();
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
	TObjectPtr<UInputAction> GearToggle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<UInputAction> StartToggle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<UInputMappingContext> Context;
	float ThrottleValue = 0;
};



