// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Player/SpaceCharacterXRPlayer.h"

#include "MotionControllerComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ViewPointComponent.h"
#include "XRCommon/Public/Components/XRViewPointComponent.h"


// Sets default values
ASpaceCharacterXRPlayer::ASpaceCharacterXRPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HeadViewPoint = CreateDefaultSubobject<UXRViewPointComponent>(TEXT("HeadViewPoint"));
	HeadViewPoint->SetupAttachment(GetRootComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(HeadViewPoint);
	
	LeftHand = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftHand"));
	LeftHand->SetupAttachment(HeadViewPoint);
	LeftHand->SetTrackingSource(EControllerHand::Left);
	
	RightHand = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightHand"));
	RightHand->SetupAttachment(HeadViewPoint);
	RightHand->SetTrackingSource(EControllerHand::Right);
}

// Called when the game starts or when spawned
void ASpaceCharacterXRPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceCharacterXRPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASpaceCharacterXRPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

