// Copyright (c) 2024 Hollow World Games llc All Rights Reserved


#include "Components/CharacterInputComponent.h"

#include "EnhancedInputComponent.h"
#include "Components/MappedInputComponent.h"
#include "GameFramework/Character.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Character_MoveTag, "Input.Character.Move", "Character Move");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Character_LookTag,"Input.Character.Look","Character Look");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Character_JumpTag,"Input.Character.Jump","Character Jump");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Character_InteractTag,"Input.Character.Interact","Character Interact");

// Sets default values for this component's properties
UCharacterInputComponent::UCharacterInputComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCharacterInputComponent::MapInputs(UMappedInputComponent* InputComponent)
{
	Super::MapInputs(InputComponent);

	//Character
	InputComponent->BindNativeAction(InputConfig, Input_Character_MoveTag, ETriggerEvent::Triggered,
		this, &UCharacterInputComponent::MoveCharacter, true);
	InputComponent->BindNativeAction(InputConfig, Input_Character_LookTag, ETriggerEvent::Triggered,
		this, &UCharacterInputComponent::TurnCharacter, true);
	InputComponent->BindNativeAction(InputConfig, Input_Character_JumpTag, ETriggerEvent::Started,
		this, &UCharacterInputComponent::JumpCharacter, true);
	InputComponent->BindNativeAction(InputConfig, Input_Character_JumpTag, ETriggerEvent::Completed,
		this, &UCharacterInputComponent::StopJumpCharacter, true);
	InputComponent->BindNativeAction(InputConfig, Input_Character_InteractTag, ETriggerEvent::Completed,
		this, &UCharacterInputComponent::InteractCharacter, true);
}


// Called when the game starts
void UCharacterInputComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UCharacterInputComponent::MoveCharacter(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (!ensureMsgf(GetOwner<ACharacter>(),TEXT("Character Player Input Setup for non Character")))
		return;
	
	APlayerController * Controller = GetOwner<APawn>()->GetController<APlayerController>();
	if (ensure(Controller != nullptr) && ensure(Controller->GetPawn()))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		Controller->GetPawn()->AddMovementInput(ForwardDirection, MovementVector.Y);
		Controller->GetPawn()->AddMovementInput(RightDirection, MovementVector.X);
	}
}

void UCharacterInputComponent::TurnCharacter(const FInputActionValue& Value)
{
	if (!ensureMsgf(GetOwner<ACharacter>(),TEXT("Character Player Input Setup for non Character")))
		return;
	
	APlayerController * Controller = GetOwner<APawn>()->GetController<APlayerController>();
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (ensure(Controller != nullptr) && ensure(Controller->GetPawn() != nullptr))
	{
		// add yaw and pitch input to controller
		Controller->GetPawn()->AddControllerYawInput(LookAxisVector.X);
		Controller->GetPawn()->AddControllerPitchInput(LookAxisVector.Y);
	}
}

void UCharacterInputComponent::JumpCharacter(const FInputActionValue& Value)
{
	if (!ensureMsgf(GetOwner<ACharacter>(),TEXT("Character Player Input Setup for non Character")))
		return;

	GetOwner<ACharacter>()->Jump();
}

void UCharacterInputComponent::StopJumpCharacter(const FInputActionValue& Value)
{
	if (!ensureMsgf(GetOwner<ACharacter>(),TEXT("Character Player Input Setup for non Character")))
		return;
	
	GetOwner<ACharacter>()->StopJumping();
}

void UCharacterInputComponent::InteractCharacter(const FInputActionValue& Value)
{

}
