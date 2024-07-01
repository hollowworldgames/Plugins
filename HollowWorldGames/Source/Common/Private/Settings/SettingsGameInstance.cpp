// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Settings/SettingsGameInstance.h"

#include "XmlFile.h"
#include "Settings/SettingAsset.h"

void USettingsGameInstance::LoadSettings()
{
	FXmlFile SettingsFile(SettingsPath);
	for(TObjectPtr<USettingAsset> setting : Settings)
	{
		setting->Write(SettingsFile);
	}
}

void USettingsGameInstance::SaveSettings()
{
	FXmlFile SettingsFile;
	for(TObjectPtr<USettingAsset> setting : Settings)
	{
		setting->Write(SettingsFile);
	}
	SettingsFile.Save(SettingsPath);
}


void USettingsGameInstance::ResetSettings()
{
	for(TObjectPtr<USettingAsset> setting : Settings)
	{
		setting->Reset();
	}
	SaveSettings();
}