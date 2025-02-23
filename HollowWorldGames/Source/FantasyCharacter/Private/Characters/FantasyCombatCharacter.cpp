//Copyright (C) 2024 Hollow World Games llc All Rights Reserved.
#include "Characters/FantasyCombatCharacter.h"

#include "UtilityStatics.h"
#include "Attributes/AttributeTags.h"
#include "UI/GameplayCombatWidgetController.h"
#include "UI/GameplayVitalWidgetController.h"
#include "UI/GameplayWidgetController.h"
#include "Variables/FloatVariableAsset.h"


// Sets default values
AFantasyCombatCharacter::AFantasyCombatCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AFantasyCombatCharacter::OnDeath()
{
	Alive = false;
	if (HasAuthority() && ensure(DestroyDelay))
	{
		if (Respawns)
		{
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
			{
				RestoreToLife();
			}, RespawnDelay, false);
		}
		else
		{
			SetLifeSpan(DestroyDelay->GetValue());
		}
	}
}

void AFantasyCombatCharacter::Ragdoll()
{
	if (IsValidEnsure(GetMesh()))
	{
		GetMesh()->SetSimulatePhysics(true);
	}
}

void AFantasyCombatCharacter::RestoreToLife()
{
	Alive = true;
	//Restore To Full Health
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if (IsValidEnsure(AbilitySystemComponent))
	{
		//Restore To Full Health
		AbilitySystemComponent->SetAttributeValue(HealthTag, AbilitySystemComponent->GetAttributeValue(MaxHealthTag));
		
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

UGameplayWidgetController* AFantasyCombatCharacter::GetWidgetController(TSubclassOf<UGameplayWidgetController> Class)
{
	if (Class->IsChildOf<UGameplayVitalWidgetController>())
	{
		if (!VitalController)
		{
			VitalController = NewObject<UGameplayVitalWidgetController>(this, VitalControllerClass);
			if (VitalController)
			{
				VitalController->Initialize(this);	
			}
		}
		return VitalController;
	}
	if (Class->IsChildOf<UGameplayCombatWidgetController>())
	{
		if (!CombatController)
		{
			CombatController = NewObject<UGameplayCombatWidgetController>(this, CombatControllerClass);
			if (CombatController)
			{
				CombatController->Initialize(this);	
			}
		}
		return CombatController;
	}
	return nullptr;
}

UAttributeSetBase* AFantasyCombatCharacter::GetAttributeSet(UClass* Class)
{
	if (Class->IsChildOf<UAttributeSet>())
	{
		const UAttributeSet * AttributeSet = GetAbilitySystemComponent()->GetAttributeSet(Class);
		if (IsValidEnsure(AttributeSet))
		{
			return Cast<UAttributeSetBase>(const_cast<UAttributeSet*>(AttributeSet));
		}
	}
	return nullptr;
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

bool AFantasyCombatCharacter::IsAlive() const
{
	return Alive;
}
