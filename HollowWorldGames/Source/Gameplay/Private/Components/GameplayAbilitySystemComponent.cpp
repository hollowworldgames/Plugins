// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Components/GameplayAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Attributes/AttributeSetBase.h"
#include "UtilityStatics.h"

FString FGameplayEffectApplied::GetEffectName() const
{
	return SpecHandle.Data.Get()->Def.Get()->GetName();
}

bool FGameplayEffectApplied::IsExpired() const
{
	return GetDurationType() == EGameplayEffectDurationType::HasDuration && Duration < 0;
}

void FGameplayEffectApplied::Apply(UAbilitySystemComponent* Target, const AActor* Source, TSubclassOf<UGameplayEffect> EffectClass, float Level, TArray<FCustomEffectValue> Values)
{
	UAbilitySystemComponent * SourceComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(const_cast<AActor*>(Source));
    if(SourceComponent)
    {
    	FGameplayEffectContextHandle Handle = SourceComponent->MakeEffectContext();
		Handle.AddSourceObject(Source);
		SpecHandle = SourceComponent->MakeOutgoingSpec(EffectClass,Level,Handle);
		ensure(SpecHandle.IsValid());
		for(FCustomEffectValue Value : Values)
		{
			UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, Value.ValueTag, Value.Value);
		}
	
		EffectHandle = SourceComponent->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), Target);
		//ensure(EffectHandle.IsValid());
		if(GetDurationType() == EGameplayEffectDurationType::HasDuration)
		{
			Duration = SpecHandle.Data.Get()->Duration;
		}
	}
}

bool FGameplayEffectApplied::Remove() const
{
	if(!IsExpired() && EffectHandle.IsValid())
	{
		EffectHandle.GetOwningAbilitySystemComponent()->RemoveActiveGameplayEffect(EffectHandle);
		return true;
	}
	return false;
}

bool FGameplayEffectApplied::IsInfinite() const
{
	return GetDurationType() == EGameplayEffectDurationType::Infinite;
}

bool FGameplayEffectApplied::IsInstant() const
{
	return GetDurationType() == EGameplayEffectDurationType::Instant;
}

void FGameplayEffectApplied::UpdateDuration(float DeltaTime)
{
	Duration -= DeltaTime;
}

EGameplayEffectDurationType FGameplayEffectApplied::GetDurationType() const
{
	if(SpecHandle.Data && SpecHandle.Data->Def)
	{
		return SpecHandle.Data.Get()->Def.Get()->DurationPolicy;
	}
	return EGameplayEffectDurationType::Instant;
}

bool FGameplayEffectApplied::operator==(const FGameplayEffectApplied& Effect) const
{
	return EffectHandle == Effect.EffectHandle;
}



void UGameplayAbilitySystemComponent::ApplyGameplayEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level,
                                                          const AActor* Source)
{
	if(!IsValid(Source))
	{
		Source = GetAvatarActor();
	}
	if(ensure(EffectClass) && ensure(Level > 0))
	{
		FGameplayEffectApplied Applied;
		Applied.Apply(this, Source, EffectClass, Level, TArray<FCustomEffectValue>());
		if(!Applied.IsInstant())
		{
			EffectsApplied.Add(Applied);
		}
	}
}

void UGameplayAbilitySystemComponent::ApplyGameplayEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level,
	TArray<FCustomEffectValue> Values, const AActor* Source)
{
	if(!IsValid(Source))
	{
		Source = GetAvatarActor();
	}
	LogStart(LogSeverity::Information, true) << "Source = " << *Source->GetName() << LogStop();
	if(ensure(EffectClass) && ensure(Level > 0))
	{
		FGameplayEffectApplied Applied;
		Applied.Apply(this, Source, EffectClass, Level, Values);
		if(!Applied.IsInstant())
		{
			EffectsApplied.Add(Applied);
		}
	}
}

void UGameplayAbilitySystemComponent::SetLevel(float Level)
{
	LogStart(LogSeverity::Information, true) << TEXT("Level set to ") << Level << LogStop();
	ApplyGameplayEffect(LevelUpClass, Level);
}

void UGameplayAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                    FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	TArray<FGameplayEffectApplied> Remove;
	for(FGameplayEffectApplied& applied : EffectsApplied)
	{
		if(applied.GetDurationType() == EGameplayEffectDurationType::HasDuration)
		{
			applied.UpdateDuration(DeltaTime);
			if(applied.IsExpired())
			{
				Remove.Add(applied);
				FGameplayTagContainer tags;
				applied.SpecHandle.Data->GetAllAssetTags(tags);
				OnEffectRemoved.Broadcast(tags);
			}
		}
	}
	for(FGameplayEffectApplied& remove : Remove)
	{
		EffectsApplied.Remove(remove);
	}
}

