// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "XRUtilityStatics.h"

#include "IXRTrackingSystem.h"
#include "ViewableWorldSubsystem.h"
#include "Components/XRViewPointComponent.h"
#include "Kismet/GameplayStatics.h"

bool UXRUtilityStatics::IsXRRunning()
{
	if (GEngine->XRSystem && GEngine->XRSystem->GetHMDDevice()) //check pointer is valid
	{
		if (GEngine->XRSystem->IsHeadTrackingAllowed()) //check stereo enabled
		{
			return true;
		}
	}
	return false;
}

AXRHandActor* UXRUtilityStatics::GetXRHandActor(const UObject* WorldContext, EHand Hand)
{
	TArray<AActor*> Hands;
	UGameplayStatics::GetAllActorsOfClass(WorldContext, AXRHandActor::StaticClass(), Hands);
	for (AActor* Actor : Hands)
	{
		if (AXRHandActor *HandActor = Cast<AXRHandActor>(Actor))
		{
			if (HandActor->GetHand() == Hand)
			{
				return HandActor;
			}
		}
	}
	return nullptr;
}

UMotionControllerComponent* UXRUtilityStatics::GetMotionControllerComponent(const UObject* WorldContext,
	const EHand Hand)
{
	UWorld * World = GEngine->GetWorldFromContextObjectChecked(WorldContext);
	if (!World) return nullptr;
	UViewableWorldSubsystem * ViewableWorldSubsystem = World->GetSubsystem<UViewableWorldSubsystem>();
	if (!ViewableWorldSubsystem) return nullptr;
	UXRViewPointComponent * XRViewPointComponent = Cast<UXRViewPointComponent>(ViewableWorldSubsystem->GetCurrentViewPoint());
	if (!XRViewPointComponent) return nullptr;
	return XRViewPointComponent->GetMotionController(Hand);
}
