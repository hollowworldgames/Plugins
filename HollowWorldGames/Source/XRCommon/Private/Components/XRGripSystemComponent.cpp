// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.


#include "Components/XRGripSystemComponent.h"

#include "Components/XRGripperComponent.h"


// Sets default values for this component's properties
UXRGripSystemComponent::UXRGripSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UXRGripSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<UXRGripperComponent*> Grippers;
	GetOwner()->GetComponents(Grippers);

	for (auto Grip : Grippers)
	{
		Grip->OnComponentBeginOverlap.AddDynamic(this, &UXRGripSystemComponent::OnBeginOverlap);
		Grip->OnComponentEndOverlap.AddDynamic(this, &UXRGripSystemComponent::OnEndOverlap);
	}
}


// Called every frame
void UXRGripSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UXRGripSystemComponent::Grip()
{
	if (Gripper)
	{
		Gripper->Grip(Grippable);
	}
}

bool UXRGripSystemComponent::HasGrippable()
{
	return Grippable != nullptr;
}

void UXRGripSystemComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	TScriptInterface<IGrippableInterface> Grip = TObjectPtr<AActor>(OtherActor);
	if (Grip)
	{
		Grippable = Grip;
		Gripper = Cast<UXRGripperComponent>(OverlappedComponent);
	}
}

void UXRGripSystemComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	TScriptInterface<IGrippableInterface> Grip = TObjectPtr<AActor>(OtherActor);
	if (Grip && Grip != Grippable)
	{
		Grippable = nullptr;
		Gripper = nullptr;
	}
}

