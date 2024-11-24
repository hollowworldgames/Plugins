// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Systems/SystemActor.h"
#include "ReactorActor.generated.h"

class UReactorAttributeSet;

UCLASS(BlueprintType)
class UReactorDefinitionData : public USystemDefinitionData
{
	GENERATED_BODY()
public :
	
};

UCLASS()
class SPACECRAFT_API AReactorActor : public ASystemActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AReactorActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UReactorAttributeSet> Reactor;
};

