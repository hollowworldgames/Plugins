// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DataCharacter.h"

#include "Components/DataAccessComponent.h"


// Sets default values
ADataCharacter::ADataCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADataCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ADataCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	Save();
}

// Called every frame
void ADataCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ADataCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ADataCharacter::Load(uint64 ActorId)
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
		DataAccessComponent->GetDataLoaded().AddDynamic(this, &ADataCharacter::Multicast_PostLoad);
		DataAccessComponent->LoadActorState(ActorId);
	}
	
}

void ADataCharacter::Save() const
{
	if(ensure(DataAccessComponent))
	{
		OnPrepareSave();
		DataAccessComponent->SaveActorState();
	}
}

void ADataCharacter::OnLoaded()
{
	//Derived Class Will Setup Attributes and such here
}

void ADataCharacter::OnPrepareSave() const
{
	//Derived Class Will write attributes and such here to update persistence
}

void ADataCharacter::Multicast_PostLoad_Implementation()
{
	
	OnLoaded();
}
