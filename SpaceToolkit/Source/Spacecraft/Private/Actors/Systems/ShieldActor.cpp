// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Actors/Systems/ShieldActor.h"

#include "Attributes/Equipment/ShieldAttributeSet.h"


// Sets default values
AShieldActor::AShieldActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ShieldAttributes = CreateDefaultSubobject<UShieldAttributeSet>(TEXT("ShieldAttributes"));
}

// Called when the game starts or when spawned
void AShieldActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShieldActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShieldActor::InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData)
{
	Super::InitializeAttributes(SystemOwner, SystemData);
}

