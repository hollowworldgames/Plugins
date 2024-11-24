// (c) Copyright 2023 Hollow World Games llc All Rights Reserved


#include "Stations/StationPawn.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/ViewPointComponent.h"
#include "GameFramework/Character.h"
#include "InteractableComponent.h"
#include "MotionControllerComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AStationPawn::AStationPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
	SetRootComponent(Root);
	Seat = CreateDefaultSubobject<UViewPointComponent>(TEXT("Seat"));
	Seat->SetupAttachment(Root);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Head Camera"));
	Camera->SetupAttachment(Seat);
	LeftHand = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftHand"));
	LeftHand->SetupAttachment(Seat);
	LeftHand->SetTrackingSource(EControllerHand::Left);
	RightHand = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightHand"));
	RightHand->SetupAttachment(Seat);
	RightHand->SetTrackingSource(EControllerHand::Right);
	EntryComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("Entry Component"));
	EntryComponent->SetupAttachment(Root);
	EntryText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Entry Text"));
	EntryText->SetupAttachment(EntryComponent);
}

// Called when the game starts or when spawned
void AStationPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AStationPawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	//kill attached characters when destroyed
	if (EndPlayReason == EEndPlayReason::Type::Destroyed && Occupant)
	{
		Occupant->Destroy();
	}
}

// Called every frame
void AStationPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AStationPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AStationPawn::SetOwningShip(TObjectPtr<AActor> Ship)
{
	OwningShip = Ship;
}

UAbilitySystemComponent* AStationPawn::GetOccupantAbilitySystemComponent() const
{
	return UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Occupant);
}

