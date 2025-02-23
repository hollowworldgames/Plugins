// Copyright (c) 2024 Hollow World Games llc All Rights Reserved


#include "Components/Systems/VehicleMovementSystemComponent.h"

void FVehicleRotationInput::AddPitch(float NewPitch)
{
	Pitch += NewPitch;
}

void FVehicleRotationInput::AddYaw(float NewYaw)
{
	Yaw += NewYaw;
}

void FVehicleRotationInput::AddRoll(float NewRoll)
{
	Roll += NewRoll;
}

float FVehicleRotationInput::ConsumePitch()
{
	float OutPitch = Pitch;
	Pitch = 0;
	return OutPitch;
}

float FVehicleRotationInput::ConsumeYaw()
{
	float OutYaw = Yaw;
	Yaw = 0;
	return OutYaw;
}

float FVehicleRotationInput::ConsumeRoll()
{
	float OutRoll = Roll;
	Roll = 0;
	return OutRoll;
}

void FVehicleTranslationInput::AddLift(float NewLift)
{
}

void FVehicleTranslationInput::AddSlide(float NewSlide)
{
}

void FVehicleTranslationInput::AddThrust(float NewThrust)
{
}

float FVehicleTranslationInput::ConsumeLift()
{
	float OutLift = Lift;
	Lift = 0;
	return OutLift;
}

float FVehicleTranslationInput::ConsumeSlide()
{
	float OutSlide = Slide;
	Slide = 0;
	return OutSlide;
}

float FVehicleTranslationInput::ConsumeThrust()
{
	float OutThrust = Thrust;
	Thrust = 0;
	return OutThrust;
}

// Sets default values for this component's properties
UVehicleMovementSystemComponent::UVehicleMovementSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UVehicleMovementSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UVehicleMovementSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UVehicleMovementSystemComponent::AddRotationPitch(const float Pitch)
{
	RotationInput.AddPitch(Pitch);
}

void UVehicleMovementSystemComponent::AddRotationYaw(const float Yaw)
{
	RotationInput.AddYaw(Yaw);
}

void UVehicleMovementSystemComponent::AddRotationRoll(const float Roll)
{
	RotationInput.AddRoll(Roll);
}

void UVehicleMovementSystemComponent::AddTranslationLift(float Lift)
{
	TranslationInput.AddLift(Lift);
}

void UVehicleMovementSystemComponent::AddTranslationSlide(float Slide)
{
	TranslationInput.AddSlide(Slide);
}

void UVehicleMovementSystemComponent::AddTranslationThrust(float Thrust)
{
	TranslationInput.AddThrust(Thrust);
}


void UVehicleMovementSystemComponent::Simulate(float DeltaTime)
{
}

void UVehicleMovementSystemComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
