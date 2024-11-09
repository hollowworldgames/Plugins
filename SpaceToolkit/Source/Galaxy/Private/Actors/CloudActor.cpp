// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Actors/CloudActor.h"


// Sets default values
ACloudActor::ACloudActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACloudActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACloudActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACloudActor::SetCloud(UCloudOrbital* NewCloud)
{
	Cloud = NewCloud;
}

