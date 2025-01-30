//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.
#include "Characters/FantasyCombatCharacter.h"

#include "UtilityStatics.h"
#include "Variables/FloatVariableAsset.h"


// Sets default values
AFantasyCombatCharacter::AFantasyCombatCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AFantasyCombatCharacter::OnDeath()
{
	GetMesh()->SetSimulatePhysics(true); //ragdoll character
	if (HasAuthority() && ensure(DestroyDelay))
	{
		SetLifeSpan(DestroyDelay->GetValue());
	}
}

// Called when the game starts or when spawned
void AFantasyCombatCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFantasyCombatCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float AFantasyCombatCharacter::GetAttributeBonus(FGameplayTag Attribute)
{
	ensure(false);
	return 1.0f;
}

FAttributeChanged& AFantasyCombatCharacter::GetAttributeChangedNotify()
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	IsValidChecked(AbilitySystemComponent);
	return AbilitySystemComponent->GetAttributeChanged();
}

TScriptInterface<IGameplayActorInterface> AFantasyCombatCharacter::GetAbilityTarget()
{
	return AbilityTarget;
}

float AFantasyCombatCharacter::GetAttributeValue(FGameplayTag Attribute)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if (IsValidEnsure(AbilitySystemComponent))
	{
		return AbilitySystemComponent->GetAttributeValue(Attribute);
	}
	return 0.0f;
}

void AFantasyCombatCharacter::ApplyEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level,
	UGameplayAbilitySystemComponent* Source)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
 	if (IsValidEnsure(AbilitySystemComponent))
 	{
 		AbilitySystemComponent->ApplyGameplayEffect(EffectClass, Level, Source->GetAvatarActor());
 	}
}

void AFantasyCombatCharacter::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	TeamID = NewTeamID;
}

FGenericTeamId AFantasyCombatCharacter::GetGenericTeamId() const
{
	return TeamID;
}

UAbilitySystemComponent* AFantasyCombatCharacter::GetAbilitySystemComponent() const
{
	ensure(false);
	return nullptr;
}

ETeamAttitude::Type AFantasyCombatCharacter::GetTeamAttitudeTowards(const AActor& Other) const
{
	FGenericTeamId OtherId = FGenericTeamId::GetTeamIdentifier(&Other);
	if (TeamID == 0 || OtherId== 0)
	{
		return ETeamAttitude::Neutral;
	}
	return IGenericTeamAgentInterface::GetTeamAttitudeTowards(Other);
}
