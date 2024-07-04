// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/Consumer.h"
#include "Interfaces/Source.h"
#include "HydraulicSystemComponent.generated.h"


class UHydraulicReservoirDefinition;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FLIGHT_API UHydraulicSystemComponent : public UActorComponent, public ISource, public IConsumer
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHydraulicSystemComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	virtual EResource GetProvided() override { return EResource::Hydraulic; };
	virtual float Consume(float Amount) override;
	virtual void AddConsumer(TScriptInterface<IConsumer> Consumer) override;
	virtual FGameplayTag GetComponentTag() override { return ComponentTag; }
	virtual EResource GetNeededResource() override { return EResource::Power; };
	virtual float GetNeeded() override;
	virtual float Provided(float Amount) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	TArray<TScriptInterface<IConsumer>> Consumers;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FGameplayTag ComponentTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TArray<TSubclassOf<UHydraulicReservoirDefinition>> ReservoirClasses;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	TArray<TObjectPtr<UHydraulicReservoirDefinition>> Reservoirs;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float Power = 0;
};
