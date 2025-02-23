// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/CharacterInputComponent.h"
#include "FantasyMountInputComponent.generated.h"

FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Mount_ToggleFlight);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Mount_Dismount);

UCLASS(ClassGroup=(Input), meta=(BlueprintSpawnableComponent))
class FANTASYCHARACTER_API UFantasyMountInputComponent : public UCharacterInputComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	UFantasyMountInputComponent();
	virtual void MapInputs(UMappedInputComponent* InputComponent) override;
protected:
	void ToggleFlight(const FInputActionValue& Value);
	void Dismount(const FInputActionValue& Value);
	// Called when the game starts
	virtual void BeginPlay() override;
};
