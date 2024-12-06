// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayUtilities.h"
#include "GameplayAbilitySystemComponent.generated.h"

class UAttributeSetBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameplayEffectAppliedDelegate, FGameplayTagContainer&, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAbilityNotify, const FGameplayTag& , Ability);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FDamageNotify, ECombatRollResult, Result, float, Damage, const AActor *, Attacker, const AActor *, Target, FGameplayTag, DamageType);

USTRUCT()
struct FCustomEffectValue
{
	GENERATED_BODY()
	FCustomEffectValue(){}
	FCustomEffectValue(FGameplayTag Tag, float NewValue)
	{
		ValueTag = Tag;
		Value = NewValue;
	}
	UPROPERTY()
	FGameplayTag ValueTag;
	UPROPERTY()
	float Value = 0;
};

USTRUCT(BlueprintType)
struct FGameplayEffectApplied
{
	GENERATED_BODY()
	public :
		UPROPERTY()
	FGameplayEffectSpecHandle SpecHandle;
	UPROPERTY()
	FActiveGameplayEffectHandle EffectHandle;
	void Apply(UAbilitySystemComponent * Target, const AActor * Source, TSubclassOf<UGameplayEffect> EffectClass, float Level, TArray<FCustomEffectValue> Values);
	bool Remove() const;
	FString GetEffectName() const;
	bool IsExpired() const;
	bool IsInfinite() const;
	bool IsInstant() const;
	void UpdateDuration(float DeltaTime);
	EGameplayEffectDurationType GetDurationType() const;
	bool operator==(const FGameplayEffectApplied& Effect) const;
	UPROPERTY()
	float Duration = 0;
};

USTRUCT(BlueprintType)
struct GAMEPLAY_API FAbilityData
{
	GENERATED_BODY()
	FAbilityData() {}
	FAbilityData(TSubclassOf<UGameplayAbility> NewAbility, float NewLevel, FGameplayTag NewTag)
	{
		Ability = NewAbility;
		Level = NewLevel;
		Tag = NewTag;
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayAbility> Ability;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Level = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag Tag;
};

UCLASS()
class GAMEPLAY_API UGameplayAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	public :
	const TArray<FGameplayEffectApplied>& GetAppliedEffects() { return EffectsApplied; }
	UFUNCTION(BlueprintCallable)
	void ApplyGameplayEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level, const AActor * Source = nullptr);
	void ApplyGameplayEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level,TArray<FCustomEffectValue> Values, const AActor * Source = nullptr);
	void RemoveGameplayEffect(TSubclassOf<UGameplayEffect> EffectClass);
	virtual void SetLevel(float Level);
	virtual void InitializeAttributes(float Level);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AddAbilities(TArray<FAbilityData> Abilities, float OverrideLevel = 0);
	void AddAbility(FAbilityData Ability,bool Locked);
	void AddAbility(TSubclassOf<UGameplayAbility> Ability, int Level, FGameplayTag Status, FGameplayTag AbilityTag);
	bool MapAbility(FGameplayTag Ability, FGameplayTag Input);
	void UnmapAbility(FGameplayTag Input);
	bool HasAbility(FGameplayTag Ability);
	void SetAbilityStatus(FGameplayTag Ability, FGameplayTag Status);
	void OnAbilityInputPressed(FGameplayTag Tag);
	void OnAbilityInputHeld(FGameplayTag Tag);
	void OnAbilityInputReleased(FGameplayTag Tag);
	UFUNCTION(BlueprintCallable)
	void ActivateAbility(FGameplayTag AbilityTag);
	void DeactivateAbility(FGameplayTag AbilityTag);
	FGameplayEffectAppliedDelegate& GetEffectApplied() { return OnEffectApplied; }
	FGameplayEffectAppliedDelegate& GetEffectRemoved() { return OnEffectRemoved; }
	void BindDelegates();
	/*float GetXPForNextLevel(float Level) const;
	bool EvaluateXP(float Experience, float Level);*/
	UFUNCTION(BlueprintCallable)
	void RemoveEffect(FGameplayEffectApplied& Effect);
	UFUNCTION(BlueprintCallable)
	void ApplyGameplayEffects(TArray<TSubclassOf<UGameplayEffect>> Effects, float Level, AActor * Source = nullptr);
	void RemoveAllAbilities();
	UFUNCTION(BlueprintCallable)
	float GetEffectDurationRemaining(FGameplayTag Tag);
	FGameplayTag GetAbilityStatus(FGameplayTag Tag);
	FGameplayTagContainer& GetCooldownTags() { return Cooldowns; }
	void EnterCombat();
	void ExitCombat();
	bool IsInCombat() const { return ComponentHasTag(CombatTag.GetTagName()); }
	void SetDeadState();
	bool HasTag(FGameplayTag GameplayTag) const;
	UAttributeSetBase * GetAttributeSet(const TSubclassOf<UAttributeSetBase>& SubClass) const;
	float GetAttributeValue(FGameplayTag Attribute) const;
	void SetAttributeValue(FGameplayTag SkillId, float Level);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Abilities)
	FGameplayTag CombatTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Abilities)
	FGameplayTag AbilityEquippedTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Abilities)
	FGameplayTag AbilityUnequippedTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Abilities)
	FGameplayTag AbilityLockedTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Abilities)
	FGameplayTag AbilityNotPurchasedTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Abilities)
	FGameplayTag AbilityNoneTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Abilities)
	FGameplayTag AbilityStatusTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Abilities)
	FGameplayTag AbilityCooldownTag;
	TArray<FGameplayAbilitySpecHandle> GetActiveAbilities();
	UPROPERTY(EditDefaultsOnly, BlueprintAssignable, Category=Events)
	FAbilityNotify OnDeactivateAbility;
	UPROPERTY(EditDefaultsOnly, BlueprintAssignable, Category=Events)
	FAbilityNotify OnAbilityActivated;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Abilities)
	FGameplayTagContainer Cooldowns;
	void ReportDamage(ECombatRollResult Result, float Damage, const AActor * Attacker, const AActor * Target, FGameplayTag DamageType) const;
	UFUNCTION(Client, Reliable)
	void ReportDamage_Client(ECombatRollResult Result, float Damage, const AActor * Attacker, const AActor * Target, FGameplayTag DamageType) const;
protected :
	UFUNCTION()
	void OnAbilityFinished(const FAbilityEndedData& Data);
	FGameplayAbilitySpec * GetAbility(FGameplayTag Ability);
	void EffectApplied(UAbilitySystemComponent * Component, const FGameplayEffectSpec& Effect, FActiveGameplayEffectHandle ActiveEffectHandle) const;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	//FScalableFloat LevelFloat;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FGameplayEffectAppliedDelegate OnEffectApplied;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FGameplayEffectAppliedDelegate OnEffectRemoved;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FDamageNotify OnDamageEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	TSubclassOf<UGameplayEffect> LevelUpClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	TSubclassOf<UGameplayEffect> InCombatClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	TSubclassOf<UGameplayEffect> DeadClass;
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite, Category=Abilities)
	TArray<FGameplayEffectApplied> EffectsApplied;
	UPROPERTY(Transient, BlueprintReadWrite, Category=Abilities)
	TMap<FGameplayTag, FGameplayTag> MappedAbilities;
	TArray<FGameplayAbilitySpecHandle> ActiveAbilities;
	TMap<FGameplayTag, FGameplayAbilitySpecHandle> PassiveAbilities;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	TArray<TSubclassOf<UGameplayEffect>> AttributeInitializers;
};
