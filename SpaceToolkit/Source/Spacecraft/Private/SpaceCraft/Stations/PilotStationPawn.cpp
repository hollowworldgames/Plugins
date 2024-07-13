// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCraft/Stations/PilotStationPawn.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "SpaceCraft/Components/SpaceFlightModelComponent.h"
#include "SpaceCraft/Interface/SpaceCraftInterface.h"


// Sets default values
APilotStationPawn::APilotStationPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APilotStationPawn::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(Context, 0);
		}
	}
}

// Called every frame
void APilotStationPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	OnSetThrottle_Server(ThrottleValue);
}

void APilotStationPawn::OnPitchYaw(const FInputActionValue& InputActionValue)
{
	FVector2d PitchYawValue = InputActionValue.Get<FVector2d>();
	OnPitchYaw_Server(PitchYawValue.Y, PitchYawValue.X);
}

void APilotStationPawn::OnRoll(const FInputActionValue& InputActionValue)
{
	float RollValue = InputActionValue.Get<float>();
	if(SpaceFlightModelComponent)
	{
		SpaceFlightModelComponent->AddRollInput(RollValue);
	}
}

void APilotStationPawn::OnLiftSlide(const FInputActionValue& InputActionValue)
{
	FVector2d LiftSlideValue = InputActionValue.Get<FVector2d>();
	if(SpaceFlightModelComponent)
	{
		SpaceFlightModelComponent->AddLiftInput(LiftSlideValue.Y);
		SpaceFlightModelComponent->AddSlideInput(LiftSlideValue.X);
	}
}

void APilotStationPawn::OnThrottle(const FInputActionValue& InputActionValue)
{
	float ThrottleInputValue = InputActionValue.Get<float>();
	ThrottleValue = ThrottleInputValue;
}

void APilotStationPawn::OnThrottleIncrement(const FInputActionValue& InputActionValue)
{
	float ThrottleInputValue = InputActionValue.Get<float>();
	ThrottleValue += ThrottleInputValue * 0.03f;
}

void APilotStationPawn::OnGearToggle()
{
	OnGearToggle_Server();
}

void APilotStationPawn::OnGearToggle_Server_Implementation()
{
	if(OwningShip && OwningShip->Implements<USpaceCraftInterface>())
	{
		ISpaceCraftInterface * SpaceCraftInterface = Cast<ISpaceCraftInterface>(OwningShip);
		if(ensure(SpaceCraftInterface))
		{
			SpaceCraftInterface->ToggleGear();
		}
	}
}

void APilotStationPawn::OnStartToggle()
{
	OnStartToggle_Server();
}

void APilotStationPawn::OnPitchYaw_Server_Implementation(float Pitch, float Yaw)
{
	if(SpaceFlightModelComponent)
	{
		SpaceFlightModelComponent->AddPitchInput(Pitch);
		SpaceFlightModelComponent->AddYawInput(Yaw);
	}
}

void APilotStationPawn::OnRoll_Server_Implementation(float RollValue)
{
	if(SpaceFlightModelComponent)
	{
		SpaceFlightModelComponent->AddRollInput(RollValue);
	}
}

void APilotStationPawn::OnLiftSlide_Server_Implementation(float Lift, float Slide)
{
	if(SpaceFlightModelComponent)
	{
		SpaceFlightModelComponent->AddLiftInput(Lift);
		SpaceFlightModelComponent->AddSlideInput(Slide);
	}
}

void APilotStationPawn::OnSetThrottle_Server_Implementation(float ThrottleInputValue)
{
	if(SpaceFlightModelComponent)
	{
		SpaceFlightModelComponent->AddThrottleInput(ThrottleInputValue);
	}
}

void APilotStationPawn::OnStartToggle_Server_Implementation()
{
	if(OwningShip && OwningShip->Implements<USpaceCraftInterface>())
	{
		ISpaceCraftInterface * SpaceCraftInterface = Cast<ISpaceCraftInterface>(OwningShip);
		if(ensure(SpaceCraftInterface))
		{
			SpaceCraftInterface->TogglePower();
		}
	}
}

// Called to bind functionality to input
void APilotStationPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(PitchYaw, ETriggerEvent::Triggered, this, &APilotStationPawn::OnPitchYaw);
		EnhancedInputComponent->BindAction(Roll, ETriggerEvent::Triggered, this, &APilotStationPawn::OnRoll);
		EnhancedInputComponent->BindAction(LiftSlide, ETriggerEvent::Triggered, this, &APilotStationPawn::OnLiftSlide);
		EnhancedInputComponent->BindAction(Throttle, ETriggerEvent::Triggered, this, &APilotStationPawn::OnThrottle);
		EnhancedInputComponent->BindAction(ThrottleIncrement, ETriggerEvent::Triggered, this, &APilotStationPawn::OnThrottleIncrement);
		EnhancedInputComponent->BindAction(GearToggle, ETriggerEvent::Completed, this, &APilotStationPawn::OnGearToggle);
		EnhancedInputComponent->BindAction(StartToggle, ETriggerEvent::Completed, this, &APilotStationPawn::OnStartToggle);
	}
}

void APilotStationPawn::SetOwningShip(TObjectPtr<AActor> MyOwner)
{
	Super::SetOwningShip(MyOwner);
	if(OwningShip)
	{
		SpaceFlightModelComponent = OwningShip->GetComponentByClass<USpaceFlightModelComponent>();
	}
}

