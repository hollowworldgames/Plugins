// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCraft/Components/SpaceFlightModelComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "ConverterStatics.h"
#include "UtilityStatics.h"
#include "SpaceCraft/Gameplay/SpaceCraftAttributes.h"


void FThrusterPoint::ApplyForce(UPrimitiveComponent* Root) const
{
	Root->AddForceAtLocationLocal(Force, Location, Bone);
}

void FThrusterSet::UpdateThrottleValue(float DeltaTime, float ChangeRate)
{
	Throttle = UUtilityStatics::MoveTowardTargetValue(Throttle, Target, ChangeRate, DeltaTime, -1 , 1);
}

// Sets default values for this component's properties
USpaceFlightModelComponent::USpaceFlightModelComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpaceFlightModelComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpaceFlightModelComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UPrimitiveComponent * Root = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	UAbilitySystemComponent * AbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner());
	if(AbilitySystemComponent && Root && Root->IsSimulatingPhysics())
	{
		bool Found = false;
		float ThrustPercent = AbilitySystemComponent->GetGameplayAttributeValue(USpaceCraftAttributes::GetEngineAgilityAttribute(), Found);
		float Thrust = AbilitySystemComponent->GetGameplayAttributeValue(USpaceCraftAttributes::GetEngineThrustAttribute(), Found);
		if(Found)
		{
			PitchThrusters.Target = ConsumePitchInput();
			PitchThrusters.UpdateThrottleValue(DeltaTime, 0.5f);
			float PitchThrust = Thrust * ThrustPercent * PitchThrusters.Throttle;
			Thrust -= PitchThrust;
			Front.Force = FVector::UpVector * UConverterStatics::KNewtonsToUNewtons(PitchThrust);
			Rear.Force = -FVector::UpVector * UConverterStatics::KNewtonsToUNewtons(PitchThrust);
			
			RollThrusters.Target = ConsumeRollInput();
			RollThrusters.UpdateThrottleValue(DeltaTime, 0.5f);
			float RollThrust = Thrust * ThrustPercent * RollThrusters.Throttle;
			Thrust -= RollThrust;
			Right.Force = UConverterStatics::KNewtonsToUNewtonsVector(FVector::UpVector * RollThrust);
			Left.Force = UConverterStatics::KNewtonsToUNewtonsVector(-FVector::UpVector * RollThrust);

			YawThrusters.Target = ConsumeYawInput();
			YawThrusters.UpdateThrottleValue(DeltaTime, 0.5f);
			float YawThrust = Thrust * ThrustPercent * YawThrusters.Throttle;
			Thrust -= YawThrust;
			Front.Force += FVector::RightVector * UConverterStatics::KNewtonsToUNewtons(YawThrust);
			Rear.Force += -FVector::RightVector * UConverterStatics::KNewtonsToUNewtons(YawThrust);

			LiftThrusters.Target = ConsumeLiftInput();
			LiftThrusters.UpdateThrottleValue(DeltaTime, 0.5f);
			float LiftThrust = Thrust * ThrustPercent * LiftThrusters.Throttle;
			Thrust -= LiftThrust;
			Front.Force += FVector::UpVector * UConverterStatics::KNewtonsToUNewtons(LiftThrust);
			Rear.Force += FVector::UpVector * UConverterStatics::KNewtonsToUNewtons(LiftThrust);

			SlideThrusters.Target = ConsumeSlideInput();
			SlideThrusters.UpdateThrottleValue(DeltaTime, 0.5f);
			float SlideThrust = UConverterStatics::KNewtonsToUNewtons(Thrust * ThrustPercent * SlideThrusters.Throttle);
			Thrust -= SlideThrust;
			Front.Force += FVector::RightVector * UConverterStatics::KNewtonsToUNewtons(SlideThrust);
			Rear.Force += FVector::RightVector * UConverterStatics::KNewtonsToUNewtons(SlideThrust);

			Front.ApplyForce(Root);
			Rear.ApplyForce(Root);
			Left.ApplyForce(Root);
			Right.ApplyForce(Root);

			MainThrusters.UpdateThrottleValue(DeltaTime, 0.5f);
			FVector Main = FVector::ForwardVector * UConverterStatics::KNewtonsToUNewtons(Thrust * MainThrusters.Throttle);
			
			for(int Index = 0;Index < Engines.Num();Index++)
			{
				Engines[Index].Force = Main;
				Engines[Index].ApplyForce(Root);
			}
		}
	}
}

void USpaceFlightModelComponent::AddPitchInput(float Input)
{
	Pitch += Input;
}

float USpaceFlightModelComponent::PeekPitchInput() const
{
	return Pitch;
}

float USpaceFlightModelComponent::ConsumePitchInput()
{
	float OutputPitch = Pitch;
	Pitch = 0;
	return OutputPitch;
}

void USpaceFlightModelComponent::AddYawInput(float Input)
{
	Yaw += Input;
}

float USpaceFlightModelComponent::PeekYawInput() const
{
	return Yaw;
}

float USpaceFlightModelComponent::ConsumeYawInput()
{
	float OutputYaw = Yaw;
	Yaw = 0;
	return OutputYaw;
}

void USpaceFlightModelComponent::AddRollInput(float Input)
{
	Roll += Input;
}

float USpaceFlightModelComponent::PeekRollInput() const
{
	return Roll;
}

float USpaceFlightModelComponent::ConsumeRollInput()
{
	float OutputRoll = Roll;
	Roll = 0;
	return OutputRoll;
}

void USpaceFlightModelComponent::AddLiftInput(float Input)
{
	Lift += Input;
}

float USpaceFlightModelComponent::PeekLiftInput() const
{
	return Lift;
}

float USpaceFlightModelComponent::ConsumeLiftInput()
{
	float OutputLift = Lift;
	Lift = 0;
	return OutputLift;
}

void USpaceFlightModelComponent::AddSlideInput(float Input)
{
	Slide += Input;
}

float USpaceFlightModelComponent::PeekSlideInput() const
{
	return Slide;
}

float USpaceFlightModelComponent::ConsumeSlideInput()
{
	float OutputSlide = Slide;
	Slide = 0;
	return OutputSlide;
}

void USpaceFlightModelComponent::AddThrottleInput(float Input)
{
	Throttle += Input;
}

float USpaceFlightModelComponent::PeekThrottleInput() const
{
	return Throttle;
}

float USpaceFlightModelComponent::ConsumeThrottleInput()
{
	float OutputThrottle = Throttle;
	Throttle = 0;
	return OutputThrottle;
}
