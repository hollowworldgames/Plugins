// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Interfaces/Consumer.h"
#include "Interfaces/Source.h"
#include "FuelSystemComponent.generated.h"


class UFuelTankDefinition;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FLIGHT_API UFuelSystemComponent : public UActorComponent , public ISource, public IConsumer
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFuelSystemComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	virtual EResource GetProvided() override;
	virtual float Consume(float Amount) override;
	virtual void AddConsumer(TScriptInterface<IConsumer> Consumer) override;
	virtual FGameplayTag GetComponentTag() override { return ComponentTag; }
	virtual float Provided(float Amount) override;
	virtual EResource GetNeededResource() override;
	virtual float GetNeeded() override;
	TScriptInterface<IConsumer> GetTarget(FGameplayTag Tag) const;
	TScriptInterface<ISource> GetSource(FGameplayTag Tag) const;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float PowerAvailable = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float PowerNeeded = 0.1f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TArray<TSubclassOf<UFuelTankDefinition>> FuelTankClasses;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	TArray<TObjectPtr<UFuelTankDefinition>> FuelTanks;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Status)
	TArray<TScriptInterface<IConsumer>> Consumers;
	FGameplayTag ComponentTag;
};


