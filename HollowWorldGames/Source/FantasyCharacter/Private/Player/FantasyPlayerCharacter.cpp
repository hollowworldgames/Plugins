//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Player/FantasyPlayerCharacter.h"

#include "UtilityStatics.h"
#include "Components/MappedInputComponent.h"
#include "Player/FantasyPlayerState.h"


// Sets default values
AFantasyPlayerCharacter::AFantasyPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CharacterInputComponent = CreateDefaultSubobject<UCharacterInputComponent>(TEXT("InputComponent"));
}

// Called when the game starts or when spawned
void AFantasyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFantasyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFantasyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (IsValidEnsure(CharacterInputComponent) && IsValidEnsure(PlayerInputComponent))
	{
		CharacterInputComponent->InitializePlayerInput(Cast<UMappedInputComponent>(PlayerInputComponent));
	}
}


void AFantasyPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	AFantasyPlayerState * State = GetPlayerState<AFantasyPlayerState>();
	if (IsValidEnsure(State))
	{
		State->PlayerAlive();
	}
}

