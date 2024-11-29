// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCharacter.h"

#include "Animation/AnimNode_Inertialization.h"
#include "Components/GameplayAbilitySystemComponent.h"


// Sets default values
ASpaceCharacter::ASpaceCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpaceCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASpaceCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASpaceCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* ASpaceCharacter::GetAbilitySystemComponent() const
{
	ensureMsgf(false,TEXT("SpaceCharacter Not Overriden"));
	return nullptr;
}

FAttributeChanged& ASpaceCharacter::GetAttributeChangedNotify()
{
	return OnAttributeChanged;
}

TScriptInterface<IGameplayActorInterface> ASpaceCharacter::GetAbilityTarget()
{
	return TScriptInterface<IGameplayActorInterface>(Target);
}

float ASpaceCharacter::GetAttributeValue(FGameplayTag Attribute)
{
	if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent()))
	{
		return AbilitySystemComponent->GetAttributeValue(Attribute);
	}
	return 0.0f;
}

void ASpaceCharacter::ApplyEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level,
	UGameplayAbilitySystemComponent* Source)
{
	if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent()))
	{
		AbilitySystemComponent->ApplyGameplayEffect(EffectClass, Level, Source->GetAvatarActor());
	}
}

void ASpaceCharacter::SetAttributes(TArray<FAttributeValue> Attributes)
{
	if (UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent()))
	{
		for (FAttributeValue Attribute : Attributes)
		{
			AbilitySystemComponent->SetAttributeValue(Attribute.AttributeTag, Attribute.NewValue);
		}
	}
}

void ASpaceCharacter::OnInteractableAvailable(TScriptInterface<IInteractable> Interactable)
{
	Candidate = Interactable;
}

void ASpaceCharacter::OnInteractableUnavailable(TScriptInterface<IInteractable> Interactable)
{
	if (Candidate == Interactable)
	{
		Candidate = nullptr;
	}
}

void ASpaceCharacter::OnInteractionBegin(TScriptInterface<IInteractable> Interactable)
{
}

void ASpaceCharacter::OnInteractionEnd(TScriptInterface<IInteractable> Interactable)
{
}

