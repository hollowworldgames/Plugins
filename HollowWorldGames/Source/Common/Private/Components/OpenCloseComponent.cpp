// Copyright (c) 2023 Hollow World Games llc. All rights reserved.


#include "Components/OpenCloseComponent.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Sound/SoundCue.h"

// Sets default values for this component's properties
UOpenCloseComponent::UOpenCloseComponent() : UStaticMeshComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenCloseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOpenCloseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(DelayDelta > 0)
	{
		DelayDelta -= DeltaTime;
		if(DelayDelta <= 0)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetComponentLocation());
		}
		return;
	}
	switch(State)
	{
	case EOpenCloseState::EOpenCloseState_Closing:
		{
			ChangeDelta += DeltaTime;
			if(ChangeDelta < ChangeTime)
			{
				SetRelativeLocation(FMath::Lerp(OpenPosition, ClosePosition, ChangeDelta / ChangeTime));
				SetRelativeRotation(UKismetMathLibrary::RLerp(OpenRotation, CloseRotation, ChangeDelta / ChangeTime, false));
			}
			else
			{
				SetClosed();
				if(OnClosed.IsBound())
				{
					OnClosed.Broadcast();
				}
			}
			break;
		}
	case EOpenCloseState::EOpenCloseState_Opening:
		{
			ChangeDelta += DeltaTime;
			if(ChangeDelta < ChangeTime)
			{
				SetRelativeLocation(FMath::Lerp(ClosePosition, OpenPosition, ChangeDelta / ChangeTime));
				SetRelativeRotation(UKismetMathLibrary::RLerp(CloseRotation, OpenRotation, ChangeDelta / ChangeTime, false));
			}
			else
			{
				SetOpened();
				if(OnOpened.IsBound())
				{
					OnOpened.Broadcast();
				}
			}
			break;
		}
	default:
		{
			break;
		}
	}
	
}

void UOpenCloseComponent::Open()
{
	if(State == EOpenCloseState::EOpenCloseState_Closed)
	{
		
		if(OnOpen.IsBound())
		{
			OnOpen.Broadcast();
		}
		State = EOpenCloseState::EOpenCloseState_Opening;
		ChangeDelta = 0;
		DelayDelta = DelayTime;
	}
}

void UOpenCloseComponent::Close()
{
	if(State == EOpenCloseState::EOpenCloseState_Opened)
	{
		if(OnClose.IsBound())
		{
			OnClose.Broadcast();
		}
		State = EOpenCloseState::EOpenCloseState_Closing;
		ChangeDelta = 0;
		DelayDelta = DelayTime;
	}
}

void UOpenCloseComponent::SetOpened()
{
	SetRelativeLocation(OpenPosition);
	SetRelativeRotation(OpenRotation);
	State = EOpenCloseState::EOpenCloseState_Opened;
}

void UOpenCloseComponent::SetClosed()
{
	SetRelativeLocation(ClosePosition);
	SetRelativeRotation(CloseRotation);
	State = EOpenCloseState::EOpenCloseState_Closed;
}

