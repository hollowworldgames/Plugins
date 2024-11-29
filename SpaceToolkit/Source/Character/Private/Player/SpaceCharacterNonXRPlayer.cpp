﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Player/SpaceCharacterNonXRPlayer.h"

#include "Camera/CameraComponent.h"
#include "Components/ViewPointComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ASpaceCharacterNonXRPlayer::ASpaceCharacterNonXRPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FollowViewPoint = CreateDefaultSubobject<UViewPointComponent>(TEXT("FollowViewPoint"));
	FollowViewPoint->SetupAttachment(GetRootComponent());

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(FollowViewPoint);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}

// Called when the game starts or when spawned
void ASpaceCharacterNonXRPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceCharacterNonXRPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASpaceCharacterNonXRPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

