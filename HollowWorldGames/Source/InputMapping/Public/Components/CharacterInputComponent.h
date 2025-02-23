// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "NativeGameplayTags.h"
#include "PlayerInputComponent.h"
#include "Components/SceneComponent.h"
#include "CharacterInputComponent.generated.h"

INPUTMAPPING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Character_MoveTag);
INPUTMAPPING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Character_LookTag);
INPUTMAPPING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Character_JumpTag);
INPUTMAPPING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Character_InteractTag);


UCLASS(ClassGroup=(Input), meta=(BlueprintSpawnableComponent))
class INPUTMAPPING_API UCharacterInputComponent : public UPlayerInputComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCharacterInputComponent();
	virtual void MapInputs(UMappedInputComponent* InputComponent) override;
protected:
	void MoveCharacter(const FInputActionValue& Value);
	void TurnCharacter(const FInputActionValue& Value);
	void JumpCharacter(const FInputActionValue& Value);
	void StopJumpCharacter(const FInputActionValue& Value);
	virtual void InteractCharacter(const FInputActionValue& Value);
	// Called when the game starts
	virtual void BeginPlay() override;
};
