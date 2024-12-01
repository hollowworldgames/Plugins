// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "SystemActor.h"
#include "EngineActor.generated.h"

SPACECRAFT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(EnginePowerToThrustBonusTag);
SPACECRAFT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(EngineMaxRCSThrustBonusTag);

class UEngineAttributeSet;

UCLASS(BlueprintType)
class UEngineDefinitionData : public USystemDefinitionData
{
	GENERATED_BODY()
public :
	UPROPERTY()
	float ThrustToPowerBonus;
	UPROPERTY()
	float MaxRCSThrustBonus;
};

UCLASS()
class SPACECRAFT_API AEngineActor : public ASystemActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEngineActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UEngineAttributeSet> Engine;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> InitializeEffect;
};
