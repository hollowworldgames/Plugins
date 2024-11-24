// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ViewableWorldSubsystem.generated.h"

class UViewPointComponent;
class IViewable;
/**
 * 
 */
UCLASS()
class  VIEWPOINTS_API UViewableWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public :
	void AddViewable(TScriptInterface<IViewable> Viewable);
	void RemoveViewable(TScriptInterface<IViewable> Viewable);
	void CycleToNextViewable();
	void CycleToNextViewPoint() const;
	void ResetToPlayerViewable();
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override { return true; }
	UViewPointComponent* GetCurrentViewPoint() const;
protected :
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Status)
	TArray<TScriptInterface<IViewable>> Viewables;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Status)
	TScriptInterface<IViewable> Current;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Status)
	TScriptInterface<IViewable> Player;
};
