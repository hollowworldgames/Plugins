// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Records/CharacterRecord.h"

FCharacterRecord::FCharacterRecord(int AccountId, FString CharacterName, float Level, FVector Location, int World,
	int Race, EGender Gender, FString Class)
{
	this->AccountId = AccountId;
	this->CharacterName = CharacterName;
	this->Level = Level;
	this->Location = Location;
	this->World = World;
	this->Race = Race;
	this->Gender = Gender;
	this->Class = FName(Class);
}

FCharacterRecord::FCharacterRecord(FSQLitePreparedStatement& Statement)
{
	Statement.GetColumnValueByIndex(0, CharacterId);
	Statement.GetColumnValueByIndex(1, CharacterName);
	Statement.GetColumnValueByIndex(2, Gender);
	Statement.GetColumnValueByIndex(3, Level);
	Statement.GetColumnValueByIndex(4, World);
	Statement.GetColumnValueByIndex(5, Race);
	Statement.GetColumnValueByIndex(6, Class);
	Statement.GetColumnValueByIndex(7, Location.X);
	Statement.GetColumnValueByIndex(8, Location.Y);
	Statement.GetColumnValueByIndex(9, Location.Z);
}

void FCharacterRecord::WriteToStatement(FSQLitePreparedStatement& Statement)
{
	Statement.SetBindingValueByIndex(0, AccountId);
	Statement.SetBindingValueByIndex(1, CharacterName);
	Statement.SetBindingValueByIndex(2, Gender);
	Statement.SetBindingValueByIndex(3, Level);
	Statement.SetBindingValueByIndex(4, World);
	Statement.SetBindingValueByIndex(5, Race);
	Statement.SetBindingValueByIndex(6, Class);
	Statement.SetBindingValueByIndex(7, Location.X);
	Statement.SetBindingValueByIndex(8, Location.Y);
	Statement.SetBindingValueByIndex(9, Location.Z);
}
