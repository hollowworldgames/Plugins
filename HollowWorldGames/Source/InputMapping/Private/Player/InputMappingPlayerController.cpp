// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/InputMappingPlayerController.h"

#include "Components/InputMappingComponent.h"

void AInputMappingPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UInputMappingComponent * MappingComponent = Cast<UInputMappingComponent>(InputComponent);
	if(ensure(MappingComponent))
	{
		MappingComponent->InitializeInputs();
		MappingComponent->LoadDefaultMapping(DefaultMapping);
	}
}
