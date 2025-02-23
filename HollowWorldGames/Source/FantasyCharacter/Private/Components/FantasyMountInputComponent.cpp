// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Components/FantasyMountInputComponent.h"
#include "UtilityStatics.h"
#include "Characters/FantasyMountCharacter.h"
#include "Components/MappedInputComponent.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Mount_ToggleFlight, "Input.Mount.ToggleFlight", "Toggle Flight");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Input_Mount_Dismount, "Input.Mount.Dismount", "Dismount");

// Sets default values for this component's properties
UFantasyMountInputComponent::UFantasyMountInputComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UFantasyMountInputComponent::MapInputs(UMappedInputComponent* InputComponent)
{
	Super::MapInputs(InputComponent);

	InputComponent->BindNativeAction(InputConfig, Input_Mount_ToggleFlight, ETriggerEvent::Completed,
		this, &UFantasyMountInputComponent::ToggleFlight, true);
	InputComponent->BindNativeAction(InputConfig, Input_Mount_Dismount, ETriggerEvent::Completed,
		this, &UFantasyMountInputComponent::Dismount, true);
}

void UFantasyMountInputComponent::ToggleFlight(const FInputActionValue& Value)
{
	AFantasyMountCharacter * Character = Cast<AFantasyMountCharacter>(GetOwner());
	if (IsValidEnsure(Character))
	{
		if (Character->IsFlying())
		{
			Character->SwitchToWalk();
		}
		else
		{
			Character->SwitchToFlight();
		}
	}
}

void UFantasyMountInputComponent::Dismount(const FInputActionValue& Value)
{
	AFantasyMountCharacter * Character = Cast<AFantasyMountCharacter>(GetOwner());
	if (IsValidEnsure(Character))
	{
		Character->Dismount();
	}
}


// Called when the game starts
void UFantasyMountInputComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

