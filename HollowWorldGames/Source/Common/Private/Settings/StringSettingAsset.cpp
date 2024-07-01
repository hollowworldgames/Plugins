// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Settings/StringSettingAsset.h"

#include "XmlFile.h"


class FXmlNode;

void UStringSettingAsset::SetValue(FString NewValue)
{
	Value = NewValue;
}

void UStringSettingAsset::Write(FXmlFile& File)
{
	Super::Write(File);
	File.GetRootNode()->AppendChildNode(FString(SettingName.ToString()), Value);
}

void UStringSettingAsset::Read(FXmlFile& File)
{
	Super::Read(File);
	FXmlNode* Node = File.GetRootNode()->FindChildNode(SettingName.ToString());
	if(ensure(Node))
	{
		Value = Node->GetContent();
	}
}