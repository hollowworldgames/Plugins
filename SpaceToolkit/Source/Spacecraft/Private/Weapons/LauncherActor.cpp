﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/LauncherActor.h"


// Sets default values
ALauncherActor::ALauncherActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALauncherActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALauncherActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALauncherActor::OnStopFire()
{
	
}

