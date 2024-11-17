// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "ObjectConstructionComponent.generated.h"

class IMaterialSourceInterface;
class IEconomyCharacterInterface;
class IComponentSourceInterface;
class IResourceSourceInterface;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FConstructedDelegate, UObjectConstructionComponent*, Component);

USTRUCT(BlueprintType)
struct FConstructJob
{
	GENERATED_BODY()
	FConstructJob(): Qty(0)
	{
	}

	FConstructJob(FGameplayTag NewMaterial, TScriptInterface<IResourceSourceInterface> NewResourceSource, TScriptInterface<IMaterialSourceInterface> NewMaterialSource,
	              TScriptInterface<IComponentSourceInterface> NewComponentSource, TScriptInterface<IEconomyCharacterInterface> NewCharacter, int NewQty);
	UPROPERTY()
	FGameplayTag Material;
	UPROPERTY()
	TScriptInterface<IResourceSourceInterface> ResourceSource;
	UPROPERTY()
	TScriptInterface<IMaterialSourceInterface> MaterialSource;
	UPROPERTY()
	TScriptInterface<IComponentSourceInterface> ComponentSource;
	UPROPERTY()
	TScriptInterface<IEconomyCharacterInterface> Character;
	UPROPERTY()
	int Qty;
};

UCLASS(ClassGroup=(Economy), Abstract)
class ECONOMY_API UObjectConstructionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UObjectConstructionComponent();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	bool StartConstruction(FGameplayTag Object, TScriptInterface<IResourceSourceInterface> ResourceSource, TScriptInterface<IComponentSourceInterface> ComponentSource,
		TScriptInterface<IMaterialSourceInterface> MaterialSource, TScriptInterface<IEconomyCharacterInterface> Character, int Qty);
	virtual bool CanConstruct(FGameplayTag Object, TScriptInterface<IResourceSourceInterface> ResourceSource, TScriptInterface<IComponentSourceInterface> ComponentSource,
		TScriptInterface<IMaterialSourceInterface> MaterialSource, TScriptInterface<IEconomyCharacterInterface> Character, int Qty);
protected:
	virtual bool DoJob(const FConstructJob& Job);
	virtual void CommitResources(const FConstructJob& ConstructJob);
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Material")
	FConstructedDelegate OnConstructed;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "Jobs")
	TArray<FConstructJob> Jobs;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Jobs")
	int MaxJobs = 1;
};
