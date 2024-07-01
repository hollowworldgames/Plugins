// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "MissileLauncher.h"

#include "Missile.h"
#include "Targetable.h"


// Sets default values for this component's properties
UMissileLauncher::UMissileLauncher()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UMissileLauncher::LaunchAt(TScriptInterface<ITargetable> Target)
{
	USceneComponent * SpawnPoint = GetChildComponent(0);
	if(GetOwner() && GetWorld() && SpawnPoint)
	{
		AMissile * Missile = GetWorld()->SpawnActor<AMissile>(MissileClass, SpawnPoint->GetComponentLocation(), SpawnPoint->GetComponentRotation());
		if(Missile)
		{
			Missile->FireAt(SpawnPoint->GetComponentLocation(), GetOwner()->GetVelocity(), Target->GetActor());
		}
	}
	
}

// Called when the game starts
void UMissileLauncher::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMissileLauncher::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

