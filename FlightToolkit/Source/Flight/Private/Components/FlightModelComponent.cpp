// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/FlightModelComponent.h"

#include "ConverterStatics.h"
#include "Aircraft/AircraftPawn.h"
#include "Components/FuelSystemComponent.h"
#include "Definitions/Engines/EngineDefinition.h"
#include "Definitions/Surfaces/ControlSurfaceDefinition.h"
#include "Definitions/Surfaces/LiftSurfaceDefinition.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values for this component's properties
UFlightModelComponent::UFlightModelComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFlightModelComponent::BeginPlay()
{
	Super::BeginPlay();

	UFuelSystemComponent * FuelSystemComponent = GetOwner()->GetComponentByClass<UFuelSystemComponent>();
	if(ensure(FuelSystemComponent))
	{
		for(TSubclassOf<UEngineDefinition> EngineClass : EngineClasses)
		{
			TObjectPtr<UEngineDefinition> Definition = NewObject<UEngineDefinition>(EngineClass);
			FuelSystemComponent->AddConsumer(Definition);
			Engines.Add(Definition);
		}

		for(TSubclassOf<ULiftSurfaceDefinition> LiftSurfaceClass : SurfaceClasses)
		{
			TObjectPtr<ULiftSurfaceDefinition> Definition = NewObject<ULiftSurfaceDefinition>(LiftSurfaceClass);
			Surfaces.Add(Definition);
		}

		for(TSubclassOf<UControlSurfaceDefinition> ControlSurfaceClass : ControlClasses)
		{
			TObjectPtr<UControlSurfaceDefinition> Definition = NewObject<UControlSurfaceDefinition>(ControlSurfaceClass);
			Controls.Add(Definition);
			if(ULiftSurfaceDefinition * SurfaceDefinition = GetLiftSurface(Definition->GetParentSurface()))
			{
				SurfaceDefinition->AddControl(Definition);
			}
		}
	}
}


// Called every frame
void UFlightModelComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AAircraftPawn * Aircraft = GetOwner<AAircraftPawn>();
	if(ensure(Aircraft))
	{
		//update controls
		float CurrentPitch = ConsumePitchInput();
		float CurrentRoll = ConsumeRollInput();
		float CurrentRudder = ConsumeRudderInput();
		float CurrentThrottle = ConsumeThrottleInput();
		float CurrentSlats = ConsumeSlatsInput();
		float CurrentFlaps = ConsumeFlapsInput();
		FlapPosition = FMath::Clamp(FlapPosition + CurrentFlaps,0, MaxFlaps)
;		float CurrentBrakes = ConsumeBrakeInput();
		FVector Velocity = Aircraft->GetVelocity();
		FVector Wind = -Velocity;
		float Airspeed =Velocity.Length();
		float AirPressure = GetAirPressure();

		//update Engines
		for(TObjectPtr<UEngineDefinition> Engine : Engines)
		{
			if(Engine)
			{
				Engine->SetThrottle(CurrentThrottle);
				Engine->TickEngine(DeltaTime, AirPressure, Airspeed);
			}
		}
		
		//Update Controls
		for(TObjectPtr<UControlSurfaceDefinition> Control : Controls)
		{
			switch(Control->GetControlType())
			{
			case EControlType::Elevator :
				{
					Control->SetControlValue(CurrentPitch);
					break;
				}
			case EControlType::Aileron :
				{
					Control->SetControlValue(CurrentRoll);
					break;
				}
			case EControlType::Rudder :
				{
					Control->SetControlValue(CurrentRudder);
					break;
				}
			case EControlType::Slat :
				{
					Control->SetControlValue(CurrentSlats);
					break;
				}
			case EControlType::Flap :
				{
					Control->SetControlValue(FlapPosition);
					break;
				}
			case EControlType::Brake :
				{
					Control->SetControlValue(CurrentBrakes);
					break;
				}
			case EControlType::Canard :
				{
					Control->SetControlValue(-CurrentPitch); //canards are backward
					break;
				}
			case EControlType::Taileron :
				{
					break;
				}
			case EControlType::Flaperon:
				{
					break;
				}
			}
			Control->TickControl(AirPressure, Airspeed, Wind, Aircraft->GetActorForwardVector(), Aircraft->GetActorUpVector());
		}
		
		//Update Surfaces
		for(TObjectPtr<ULiftSurfaceDefinition> Surface : Surfaces)
		{
			Surface->TickSurface(AirPressure, Wind , Aircraft->GetActorForwardVector(),
				GetOwner()->GetActorUpVector(), Airspeed);
		}
	}
}

float UFlightModelComponent::GetEngineRPM(FGameplayTag Tag) const
{
	for(TObjectPtr<UEngineDefinition> Engine : Engines)
	{
		if(Engine->GetComponentTag().MatchesTag(Tag))
		{
			return Engine->GetRPM();
		}
	}
	return 0;
}

float UFlightModelComponent::GetEngineTemperature(FGameplayTag Tag) const
{
	for(TObjectPtr<UEngineDefinition> Engine : Engines)
	{
		if(Engine->GetComponentTag().MatchesTag(Tag))
		{
			return Engine->GetTemperature();
		}
	}
	return 0;
}

UEngineDefinition* UFlightModelComponent::GetEngine(FGameplayTag Tag) const
{
	for(TObjectPtr<UEngineDefinition> Engine : Engines)
	{
		return Engine;
	}
	return nullptr;
}

TArray<UEngineDefinition*> UFlightModelComponent::GetEngines() const
{
	TArray<UEngineDefinition*> Output;
	for(TObjectPtr<UEngineDefinition> Engine : Engines)
	{
		Output.Add(Engine);
	}
	return Output;
}

