// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Components/ActorComponent.h"
#include "SpaceFlightModelComponent.generated.h"

USTRUCT(BlueprintType)
struct FThrusterPoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Thruster Point")
	FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Thruster Point")
	FName Bone;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Thruster Point")
	FVector Force;
	void ApplyForce(UPrimitiveComponent* Root) const;
};

USTRUCT(BlueprintType)
struct FThrusterSet
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Thruster")
	float Target = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Thruster")
	float Throttle = 0;
	void UpdateThrottleValue(float DeltaTime, float ChangeRate);
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPACECRAFT_API USpaceFlightModelComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USpaceFlightModelComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	void AddPitchInput(float Input);
	float PeekPitchInput() const;
	float ConsumePitchInput();
	void AddYawInput(float Input);
	float PeekYawInput() const;
	float ConsumeYawInput();
	void AddRollInput(float Input);
	float PeekRollInput() const;
	float ConsumeRollInput();
	void AddLiftInput(float Input);
	float PeekLiftInput() const;
	float ConsumeLiftInput();
	void AddSlideInput(float Input);
	float PeekSlideInput() const;
	float ConsumeSlideInput();
	void AddThrottleInput(float Input);
	float PeekThrottleInput() const;
	float ConsumeThrottleInput();
protected:
	void OnThrustChanged(const FOnAttributeChangeData& OnAttributeChangeData);
	void OnMaxRCSThrustChanged(const FOnAttributeChangeData& OnAttributeChangeData);
	// Called when the game starts
	virtual void BeginPlay() override;
	float Pitch = 0;
	float Yaw = 0;
	float Roll = 0;
	float Lift = 0;
	float Slide = 0;
	float Throttle = 0;
	float Thrust = 0;
	float MaxRCSThrust = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Thrusters)
	FThrusterPoint Front;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Thrusters)
	FThrusterPoint Rear;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Thrusters)
	FThrusterPoint Left;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Thrusters)
	FThrusterPoint Right;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Thrusters)
	TArray<FThrusterPoint> Engines;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Throttles)
	FThrusterSet PitchThrusters;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Throttles)
	FThrusterSet RollThrusters;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Throttles)
	FThrusterSet YawThrusters;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Throttles)
	FThrusterSet LiftThrusters;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Throttles)
	FThrusterSet SlideThrusters;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Throttles)
	FThrusterSet MainThrusters;
};
