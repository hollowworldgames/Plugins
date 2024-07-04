// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/Consumer.h"
#include "Interfaces/Source.h"
#include "PowerSystemComponent.generated.h"


class UBatteryDefinition;
class UGeneratorDefinition;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FLIGHT_API UPowerSystemComponent : public UActorComponent, public ISource
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPowerSystemComponent();
	// Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
                               FActorComponentTickFunction* ThisTickFunction) override;
	virtual EResource GetProvided() override { return EResource::Power; };
	virtual float Consume(float Amount) override;
	virtual void AddConsumer(TScriptInterface<IConsumer> Consumer) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TArray<TSubclassOf<UGeneratorDefinition>> GeneratorClasses;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Settings)
	TArray<TObjectPtr<UGeneratorDefinition>> Generators;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TSubclassOf<UBatteryDefinition> BatteryClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	TObjectPtr<UBatteryDefinition> Battery;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	TArray<TScriptInterface<IConsumer>> Consumers;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float PowerGenerated = 0;
};
