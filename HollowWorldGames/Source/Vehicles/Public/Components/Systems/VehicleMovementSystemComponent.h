// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/Systems/SystemComponent.h"
#include "VehicleMovementSystemComponent.generated.h"

USTRUCT()
struct FVehicleRotationInput
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere,  Category=Input)
	float Pitch = 0;
	UPROPERTY(VisibleAnywhere, Category=Input)
	float Yaw = 0;
	UPROPERTY(VisibleAnywhere, Category=Input)
	float Roll = 0;
	void AddPitch(float NewPitch);
	void AddYaw(float NewYaw);
	void AddRoll(float NewRoll);
	float ConsumePitch();
	float ConsumeYaw();
	float ConsumeRoll();
};

USTRUCT()
struct FVehicleTranslationInput
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere,  Category=Input)
	float Lift = 0;
	UPROPERTY(VisibleAnywhere, Category=Input)
	float Slide = 0;
	UPROPERTY(VisibleAnywhere, Category=Input)
	float Thrust = 0;
	void AddLift(float NewLift);
	void AddSlide(float NewSlide);
	void AddThrust(float NewThrust);
	float ConsumeLift();
	float ConsumeSlide();
	float ConsumeThrust();
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class VEHICLES_API UVehicleMovementSystemComponent : public USystemComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UVehicleMovementSystemComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AddRotationPitch(float Pitch);
	void AddRotationYaw(float Yaw);
	void AddRotationRoll(float Roll);
	void AddTranslationLift(float Lift);
	void AddTranslationSlide(float Slide);
	void AddTranslationThrust(float Thrust);
	virtual void Simulate(float DeltaTime);
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Replicated, Category="Input")
	FVehicleRotationInput RotationInput;
	UPROPERTY(VisibleAnywhere, Replicated, Category="Input")
	FVehicleTranslationInput TranslationInput;
};

