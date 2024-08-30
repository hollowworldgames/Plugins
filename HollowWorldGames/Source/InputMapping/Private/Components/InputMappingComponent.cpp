// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InputMappingComponent.h"

#include "EnhancedInputSubsystems.h"
#include "Data/InputMapDefaultsData.h"

// Sets default values for this component's properties
UInputMappingComponent::UInputMappingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInputMappingComponent::InitializeInputs()
{
	UEnhancedInputWorldSubsystem * Subsystem = GetWorld()->GetSubsystem<UEnhancedInputWorldSubsystem>();
 	if(ensure(Subsystem))
 	{
 		for(TObjectPtr<UInputMappingContext> Context : Contexts)
 		{
 			Subsystem->AddMappingContext(Context, 0);
 		}
 	}
	for(FInputAvailable Available : Inputs->Inputs)
	{
		Super::BindAction(Available.Action, ETriggerEvent::Triggered, this, &UInputMappingComponent::OnTriggered, Available.Axis, Available.InputTag);
		Super::BindAction(Available.Action, ETriggerEvent::Completed, this, &UInputMappingComponent::OnReleased, Available.Axis, Available.InputTag);
		Super::BindAction(Available.Action, ETriggerEvent::Ongoing, this, &UInputMappingComponent::OnOngoing, Available.Axis, Available.InputTag);
	}
}

void UInputMappingComponent::LoadDefaultMapping(FString Mapping)
{
	for(TObjectPtr<UInputMapDefaultsData> Default : Defaults)
	{
		if(Default->InputGroup == Mapping)
		{
			SetMapping(Default->Mappings);
		}
	}
}

void UInputMappingComponent::SetMapping(TArray<FInputMapping> Mappings)
{
	CurrentMap.Empty();
	for(FInputMapping Map : Mappings)
	{
		CurrentMap[Map.InputTag] = Map;
	}
}

void UInputMappingComponent::LoadMapping(FString Path)
{
	
}

void UInputMappingComponent::SaveMapping(FString Path)
{
	
}

void UInputMappingComponent::OnTriggered(const FInputActionValue& Value, bool Axis, FGameplayTag Input)
{
	if(CurrentMap.Contains(Input))
	{
		FInputMapping Output = CurrentMap[Input];
		if(TriggerNotifies.Contains(Output.OutputTag))
		{
			TriggerNotifies[Output.OutputTag].Broadcast(Output.OutputTag, (Output.Invert) ? -Value.Get<float>() : Value.Get<float>(), Axis);
		}
	}
}

void UInputMappingComponent::OnReleased(const FInputActionValue& Value, bool Axis, FGameplayTag Input)
{
	if(CurrentMap.Contains(Input))
	{
		FInputMapping Output = CurrentMap[Input];
		if(CompleteNotifies.Contains(Output.OutputTag))
		{
			CompleteNotifies[Output.OutputTag].Broadcast(Output.OutputTag, (Output.Invert) ? -Value.Get<float>() : Value.Get<float>(), Axis);;
		}
	}
}

void UInputMappingComponent::OnOngoing(const FInputActionValue& Value, bool Axis, FGameplayTag Input)
{
	if(CurrentMap.Contains(Input))
	{
		FInputMapping Output = CurrentMap[Input];
		if(OngoingNotifies.Contains(Output.OutputTag))
		{
			OngoingNotifies[Output.OutputTag].Broadcast(Output.OutputTag, (Output.Invert) ? -Value.Get<float>() : Value.Get<float>(), Axis);;
		}
	}
}


// Called when the game starts
void UInputMappingComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

