// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DataPawn.h"

#include "Components/DataAccessComponent.h"


// Sets default values
ADataPawn::ADataPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADataPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADataPawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	Save();
}

// Called every frame
void ADataPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ADataPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ADataPawn::Load(uint64 ActorId)
{
	TSubclassOf<UDataAccessComponent> DataClass;
	switch(GetNetMode())
	{
	case NM_Client :
		{
			DataClass = ClientDataClass;
			break;
		}
	case NM_DedicatedServer :
		{
			DataClass = ServerDataClass;
			break;
		}
	case NM_ListenServer :
	case NM_Standalone :
		{
			DataClass = SingleDataClass;
			break;
		}
	default :
		break;
	}
	DataAccessComponent = Cast<UDataAccessComponent>(AddComponentByClass(DataClass, false, FTransform(), false));
	if(ensure(DataAccessComponent))
	{
		DataAccessComponent->SetIsReplicated(true);
		DataAccessComponent->GetDataLoaded().AddDynamic(this, &ADataPawn::Multicast_PostLoad);
		DataAccessComponent->LoadActorState(ActorId);
	}
}

void ADataPawn::Save() const
{
	if(ensure(DataAccessComponent))
	{
		OnPrepareSave();
		DataAccessComponent->SaveActorState();
	}
}

void ADataPawn::OnLoaded()
{
	//Derived Class Will Setup Attributes and such here
}

void ADataPawn::OnPrepareSave() const
{
	//Derived Class Will write attributes and such here to update persistence
}

void ADataPawn::Multicast_PostLoad_Implementation()
{
	OnLoaded();
}
