// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameFramework/Actor.h"
#include "SystemActor.generated.h"

class ASpaceCraftActor;
class UGameplayAbility;
class UVitalAttributeSet;
class UGameplayAbilitySystemComponent;

UCLASS(Blueprintable, BlueprintType)
class USystemDefinitionData : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Level = 1;
};

USTRUCT(BlueprintType)
struct FSystemEffectToApply
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayEffect> Effect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Component;
};

UCLASS()
class SPACECRAFT_API ASystemActor : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASystemActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintNativeEvent)
	bool IsOn();
	UFUNCTION(BlueprintNativeEvent)
	void SetOn(bool On);
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void InitializeAttributes(ASpaceCraftActor * SystemOwner, USystemDefinitionData * SystemData);
	FGameplayTag GetComponentTag() const { return ComponentTag; }
	void StartEffects(ASpaceCraftActor * SystemOwner) const;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UGameplayAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attributes")
	TObjectPtr<UVitalAttributeSet> VitalAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Abilities")
	FAbilityData StartAbility;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Abilities")
	FAbilityData StopAbility;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTag StartTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTag ComponentTag;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	TArray<FSystemEffectToApply> Effects;
	UPROPERTY()
	TObjectPtr<ASpaceCraftActor> Ship;
};
