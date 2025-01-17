// (c) Copyright 2024 Hollow World Games llc All Rights Reserved.


#include "Components/PlayerInputComponent.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Components/MappedInputComponent.h"
#include "UserSettings/EnhancedInputUserSettings.h"


// Sets default values for this component's properties
UPlayerInputComponent::UPlayerInputComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerInputComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UPlayerInputComponent::MapInputs(UMappedInputComponent* InputComponent)
{
	TArray<uint32> BindHandles;
	InputComponent->BindAbilityActions(InputConfig, this, &ThisClass::Input_AbilityInputTagPressed, &ThisClass::Input_AbilityInputTagReleased, /*out*/ BindHandles);

}

void UPlayerInputComponent::InitializePlayerInput(UMappedInputComponent* InputComponent)
{
	check(InputComponent);

	const APawn* Pawn = GetOwner<APawn>();
	if (!Pawn)
	{
		return;
	}

	const APlayerController* PC = Pawn->GetController<APlayerController>();
	check(PC);

	const ULocalPlayer* LP = Cast<ULocalPlayer>(PC->GetLocalPlayer());
	check(LP);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	Subsystem->ClearAllMappings();

	if (InputConfig)
	{
		for (const FInputMappingContextAndPriority& Mapping : DefaultInputMappings)
		{
			if (Mapping.InputMapping)
			{
				if (Mapping.bRegisterWithSettings)
				{
					if (UEnhancedInputUserSettings* Settings = Subsystem->GetUserSettings())
					{
						Settings->RegisterInputMappingContext(Mapping.InputMapping);
					}
					
					FModifyContextOptions Options = {};
					Options.bIgnoreAllPressedKeysUntilRelease = false;
					// Actually add the config to the local player							
					Subsystem->AddMappingContext(Mapping.InputMapping, Mapping.Priority, Options);
				}
			}
		}

		// The Lyra Input Component has some additional functions to map Gameplay Tags to an Input Action.
		// If you want this functionality but still want to change your input component class, make it a subclass
		// of the ULyraInputComponent or modify this component accordingly.
		if (ensureMsgf(InputComponent, TEXT("Unexpected Input Component class! The Gameplay Abilities will not be bound to their inputs. Change the input component to ULyraInputComponent or a subclass of it.")))
		{
			// Add the key mappings that may have been set by the player
			InputComponent->AddInputMappings(InputConfig, Subsystem);
			MapInputs(InputComponent);
		}
	}
}


// Called every frame
void UPlayerInputComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerInputComponent::ClearMappings()
{
	const APawn* Pawn = GetOwner<APawn>();
	if (!Pawn)
	{
		return;
	}

	const APlayerController* PC = Pawn->GetController<APlayerController>();
	check(PC);

	const ULocalPlayer* LP = Cast<ULocalPlayer>(PC->GetLocalPlayer());
	check(LP);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	Subsystem->ClearAllMappings();
}

void UPlayerInputComponent::SwitchToAlternate(int Alternate)
{
	ClearMappings();

	const APawn* Pawn = GetOwner<APawn>();
	if (!Pawn)
	{
		return;
	}

	const APlayerController* PC = Pawn->GetController<APlayerController>();
	check(PC);

	const ULocalPlayer* LP = Cast<ULocalPlayer>(PC->GetLocalPlayer());
	check(LP);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	if (Alternate < AlternateInputMappings.Num())
	{
		if (UEnhancedInputUserSettings* Settings = Subsystem->GetUserSettings())
		{
			Settings->RegisterInputMappingContext(AlternateInputMappings[Alternate].InputMapping);
		}
					
		FModifyContextOptions Options = {};
		Options.bIgnoreAllPressedKeysUntilRelease = false;
		// Actually add the config to the local player							
		Subsystem->AddMappingContext(AlternateInputMappings[Alternate].InputMapping, AlternateInputMappings[Alternate].Priority, Options);
	}
}

void UPlayerInputComponent::SwitchToDefaults()
{
	ClearMappings();

	const APawn* Pawn = GetOwner<APawn>();
	if (!Pawn)
	{
		return;
	}

	const APlayerController* PC = Pawn->GetController<APlayerController>();
	check(PC);

	const ULocalPlayer* LP = Cast<ULocalPlayer>(PC->GetLocalPlayer());
	check(LP);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	
	for (const FInputMappingContextAndPriority& Mapping : DefaultInputMappings)
	{
		if (Mapping.InputMapping)
		{
			if (Mapping.bRegisterWithSettings)
			{
				if (UEnhancedInputUserSettings* Settings = Subsystem->GetUserSettings())
				{
					Settings->RegisterInputMappingContext(Mapping.InputMapping);
				}
					
				FModifyContextOptions Options = {};
				Options.bIgnoreAllPressedKeysUntilRelease = false;
				// Actually add the config to the local player							
				Subsystem->AddMappingContext(Mapping.InputMapping, Mapping.Priority, Options);
			}
		}
	}
}

void UPlayerInputComponent::Input_AbilityInputTagPressed(FGameplayTag InputTag)
{
	if (const IAbilitySystemInterface* Pawn = GetOwner<IAbilitySystemInterface>())
	{
		UGameplayAbilitySystemComponent * Component = Cast<UGameplayAbilitySystemComponent>(Pawn->GetAbilitySystemComponent());
		if (ensure(Component))
		{
			Component->OnAbilityInputPressed(InputTag);
		}	
	}
}

void UPlayerInputComponent::Input_AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (const IAbilitySystemInterface* Pawn = GetOwner<IAbilitySystemInterface>())
	{
		UGameplayAbilitySystemComponent * Component = Cast<UGameplayAbilitySystemComponent>(Pawn->GetAbilitySystemComponent());
		if (ensure(Component))
		{
			Component->OnAbilityInputReleased(InputTag);
		}	
	}
}
