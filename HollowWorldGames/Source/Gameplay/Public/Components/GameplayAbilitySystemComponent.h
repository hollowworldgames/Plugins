// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayStructs.h"
#include "GameplayAbilitySystemComponent.generated.h"

class UAttributeSetBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttributeChanged, FGameplayTag, AttributeTag, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameplayEffectAppliedDelegate, FGameplayTagContainer&, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAbilityNotify, const FGameplayTag& , Ability);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FDamageNotify, ECombatRollResult, Result, float, Damage, const AActor *, Attacker, const AActor *, Target, FGameplayTag, DamageType);

USTRUCT(BlueprintType)
struct FGameplayEffectApplied
{
	GENERATED_BODY()
public :
	UPROPERTY()
	FGameplayEffectSpecHandle SpecHandle;
	UPROPERTY()
	FActiveGameplayEffectHandle EffectHandle;
	void Apply(UAbilitySystemComponent * Target, const AActor * Source, TSubclassOf<UGameplayEffect> EffectClass, float Level,const TArray<FCustomEffectValue>& Values);
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
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	TSubclassOf<UGameplayAbility> Ability;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	float Level = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	FGameplayTag Tag;
};

UCLASS()
class GAMEPLAY_API UGameplayAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public :
	const TArray<FGameplayEffectApplied>& GetAppliedEffects() { return EffectsApplied; }
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void ApplyGameplayEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level, const AActor * Source = nullptr);
	void ApplyGameplayEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level,const TArray<FCustomEffectValue>& Values, const AActor * Source = nullptr);
	void RemoveGameplayEffect(TSubclassOf<UGameplayEffect> EffectClass);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AddAbilities(TArray<FAbilityData> Abilities, float OverrideLevel = 0);
	void AddAbility(const FAbilityData& Ability,bool Locked);
	void AddAbility(TSubclassOf<UGameplayAbility> Ability, int Level, FGameplayTag Status, FGameplayTag AbilityTag);
	bool MapAbility(FGameplayTag Ability, FGameplayTag Input);
	void UnmapAbility(FGameplayTag Input);
	bool HasAbility(FGameplayTag Ability);
	void SetAbilityStatus(FGameplayTag Ability, FGameplayTag Status);
	void OnAbilityInputPressed(FGameplayTag Tag);
	void OnAbilityInputHeld(FGameplayTag Tag);
	void OnAbilityInputReleased(FGameplayTag Tag);
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void ActivateAbility(FGameplayTag AbilityTag);
	void DeactivateAbility(FGameplayTag AbilityTag);
	FGameplayEffectAppliedDelegate& GetEffectApplied() { return OnEffectApplied; }
	FGameplayEffectAppliedDelegate& GetEffectRemoved() { return OnEffectRemoved; }
	void BindDelegates();
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void RemoveEffect(FGameplayEffectApplied& Effect);
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void ApplyGameplayEffects(TArray<TSubclassOf<UGameplayEffect>> Effects, float Level, AActor * Source = nullptr);
	void ApplyGameplayEffects(TArray<TSubclassOf<UGameplayEffect>> Effects, float Level, const TArray<FCustomEffectValue>& Values, AActor * Source = nullptr);
	void RemoveAllAbilities();
	UFUNCTION(BlueprintCallable, Category = "Ability")
	float GetEffectDurationRemaining(FGameplayTag Tag);
	FGameplayTag GetAbilityStatus(FGameplayTag Tag);
	FGameplayTagContainer& GetCooldownTags() { return Cooldowns; }
	bool HasTag(FGameplayTag GameplayTag) const;
	UAttributeSetBase * GetAttributeSet(const TSubclassOf<UAttributeSetBase>& SubClass) const;
	void GetAllAttributeSets(TArray<UAttributeSetBase*>& OutAttributes, const TSubclassOf<UAttributeSetBase>& SubClass) const;
	float GetAttributeValue(FGameplayTag Attribute) const;
	void SetAttributeValue(FGameplayTag Attribute, float Level) const;
	FAttributeChanged& GetAttributeChanged() { return OnAttributeChanged; }
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
	void AttributeChanged(FGameplayTag AttributeTag, float Value);
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnAbilityFinished(const FAbilityEndedData& Data);
	FGameplayAbilitySpec * GetAbility(FGameplayTag Ability);
	void EffectApplied(UAbilitySystemComponent * Component, const FGameplayEffectSpec& Effect, FActiveGameplayEffectHandle ActiveEffectHandle) const;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FGameplayEffectAppliedDelegate OnEffectApplied;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FGameplayEffectAppliedDelegate OnEffectRemoved;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FDamageNotify OnDamageEvent;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FAttributeChanged OnAttributeChanged;
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite, Category=Abilities)
	TArray<FGameplayEffectApplied> EffectsApplied;
	UPROPERTY(Transient, BlueprintReadWrite, Category=Abilities)
	TMap<FGameplayTag, FGameplayTag> MappedAbilities;
	TArray<FGameplayAbilitySpecHandle> ActiveAbilities;
	TMap<FGameplayTag, FGameplayAbilitySpecHandle> PassiveAbilities;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	TArray<TSubclassOf<UGameplayEffect>> AttributeInitializers;
};