void UGameplayAbilitySystemComponent::AddAbilities(TArray<FAbilityData> Abilities, float OverrideLevel)
{
	for(const FAbilityData Ability : Abilities)
	{
		LogStart(LogSeverity::Information, true) << "Ability Added " << *Ability.Tag.ToString() << LogStop();
		AddAbility(Ability.Ability, (OverrideLevel > 0) ? OverrideLevel : Ability.Level, AbilityLockedTag, Ability.Tag);
	}
}

void UGameplayAbilitySystemComponent::AddAbility(FAbilityData Ability, bool Locked)
{
	AddAbility(Ability.Ability, Ability.Level, (Locked) ? AbilityLockedTag : AbilityEquippedTag, Ability.Tag);
}

void UGameplayAbilitySystemComponent::AddAbility(TSubclassOf<UGameplayAbility> Ability, int Level, FGameplayTag Status, FGameplayTag AbilityTag)
{
	if(!HasAbility(AbilityTag))
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability, Level);
		AbilitySpec.DynamicAbilityTags.AddTag(Status);
		AbilitySpec.DynamicAbilityTags.AddTag(AbilityTag);
		FGameplayAbilitySpecHandle GrantedAbility = GiveAbility(AbilitySpec);
		MarkAbilitySpecDirty(AbilitySpec);
	}
}

bool UGameplayAbilitySystemComponent::MapAbility(FGameplayTag Ability, FGameplayTag Input)
{
	if(FGameplayAbilitySpec * Spec = GetAbility(Ability))
	{
		UnmapAbility(Input); //unmap any ability already mapped
		if(Spec->DynamicAbilityTags.HasTagExact(AbilityUnequippedTag))
		{
			MappedAbilities[Input] = Ability;
			Spec->DynamicAbilityTags.AddTag(AbilityEquippedTag);
			return true;
		}
		//oops tried to equip a locked ability
		ensureMsgf(false, TEXT("ability %s is locked and can't be equipped"), *Ability.ToString());
	}
	else
	{
		ensureMsgf(false, TEXT("You don't have ability %s"), *Ability.ToString());
	}
	return false;
}

void UGameplayAbilitySystemComponent::UnmapAbility(FGameplayTag Input)
{
	if(MappedAbilities.Contains(Input))
	{
		FGameplayTag Ability = MappedAbilities[Input];
		MappedAbilities.Remove(Input);
		SetAbilityStatus(Ability, AbilityUnequippedTag);
    }
}

bool UGameplayAbilitySystemComponent::HasAbility(FGameplayTag Ability)
{
	FScopedAbilityListLock ActiveScopeLock(*this);
	for(auto A : GetActivatableAbilities())
	{
		if(A.DynamicAbilityTags.HasTagExact(Ability))
		{
			return true;
		}
	}
	return false;
}

FGameplayAbilitySpec* UGameplayAbilitySystemComponent::GetAbility(FGameplayTag Ability)
{
	FScopedAbilityListLock ActiveScopeLock(*this);
	ensure(GetActivatableAbilities().Num() > 0);
	for(FGameplayAbilitySpec& A : GetActivatableAbilities())
	{
		if(A.DynamicAbilityTags.HasTagExact(Ability))
		{
			return &A;
		}
	}
	LogStart(LogSeverity::Error, false) << TEXT("Ability Not Found") << *Ability.ToString() << LogStop();
	return nullptr;
}

void UGameplayAbilitySystemComponent::SetAbilityStatus(FGameplayTag Ability, FGameplayTag Status)
{
	FScopedAbilityListLock ActiveScopeLock(*this);
	for(auto A : GetActivatableAbilities())
	{
		if(A.DynamicAbilityTags.HasTagExact(Ability))
		{
			FGameplayTagContainer Tags = A.DynamicAbilityTags;
			//remove any status tag from Ability
			for(FGameplayTag Tag : Tags)
			{
				if(Tag.MatchesTag(AbilityStatusTag))
				{
					A.DynamicAbilityTags.RemoveTag(Tag);
				}
			}
			//add new status tag
			A.DynamicAbilityTags.AddTag(Status);
		}
	}
}

void UGameplayAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag Tag)
{
	/*if(FGameplayTag * Ability = MappedAbilities.Find(Tag))
	{*/
		FGameplayAbilitySpec * Spec = GetAbility(Tag);
		if(ensure(Spec))
		{
			AbilitySpecInputPressed(*Spec);
			if(!Spec->IsActive())
			{
				if(TryActivateAbility(Spec->Handle))
				{
					OnAbilityActivated.Broadcast(Tag);
					ActiveAbilities.AddUnique(Spec->Handle);
					InvokeReplicatedEvent(EAbilityGenericReplicatedEvent::InputPressed, Spec->Handle, Spec->ActivationInfo.GetActivationPredictionKey());
				}
			}
		}
	/*}
	else
	{
		LogStart(LogSeverity::Error, false) << "Ability Not Found " << *Tag.ToString() << LogStop();
	}*/
}

