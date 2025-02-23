// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "UI/GameplayWidgetController.h"

void UGameplayWidgetController::Initialize(ACharacter* NewCharacter)
{
	Character = NewCharacter;
	BindToAttributes();
}

void UGameplayWidgetController::BindToAttributes()
{
	
}

FName UGameplayWidgetController::GetCharacterName() const
{
	return NAME_None;
}
