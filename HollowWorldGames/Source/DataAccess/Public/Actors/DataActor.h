﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actors/ViewableActor.h"
#include "Interfaces/DataComponentInterface.h"
#include "DataActor.generated.h"

class UDataAccessComponent;

UCLASS()
class DATAACCESS_API ADataActor : public AViewableActor, public IDataComponentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADataActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Save() const;
	UFUNCTION()
	virtual void OnLoaded();
	virtual void OnPrepareSave() const;
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_PostLoad();
	virtual UDataAccessComponent * GetDataAccessComponent() const override { return DataAccessComponent; }
	virtual void Load(int64 ActorId) override;
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
};


