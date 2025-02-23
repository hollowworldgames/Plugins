// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Characters/FantasyMountCharacter.h"

#include "UtilityStatics.h"
#include "Components/InteractableComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AFantasyMountCharacter::AFantasyMountCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractionComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("Interaction Component"));
}

void AFantasyMountCharacter::Mount(ACharacter* Character)
{
	if (!Rider)
	{
		Rider = Character;
		Rider->AttachToActor(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale, Saddle);
		AController* NewController = Character->GetController();
		if (NewController)
		{
			NewController->Possess(this);
		}
	}
}

void AFantasyMountCharacter::Dismount()
{
	if (Rider)
	{
		Rider->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		Rider->SetActorLocation(InteractionComponent->GetComponentLocation());
		AController * NewController = Rider->GetController();
		if (IsValidEnsure(NewController))
		{
			NewController->Possess(Rider);
		}
		Rider = nullptr;
	}
}

void AFantasyMountCharacter::SwitchToFlight() const
{
	if (CanFly)
	{
		UCharacterMovementComponent * MovementComponent = Cast<UCharacterMovementComponent>(GetMovementComponent());
		if (IsValidEnsure(MovementComponent))
		{
			MovementComponent->SetMovementMode(MOVE_Flying);
		}
	}
}

void AFantasyMountCharacter::SwitchToWalk() const
{
	UCharacterMovementComponent * MovementComponent = Cast<UCharacterMovementComponent>(GetMovementComponent());
	if (IsValidEnsure(MovementComponent))
	{
		MovementComponent->SetMovementMode(MOVE_Walking);
	}
}

bool AFantasyMountCharacter::IsFlying() const
{
	UCharacterMovementComponent * MovementComponent = Cast<UCharacterMovementComponent>(GetMovementComponent());
	if (IsValidEnsure(MovementComponent))
	{
		return MovementComponent->IsFlying();
	}
	return false;
}

TArray<FName> AFantasyMountCharacter::GetSocketNames() const
{
	TArray<FName> Result;
	if (IsValidEnsure(GetMesh()))
	{
		Result = GetMesh()->GetAllSocketNames();
	}
	return Result;
}

// Called when the game starts or when spawned
void AFantasyMountCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


