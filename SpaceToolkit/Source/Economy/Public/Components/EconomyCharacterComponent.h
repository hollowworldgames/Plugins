// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTags.h"
#include "EconomyCharacterComponent.generated.h"



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECONOMY_API UEconomyCharacterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UEconomyCharacterComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	virtual bool CanRefine(FGameplayTag Material);
	virtual bool CanConstruct(FGameplayTag Object, float Level);
	virtual FGameplayTag GetCurrentConstructObject() const { return CurrentConstructObjectTag; }
	virtual FGameplayTag GetCurrentRefineMaterial() const { return CurrentRefineMaterialTag; }
	virtual TArray<FGameplayTag> GetRefinableMaterials();
	virtual TArray<FGameplayTag> GetConstructableObjects();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient)
	FGameplayTag CurrentConstructObjectTag;
	UPROPERTY(VisibleAnywhere, Transient)
	FGameplayTag CurrentRefineMaterialTag;
	UPROPERTY(VisibleAnywhere, Transient)
	FGameplayTagContainer RefinableMaterials;
	UPROPERTY(VisibleAnywhere, Transient)
	FGameplayTagContainer ConstructableObjects;
};