float UFlightModelComponent::GetEngineFuelFlow() const
{
	for(TObjectPtr<UEngineDefinition> Engine : Engines)
	{
		return Engine->GetFuelFlow();
	}
	return 0;
}

ULiftSurfaceDefinition* UFlightModelComponent::GetLiftSurface(FGameplayTag Tag) const
{
	for(TObjectPtr<ULiftSurfaceDefinition> LiftSurface : Surfaces)
	{
		if(LiftSurface->GetComponentId().MatchesTag(Tag))
		{
			return LiftSurface;
		}
	}
	return nullptr;
}

UControlSurfaceDefinition* UFlightModelComponent::GetControlSurface(FGameplayTag Tag) const
{
	for(TObjectPtr<UControlSurfaceDefinition> Surface : Controls)
	{
		if(Surface->GetComponentId().MatchesTag(Tag))
		{
			return Surface;
		}
	}
	return nullptr;
}

void UFlightModelComponent::AddPitchInput(float NewPitch)
{
	Pitch += NewPitch;
}

float UFlightModelComponent::PeekPitchInput() const
{
	return Pitch;
}

float UFlightModelComponent::ConsumePitchInput()
{
	float NewPitch = Pitch;
	Pitch = 0;
	return NewPitch;
}

void UFlightModelComponent::AddRollInput(float NewRoll)
{
	Roll += NewRoll;
}

float UFlightModelComponent::PeekRollInput() const
{
	return Roll;
}

float UFlightModelComponent::ConsumeRollInput()
{
	float NewRoll = Roll;
	Roll = 0;
	return NewRoll;
}

void UFlightModelComponent::AddRudderInput(float NewRudder)
{
	Rudder += NewRudder;
}

float UFlightModelComponent::PeekRudderInput() const
{
	return Rudder;
}

float UFlightModelComponent::ConsumeRudderInput()
{
	float NewRudder = Rudder;
	Rudder = 0;
	return NewRudder;
}

void UFlightModelComponent::AddThrottleInput(float NewThrottle)
{
	Throttle += NewThrottle;
}

float UFlightModelComponent::PeekThrottleInput() const
{
	return Throttle;
}

float UFlightModelComponent::ConsumeThrottleInput()
{
	float NewThrottle = Throttle;
	Throttle = 0;
	return NewThrottle;
}

void UFlightModelComponent::AddFlapsInput(float NewFlap)
{
	Flaps += NewFlap;
}

float UFlightModelComponent::PeekFlapsInput() const
{
	return Flaps;
}

float UFlightModelComponent::ConsumeFlapsInput()
{
	float NewFlaps = Flaps;
	Flaps = 0;
	return NewFlaps;
}

void UFlightModelComponent::AddSlatsInput(float NewSlats)
{
	Slats += NewSlats;
}

float UFlightModelComponent::PeekSlatsInput() const
{
	return Slats;
}

float UFlightModelComponent::ConsumeSlatsInput()
{
	float NewSlats = Slats;
	Slats = 0;
	return NewSlats;
}

void UFlightModelComponent::AddBrakeInput(float newBrake)
{
	Brake += newBrake;
}

float UFlightModelComponent::PeekBrakeInput() const
{
	return Brake;
}

float UFlightModelComponent::ConsumeBrakeInput()
{
	float NewBrake = Brake;
	Brake = 0;
	return NewBrake;
}

float UFlightModelComponent::GetAirPressure() const
{
	if(GetOwner())
	{
		return AirPressureAtAltitude.GetValueAtLevel(UConverterStatics::UUnitsToKm(GetOwner()->GetActorLocation().Z));
	}
	return 0.0f;
}

float UFlightModelComponent::GetAirSpeed() const
{
	if(GetOwner())
	{
		return GetOwner()->GetVelocity().Length();
	}
	return 0;
}

float UFlightModelComponent::GetVerticalVelocity() const
{
	if(GetOwner())
	{
		return GetOwner()->GetVelocity().Z;
	}
	return 0;
}

float UFlightModelComponent::GetSideSlip() const
{
	if(GetOwner())
	{
		FVector VelocityRelative = GetOwner()->GetActorTransform().InverseTransformVector(GetOwner()->GetVelocity());
		return VelocityRelative.Y;
	}
	return 0;
}

float UFlightModelComponent::GetAltitude() const
{
	if(GetOwner())
	{
		return GetOwner()->GetActorLocation().Z;
	}
	return 0;
}

float UFlightModelComponent::GetPitch() const
{
	if(GetOwner())
	{
		FRotator Rotator = GetOwner()->GetActorRotation();
		double Other = 0;
		return UKismetMathLibrary::FMod(UConverterStatics::AngleToSigned(Rotator.Pitch),90, Other);
	}
	return 0;
}

float UFlightModelComponent::GetRoll() const
{
	if(GetOwner())
	{
		FRotator Rotator = GetOwner()->GetActorRotation();
		double Other = 0;
		return UConverterStatics::AngleToSigned(Rotator.Roll);
	}
	return 0;
}

float UFlightModelComponent::GetYaw() const
{
	if(GetOwner())
	{
		return GetOwner()->GetActorRotation().Yaw;
	}
	return 0;
}

float UFlightModelComponent::GetRadarAltitude() const
{
	FHitResult HitResult;
	if(GetWorld()->LineTraceSingleByChannel(HitResult, GetOwner()->GetActorLocation(),
		GetOwner()->GetActorLocation() + (-GetOwner()->GetActorUpVector() * 10000000), ECC_GameTraceChannel1))
	{
		return HitResult.Distance;
	}
	return 0;
}

