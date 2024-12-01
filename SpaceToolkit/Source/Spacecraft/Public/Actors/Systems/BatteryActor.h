// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "SystemActor.h"
#include "BatteryActor.generated.h"

class UBatteryAttributeSet;

UCLASS(BlueprintType)
class UBatteryDefinitionData : public USystemDefinitionData
{
	GENERATED_BODY()
public :
	UPROPERTY()
	float BatteryCapacityBonus;
};

SPACECRAFT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(BatteryCapacityBonusTag);

UCLASS()
class SPACECRAFT_API ABatteryActor : public ASystemActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABatteryActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attributes")
	TObjectPtr<UBatteryAttributeSet> BatteryAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> InitializeEffect;
  };
