// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "CharacterStatics.h"

#include "GameFramework/Character.h"


void UCharacterStatics::MovePawn(const FVector2D MovementVector, APawn* MyPawn,
                                 APlayerController* MyController)
{
	// find out which way is forward
	const FRotator Rotation = MyController->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	// get right vector 
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// add movement 
	MyPawn->AddMovementInput(ForwardDirection, MovementVector.Y);
	MyPawn->AddMovementInput(RightDirection, MovementVector.X);
}

void UCharacterStatics::TurnPawn(const FVector2D LookAxisVector, APawn* MyPawn)
{
	// add yaw and pitch input to controller
	MyPawn->AddControllerYawInput(LookAxisVector.X);
	MyPawn->AddControllerPitchInput(LookAxisVector.Y);
}

void UCharacterStatics::StartJump(APawn* MyPawn)
{
	ACharacter * MyCharacter = Cast<ACharacter>(MyPawn);
	if(ensure(MyCharacter))
	{
		MyCharacter->Jump();
	}
}

void UCharacterStatics::StopJump(APawn* MyPawn)
{
	ACharacter * MyCharacter = Cast<ACharacter>(MyPawn);
	if(ensure(MyCharacter))
	{
		MyCharacter->StopJumping();
	}
}
