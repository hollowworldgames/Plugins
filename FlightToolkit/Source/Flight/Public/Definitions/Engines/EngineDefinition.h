// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DamageableDefinition.h"
#include "Interfaces/Consumer.h"
#include "Interfaces/Source.h"
#include "EngineDefinition.generated.h"

UENUM()
enum class EEngineState : uint8
{
	Starting,
	Running,
	Stopping,
	Off
};

UCLASS()
class FLIGHT_API UEngineDefinition : public UDamageableDefinition, public IConsumer
{
	GENERATED_BODY()
public :
	float GetOutputForce() const { return Force; }
	virtual float GetRotation() { return 0; }
	virtual FVector GetRotationForce() { return FVector::Zero(); }
	virtual bool HasRotation() const { return false; }
	float GetRPM() const { return RPM; }
	float GetTemperature() const { return Temperature; }
	float GetFuelFlow() const { return Fuel; }
	EEngineState GetEngineState() const { return State; }
	virtual void Start();
	virtual void Stop();
	virtual void TickEngine(float DeltaTime, float AirPressure, float AirSpeed);
	virtual void TickEngine(float DeltaTime, float AirPressure, TObjectPtr<USkeletalMeshComponent> Root);
	virtual void ApplyForce(TObjectPtr<USkeletalMeshComponent> Root);
	virtual EResource GetNeededResource() override;
	virtual float GetNeeded() override;
	virtual float Provided(float Amount) override;
	virtual FGameplayTag GetComponentTag() override;
	virtual void SetThrottle(float NewThrottle);
	virtual void SetBoost(float newBoost);
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float Force = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float RPM = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float Temperature = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float Fuel = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	EEngineState State = EEngineState::Off;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float Throttle = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float ThrottleTarget = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FScalableFloat FuelFromThrottle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float Boost = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float BoostTarget = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FName Bone;
};