void UGameplayAbilitySystemComponent::OnAbilityInputHeld(FGameplayTag Tag)
{
	/*if(FGameplayTag * Ability = MappedAbilities.Find(Tag))
	{*/
		FGameplayAbilitySpec * Spec = GetAbility(Tag);
		if(ensure(Spec) && !Spec->IsActive())
		{
			if(TryActivateAbility(Spec->Handle))
			{
				OnAbilityActivated.Broadcast(Tag);
				ActiveAbilities.AddUnique(Spec->Handle);
				InvokeReplicatedEvent(EAbilityGenericReplicatedEvent::InputPressed, Spec->Handle, Spec->ActivationInfo.GetActivationPredictionKey());
			}
		}
	/*}
	else
	{
		LogStart(LogSeverity::Error, false) << "Ability Not Found " << *Tag.ToString() << LogStop();
	}*/
}

void UGameplayAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag Tag)
{
	/*if(FGameplayTag * Ability = MappedAbilities.Find(Tag))
	{*/
		FGameplayAbilitySpec * Spec = GetAbility(Tag);
		if(ensure(Spec) && Spec->IsActive())
		{
			AbilitySpecInputReleased(*Spec);
			InvokeReplicatedEvent(EAbilityGenericReplicatedEvent::InputReleased, Spec->Handle, Spec->ActivationInfo.GetActivationPredictionKey());
		}
	/*}
	else
	{
		LogStart(LogSeverity::Error, false) << "Ability Not Found " << *Tag.ToString() << LogStop();
	}*/
}

void UGameplayAbilitySystemComponent::ActivateAbility(FGameplayTag AbilityTag)
{
	FScopedAbilityListLock ActiveScopeLock(*this);
	for(auto Ability : GetActivatableAbilities())
	{
		if(Ability.DynamicAbilityTags.HasTagExact(AbilityTag))
		{
			if(!Ability.IsActive())
			{
				if(TryActivateAbility(Ability.Handle))
				{
					ActiveAbilities.AddUnique(Ability.Handle);
					OnAbilityActivated.Broadcast(AbilityTag);
				}
			}
		}
	}
}

void UGameplayAbilitySystemComponent::DeactivateAbility(FGameplayTag AbilityTag)
{
	OnDeactivateAbility.Broadcast(AbilityTag);
}

void UGameplayAbilitySystemComponent::BindDelegates()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UGameplayAbilitySystemComponent::EffectApplied);
	OnAbilityEnded.AddUObject(this, &UGameplayAbilitySystemComponent::OnAbilityFinished);
}

/*float UGameplayAbilitySystemComponent::GetXPForNextLevel(float Level) const
{
	float needed = 0;
	FString Context;
	const FRealCurve* Curve = nullptr;
	if(LevelFloat.EvaluateCurveAtLevel(needed, Curve, Level + 1, Context))
	{
		return needed;
	}
	return 0;
}

bool UGameplayAbilitySystemComponent::EvaluateXP(float Experience, float Level)
{
	const float xpNeeded = GetXPForNextLevel(Level);
	LogStart(LogSeverity::Information, true) << "XP = " << Experience << " Needed = " << xpNeeded << LogStop();
	if(Experience > xpNeeded)
	{
		return true;
	}
	return false;
}*/

void UGameplayAbilitySystemComponent::RemoveEffect(FGameplayEffectApplied& Effect)
{
	if(Effect.Remove())
	{
		FGameplayTagContainer tags;
		Effect.SpecHandle.Data->GetAllAssetTags(tags);
		OnEffectRemoved.Broadcast(tags);
	}
}

void UGameplayAbilitySystemComponent::ApplyGameplayEffects(TArray<TSubclassOf<UGameplayEffect>> Effects, float Level, AActor * Source)
{
	for(const TSubclassOf<UGameplayEffect> Effect : Effects)
	{
		ApplyGameplayEffect(Effect, Level, Source);
	}
}

void UGameplayAbilitySystemComponent::RemoveAllAbilities()
{
	//FScopedAbilityListLock ActiveScopeLock(*this);
	ClearAllAbilities();
	MappedAbilities.Empty();
}

float UGameplayAbilitySystemComponent::GetEffectDurationRemaining(FGameplayTag Tag)
{
	FGameplayEffectQuery Query = FGameplayEffectQuery::MakeQuery_MatchAnyEffectTags(Tag.GetSingleTagContainer());
	TArray<float> Durations = GetActiveEffectsTimeRemaining(Query);
	if(Durations.Num() > 0)
	{
		const float Duration = UUtilityStatics::GetHighestFloat(Durations);
		return Duration;
	}
	return 0;
}

