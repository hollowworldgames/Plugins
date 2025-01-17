// Copyright (c) 2024 Hollow World Games llc All Rights Reserved


#include "Settings/EnumSettingAsset.h"

int UEnumSettingAsset::GetEnumValue() const
{
	return 0;
}

void UEnumSettingAsset::Read(FXmlFile& File)
{
	Super::Read(File);
	FXmlNode* Node = File.GetRootNode()->FindChildNode(SettingName.ToString());
	if(ensure(Node))
	{
		Value = Node->GetContent();
	}
}

void UEnumSettingAsset::Write(FXmlFile& File)
{
	Super::Write(File);
	File.GetRootNode()->AppendChildNode(FString(SettingName.ToString()), Value);
}

void UEnumSettingAsset::Reset()
{
	Value = DefaultValue;
}
