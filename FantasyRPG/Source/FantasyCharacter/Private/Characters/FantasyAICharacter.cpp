// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Characters/FantasyAICharacter.h"
#include "Abilities/GameplayAbility.h"
#include "Attributes/RPGAttributeSet.h"
#include "Components/GameplayAbilitySystemComponent.h"


// Sets default values
AFantasyAICharacter::AFantasyAICharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UGameplayAbilitySystemComponent>("Ability System");
	Attributes = CreateDefaultSubobject<URPGAttributeSet>("Attributes");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

// Called when the game starts or when spawned
void AFantasyAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFantasyAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFantasyAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* AFantasyAICharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

