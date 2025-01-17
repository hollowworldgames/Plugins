// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ViewableCharacter.h"
#include "GameFramework/Character.h"
#include "Interfaces/DataComponentInterface.h"
#include "DataCharacter.generated.h"

class UDataAccessComponent;

UCLASS()
class DATAACCESS_API ADataCharacter : public AViewableCharacter, public IDataComponentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADataCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Save() const;
	UFUNCTION()
	virtual void OnLoaded();
	virtual void OnPrepareSave() const;
	virtual UDataAccessComponent * GetDataAccessComponent() const override { return DataAccessComponent; }
	virtual void Load(int64 NewActorId) override;
	virtual void OnRep_PlayerState() override;
	virtual void PossessedBy(AController* NewController) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TSubclassOf<UDataAccessComponent> SingleDataClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TSubclassOf<UDataAccessComponent> ServerDataClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TSubclassOf<UDataAccessComponent> ClientDataClass;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Data)
	TObjectPtr<UDataAccessComponent> DataAccessComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Data)
	int64 ActorId;
private:
	UFUNCTION(NetMulticast, Reliable)
    virtual void Multicast_PostLoad();
};


