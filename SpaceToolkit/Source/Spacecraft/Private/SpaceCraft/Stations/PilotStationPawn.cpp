// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCraft/Stations/PilotStationPawn.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "SpaceCraft/Components/SpaceFlightModelComponent.h"


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
	if(SpaceFlightModelComponent)
	{
		SpaceFlightModelComponent->AddThrottleInput(ThrottleValue);
	}
}

void APilotStationPawn::OnPitchYaw(const FInputActionValue& InputActionValue)
{
	FVector2d PitchYaw = InputActionValue.Get<FVector2d>();
	if(SpaceFlightModelComponent)
	{
		SpaceFlightModelComponent->AddPitchInput(PitchYaw.Y);
		SpaceFlightModelComponent->AddYawInput(PitchYaw.X);
	}
}

void APilotStationPawn::OnRoll(const FInputActionValue& InputActionValue)
{
	float Roll = InputActionValue.Get<float>();
	if(SpaceFlightModelComponent)
	{
		SpaceFlightModelComponent->AddRollInput(Roll);
	}
}

void APilotStationPawn::OnLiftSlide(const FInputActionValue& InputActionValue)
{
	FVector2d LiftSlide = InputActionValue.Get<FVector2d>();
	if(SpaceFlightModelComponent)
	{
		SpaceFlightModelComponent->AddLiftInput(LiftSlide.Y);
		SpaceFlightModelComponent->AddSlideInput(LiftSlide.X);
	}
}

void APilotStationPawn::OnThrottle(const FInputActionValue& InputActionValue)
{
	float Throttle = InputActionValue.Get<float>();
	ThrottleValue = Throttle;
}

void APilotStationPawn::OnThrottleIncrement(const FInputActionValue& InputActionValue)
{
	float Throttle = InputActionValue.Get<float>();
	ThrottleValue += Throttle * 0.03f;
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
	}
}

void APilotStationPawn::SetOwningShip(TObjectPtr<AActor> OwningShip)
{
	Super::SetOwningShip(OwningShip);
	if(OwningShip)
	{
		SpaceFlightModelComponent = OwningShip->GetComponentByClass<USpaceFlightModelComponent>();
	}
}

