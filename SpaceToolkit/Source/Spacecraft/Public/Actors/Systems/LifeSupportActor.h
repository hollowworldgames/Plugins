// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SystemActor.h"
#include "LifeSupportActor.generated.h"

class ULifeSupportAttributeSet;

UCLASS(BlueprintType)
class ULifeSupportDefinitionData : public USystemDefinitionData
{
	GENERATED_BODY()
public:
};

UCLASS()
class SPACECRAFT_API ALifeSupportActor : public ASystemActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALifeSupportActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category=Components)
	TObjectPtr<ULifeSupportAttributeSet> LifeSupportAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> InitializeEffect;
};


