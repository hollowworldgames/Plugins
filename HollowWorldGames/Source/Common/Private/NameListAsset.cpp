// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "NameListAsset.h"

#include "UtilityStatics.h"

TArray<FName> UNameListAsset::GetFirstNames()
{
	TArray<FName> names;
	FNameTableRow* FoundRow = nullptr;
	for (auto It : First->GetRowMap())
	{
		FNameTableRow* Row = reinterpret_cast<FNameTableRow*>(It.Value);
		names.Add(Row->Name);
	}
	return names;
}

TArray<FName> UNameListAsset::GetMiddleNames()
{
	TArray<FName> names;
	FNameTableRow* FoundRow = nullptr;
	for (auto It : Middle->GetRowMap())
	{
		FNameTableRow* Row = reinterpret_cast<FNameTableRow*>(It.Value);
		names.Add(Row->Name);
	}
	return names;
}

TArray<FName> UNameListAsset::GetLastNames()
{
	TArray<FName> names;
	FNameTableRow* FoundRow = nullptr;
	for (auto It : Last->GetRowMap())
	{
		FNameTableRow* Row = reinterpret_cast<FNameTableRow*>(It.Value);
		names.Add(Row->Name);
	}
	return names;
}

FName UNameListAsset::GetRandomFirstName()
{
	TArray<FName> names = GetFirstNames();
	return UUtilityStatics::GetRandomItem<FName>(names);
}

FName UNameListAsset::GetRandomMiddleName()
{
	TArray<FName> names = GetMiddleNames();
	return UUtilityStatics::GetRandomItem<FName>(names);
}

FName UNameListAsset::GetRandomLastName()
{
	TArray<FName> names = GetLastNames();
	return UUtilityStatics::GetRandomItem<FName>(names);
}
