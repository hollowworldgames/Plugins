// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Definitions/GeneratorDefinition.h"
#include "FlightModelComponent.generated.h"


class UControlSurfaceDefinition;
class ULiftSurfaceDefinition;
class UEngineDefinition;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FLIGHT_API UFlightModelComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFlightModelComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintPure)
	float GetEngineRPM(FGameplayTag Tag) const;
	UFUNCTION(BlueprintPure)
	float GetEngineTemperature(FGameplayTag Tag) const;
	UFUNCTION(BlueprintPure)
	UEngineDefinition * GetEngine(FGameplayTag Tag) const;
	UFUNCTION(BlueprintPure)
	TArray<UEngineDefinition*> GetEngines() const;
	UFUNCTION(BlueprintPure)
	float GetEngineFuelFlow() const;
	UFUNCTION(BlueprintPure)
	ULiftSurfaceDefinition * GetLiftSurface(FGameplayTag Tag) const;
	UFUNCTION(BlueprintPure)
	UControlSurfaceDefinition * GetControlSurface(FGameplayTag Tag) const;
	void AddPitchInput(float NewPitch);
	float PeekPitchInput() const;
	float ConsumePitchInput();
	void AddRollInput(float NewRoll);
	float PeekRollInput() const;
	float ConsumeRollInput();
	void AddRudderInput(float NewRudder);
	float PeekRudderInput() const;
	float ConsumeRudderInput();
	void AddThrottleInput(float NewThrottle);
	float PeekThrottleInput() const;
	float ConsumeThrottleInput();
	void AddFlapsInput(float NewFlap);
	float PeekFlapsInput() const;
	float ConsumeFlapsInput();
	void AddSlatsInput(float NewSlats);
	float PeekSlatsInput() const;
	float ConsumeSlatsInput();
	void AddBrakeInput(float newBrake);
	float PeekBrakeInput() const;
	float ConsumeBrakeInput();
	UFUNCTION(BlueprintPure)
	float GetAirPressure() const;
	UFUNCTION(BlueprintPure)
	float GetAirSpeed() const;
	UFUNCTION(BlueprintPure)
	float GetVerticalVelocity() const;
	UFUNCTION(BlueprintPure)
	float GetSideSlip() const;
	UFUNCTION(BlueprintPure)
	float GetAltitude() const;
	UFUNCTION(BlueprintPure)
	float GetPitch() const;
	UFUNCTION(BlueprintPure)
	float GetRoll() const;
	UFUNCTION(BlueprintPure)
	float GetYaw() const;
	UFUNCTION(BlueprintPure)
	float GetRadarAltitude() const; 
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Engine)
	TArray<TSubclassOf<UEngineDefinition>> EngineClasses;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Engine)
	TArray<TObjectPtr<UEngineDefinition>> Engines;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Surfaces)
	TArray<TSubclassOf<ULiftSurfaceDefinition>> SurfaceClasses;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Surfaces)
	TArray<TObjectPtr<ULiftSurfaceDefinition>> Surfaces;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Surfaces)
	TArray<TSubclassOf<class UControlSurfaceDefinition>> ControlClasses;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Surfaces)
	TArray<TObjectPtr<UControlSurfaceDefinition>> Controls;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Controls)
	float Pitch = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Controls)
	float Roll = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Controls)
	float Rudder = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Controls)
	float Throttle = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Controls)
	float Flaps = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Controls)
	float FlapPosition = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Controls)
	float MaxFlaps = 5;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Controls)
	float Slats = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Controls)
	float Brake = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	FScalableFloat AirPressureAtAltitude;
};
