// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Characters/FantasyPlayerThirdPersonCharacter.h"

#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AFantasyPlayerThirdPersonCharacter::AFantasyPlayerThirdPersonCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFantasyPlayerThirdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFantasyPlayerThirdPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFantasyPlayerThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFantasyPlayerThirdPersonCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFantasyPlayerThirdPersonCharacter::Look);

		EnhancedInputComponent->BindAction(FlightToggleAction, ETriggerEvent::Completed, this, &AFantasyPlayerThirdPersonCharacter::ToggleFlight);
	}
}

void AFantasyPlayerThirdPersonCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		
		FRotator YawRotation(0, Rotation.Yaw, 0);

		UCharacterMovementComponent * Component = Cast<UCharacterMovementComponent>(GetMovementComponent());
		if(Component)
		{
			if(Component->MovementMode == MOVE_Flying)
			{
				YawRotation.Pitch = Rotation.Pitch;
			}
		}
		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AFantasyPlayerThirdPersonCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AFantasyPlayerThirdPersonCharacter::ToggleFlight()
{
	UCharacterMovementComponent * Component = Cast<UCharacterMovementComponent>(GetMovementComponent());
	if(Component)
	{
		if(Component->MovementMode == MOVE_Walking)
		{
			Component->SetMovementMode(MOVE_Flying);
		}
		else
		{
			Component->SetMovementMode(MOVE_Walking);
		}
	}
}

