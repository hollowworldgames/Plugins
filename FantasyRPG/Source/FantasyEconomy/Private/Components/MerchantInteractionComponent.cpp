// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/MerchantInteractionComponent.h"


// Sets default values for this component's properties
UMerchantInteractionComponent::UMerchantInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMerchantInteractionComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}


void UMerchantInteractionComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

// Called when the game starts
void UMerchantInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UMerchantInteractionComponent::OnBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UMerchantInteractionComponent::OnEndOverlap);
}


