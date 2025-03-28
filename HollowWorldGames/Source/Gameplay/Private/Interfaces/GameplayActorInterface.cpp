﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Interfaces/GameplayActorInterface.h"


// Add default functionality here for any IGameplayActorInterface functions that are not pure virtual.
UGameplayWidgetController* IGameplayActorInterface::GetWidgetController_K2(
	const TSubclassOf<UGameplayWidgetController> Class)
{
	return GetWidgetController(Class);
}
