// (c) Copyright 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Highlightable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class INTERACTIONS_API UHighlightable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INTERACTIONS_API IHighlightable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SetHighlighted() = 0;
	virtual void RemoveHighlighted() = 0;
	virtual EMouseCursor::Type GetMouseCursor() = 0;
};
