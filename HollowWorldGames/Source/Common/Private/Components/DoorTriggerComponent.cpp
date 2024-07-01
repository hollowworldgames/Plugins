// (c) Copyright 2023 Hollow World Games llc All Rights Reserved


#include "Components/DoorTriggerComponent.h"

#include "Components/DoorMovementComponent.h"

// Sets default values for this component's properties
UDoorTriggerComponent::UDoorTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	Location = GetComponentLocation();
	OnComponentBeginOverlap.AddDynamic(this, &UDoorTriggerComponent::OnBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UDoorTriggerComponent::OnEndOverlap);
}

void UDoorTriggerComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UDoorMovementComponent * component = GetOwner()->GetComponentByClass<UDoorMovementComponent>();
	if(component)
	{
		component->Open();
	}
}

void UDoorTriggerComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UDoorMovementComponent * component = GetOwner()->GetComponentByClass<UDoorMovementComponent>();
	if(component)
	{
		component->Close();
	}
}


// Called every frame
void UDoorTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	SetWorldLocation(Location);
}

