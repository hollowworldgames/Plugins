// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SpaceCharacterAI.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Gameplay/SpaceCharacterAttributes.h"


// Sets default values
ASpaceCharacterAI::ASpaceCharacterAI()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UGameplayAbilitySystemComponent>("Ability System Component");
	Attributes = CreateDefaultSubobject<USpaceCharacterAttributes>("Attributes");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AbilitySystemComponent->SetIsReplicated(true);
}

// Called when the game starts or when spawned
void ASpaceCharacterAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceCharacterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASpaceCharacterAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASpaceCharacterAI::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