FGameplayTag UGameplayAbilitySystemComponent::GetAbilityStatus(FGameplayTag Tag)
{
	FScopedAbilityListLock ActiveScopeLock(*this);
	for(auto Ability : GetActivatableAbilities())
	{
		if(Ability.DynamicAbilityTags.HasTagExact(Tag))
		{
			for(FGameplayTag TestTag : Ability.DynamicAbilityTags)
			{
				if(TestTag.MatchesTag(AbilityStatusTag))
				{
					return Tag;
				}
			}
		}
	}
	return AbilityNoneTag;
}

void UGameplayAbilitySystemComponent::EnterCombat()
{
	if(!ComponentHasTag(CombatTag.GetTagName()))
	{
		LogStart(LogSeverity::Information, true) << "Combat Start" << LogStop();
		ApplyGameplayEffect(InCombatClass, 1);
	}
}

void UGameplayAbilitySystemComponent::ExitCombat()
{
	LogStart(LogSeverity::Information, true) << "Combat Stop" << LogStop();
	FGameplayTagContainer Tags;
	Tags.AddTag(CombatTag);
	RemoveActiveEffectsWithGrantedTags(Tags);
}

void UGameplayAbilitySystemComponent::SetDeadState()
{
	ApplyGameplayEffect(DeadClass, 1);
}

bool UGameplayAbilitySystemComponent::HasTag(FGameplayTag GameplayTag) const
{
	FGameplayTagContainer Container;
	GetOwnedGameplayTags(Container);
	return Container.HasTag(GameplayTag);
}

UAttributeSetBase* UGameplayAbilitySystemComponent::GetAttributeSet(const TSubclassOf<UAttributeSetBase>& SubClass) const
{
	UAttributeSet * Set = const_cast<UAttributeSet*>(GetAttributeSubobject(SubClass));
	return Cast<UAttributeSetBase>(Set);
}

float UGameplayAbilitySystemComponent::GetAttributeValue(FGameplayTag Attribute) const
{
	const TArray<UAttributeSet*> Attributes = GetSpawnedAttributes();
	for(UAttributeSet * Set : Attributes)
	{
		UAttributeSetBase * SetBase = Cast<UAttributeSetBase>(Set);
		if(SetBase)
		{
			if(SetBase->HasAttribute(Attribute))
			{
				return SetBase->GetAttributeValue(Attribute);
			}
		}
	}
	return 0;
}

void UGameplayAbilitySystemComponent::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	const TArray<UAttributeSet*> Attributes = GetSpawnedAttributes();
	for(UAttributeSet * Set : Attributes)
	{
		UAttributeSetBase * SetBase = Cast<UAttributeSetBase>(Set);
		if(SetBase)
		{
			if(SetBase->HasAttribute(Attribute))
			{
				SetBase->SetAttributeValue(Attribute, Value);
				break;
			}
		}
	}
}


void UGameplayAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* Component,
                                                    const FGameplayEffectSpec& Effect, FActiveGameplayEffectHandle ActiveEffectHandle) const
{
	FGameplayTagContainer tags;
	Effect.GetAllAssetTags(tags);
	OnEffectApplied.Broadcast(tags);
}


TArray<FGameplayAbilitySpecHandle> UGameplayAbilitySystemComponent::GetActiveAbilities()
{
	return ActiveAbilities;
}

void UGameplayAbilitySystemComponent::ReportDamage(ECombatRollResult Result, float Damage, const AActor* Attacker,
	const AActor* Target, FGameplayTag DamageType) const
{
	APawn * Character = Cast<APawn>(GetAvatarActor());
	if(ensure(Character))
	{
		switch(Character->GetNetMode())
		{
		case NM_Standalone :
		case NM_ListenServer :
		case NM_DedicatedServer :
			{
				//write to event log
				break;
			}
		default :
			{
				break;
			}
		}
		if(Character->IsPlayerControlled())
		{
			OnDamageEvent.Broadcast(Result, Damage, Attacker, Target, DamageType);
			ReportDamage_Client(Result, Damage, Attacker, Target, DamageType);
		}
	}
}

void UGameplayAbilitySystemComponent::ReportDamage_Client_Implementation(ECombatRollResult Result, float Damage,
	const AActor* Attacker, const AActor* Target, FGameplayTag DamageType) const
{
	OnDamageEvent.Broadcast(Result, Damage, Attacker, Target, DamageType);
}

void UGameplayAbilitySystemComponent::OnAbilityFinished(const FAbilityEndedData& Data)
{
	ActiveAbilities.Remove(Data.AbilitySpecHandle);
}
