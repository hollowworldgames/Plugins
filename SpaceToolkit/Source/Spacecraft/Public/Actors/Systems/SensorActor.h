// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "SystemActor.h"
#include "SensorActor.generated.h"

SPACECRAFT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SensorStrengthBonusTag);
SPACECRAFT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SensorResolutionBonusTag);

class USensorAttributeSet;

UCLASS(BlueprintType)
class USensorDefinitionData : public USystemDefinitionData
{
	GENERATED_BODY()
public :
	UPROPERTY()
	float SignalStrength;
	UPROPERTY()
	float SignalResolution;
};

UCLASS()
class SPACECRAFT_API ASensorActor : public ASystemActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASensorActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attributes")
	TObjectPtr<USensorAttributeSet> SensorAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> InitializeEffect;
};
