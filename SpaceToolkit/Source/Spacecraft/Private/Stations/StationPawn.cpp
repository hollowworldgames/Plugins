// (c) Copyright 2023 Hollow World Games llc All Rights Reserved


#include "Stations/StationPawn.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/ViewPointComponent.h"
#include "GameFramework/Character.h"
#include "Components/InteractableComponent.h"
#include "MotionControllerComponent.h"
#include "Components/CapsuleComponent.h"


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
	if (EntryComponent)
	{
		EntryComponent->GetOnBeginInteract().Clear();
		EntryComponent->GetOnCompleteInteract().Clear();
		EntryComponent->GetOnInteractorEntered().Clear();
		EntryComponent->GetOnInteractorExited().Clear();
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

void AStationPawn::SetInteractor(const TObjectPtr<UInteractableComponent> NewInteractor)
{
	if(ensure(NewInteractor))
	{
		EntryComponent = NewInteractor;
		EntryComponent->GetOnBeginInteract().AddDynamic(this, &AStationPawn::OnBeginInteract);
		EntryComponent->GetOnCompleteInteract().AddDynamic(this, &AStationPawn::OnCompleteInteract);
		EntryComponent->GetOnInteractorEntered().AddDynamic(this, &AStationPawn::OnInteractorEnter);
		EntryComponent->GetOnInteractorExited().AddDynamic(this, &AStationPawn::OnInteractorExit);
	}
}

void AStationPawn::ExitStation()
{
	BeginExitStation(Occupant);
}

void AStationPawn::ExitComplete()
{
	Occupant->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	AController * NewController = GetController();
	NewController->UnPossess();
	NewController->Possess(Occupant);
	Occupant = nullptr;
}

void AStationPawn::OnBeginInteract(ACharacter* Character, UInteractableComponent* Component)
{
	Occupant = Character;
	EnterStation(Character);
}

void AStationPawn::OnCompleteInteract(ACharacter* Character, UInteractableComponent* Component)
{
	Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	AController * NewController = Character->GetController();
	NewController->UnPossess();
	NewController->Possess(this);
}

void AStationPawn::OnInteractorEnter(ACharacter* Character, UInteractableComponent* Component)
{
	
}

void AStationPawn::OnInteractorExit(ACharacter* Character, UInteractableComponent* Component)
{
	
}

