// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Settings/FloatSettingAsset.h"

#include "XmlFile.h"


class FXmlNode;

void UFloatSettingAsset::SetValue(float NewValue)
{
	if(ensure(NewValue >= MinValue && NewValue <= MaxValue))
	{
		Value = NewValue;
	}
}

void UFloatSettingAsset::Write(FXmlFile& File)
{
	Super::Write(File);
	File.GetRootNode()->AppendChildNode(FString(SettingName.ToString()), FString::Printf(TEXT("%f"), Value));
}

void UFloatSettingAsset::Read(FXmlFile& File)
{
	Super::Read(File);
	FXmlNode* Node = File.GetRootNode()->FindChildNode(SettingName.ToString());
	if(ensure(Node))
	{
		Value = FCString::Atof(*Node->GetContent());
	}
}