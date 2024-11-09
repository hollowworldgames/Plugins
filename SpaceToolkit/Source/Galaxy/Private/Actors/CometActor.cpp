// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/CometActor.h"


// Sets default values
ACometActor::ACometActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACometActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACometActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

