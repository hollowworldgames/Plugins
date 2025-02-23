// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "UI/GameplayCharacterWidgetComponent.h"
#include "GameFramework/Character.h"
#include "Interfaces/GameplayWidgetInterface.h"


// Sets default values for this component's properties
UGameplayCharacterWidgetComponent::UGameplayCharacterWidgetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGameplayCharacterWidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	if (const TScriptInterface<IGameplayWidgetInterface> Interface = TObjectPtr<UUserWidget>(GetWidget()))
	{
		Interface->InitializeWidget(GetOwner<ACharacter>());
	}
}
