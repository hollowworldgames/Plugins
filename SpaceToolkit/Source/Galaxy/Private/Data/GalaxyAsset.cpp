// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/GalaxyAsset.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxyColorRedTag, "Galaxy.Color.Red", "Galaxy Color Red");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxyColorGreenTag, "Galaxy.Color.Green", "Galaxy Color Green");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxyColorBlueTag, "Galaxy.Color.Blue", "Galaxy Color Blue");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxyColorAlphaTag, "Galaxy.Color.Alpha", "Galaxy Color Alpha");

UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxySpiralCoreSizeTag, "Galaxy.Spiral.CoreSize", "Spiral Galaxy Core Size");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxySpiralArmCountTag, "Galaxy.Spiral.ArmCount", "Spiral Galaxy Arm Count");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxySpiralArmWidthTag, "Galaxy.Spiral.ArmWidth", "Spiral Galaxy Arm Width");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxySpiralArmLengthTag, "Galaxy.Spiral.ArmLength", "Spiral Galaxy Arm Length");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GalaxySpiralArmTightnessTag, "Galaxy.Spiral.ArmTightness", "Spiral Galaxy Arm Tightness");


int64 FSystemId::GetSeed() const
{
	return 1;
}

FVector FSystemId::GetGalaxyLocation() const
{
	return FVector::Zero();
}

FVector FSystemId::GetSystemLocation() const
{
	return FVector::Zero();
}

bool FSystemId::IsSystem() const
{
	return true;
}

bool FSystemId::IsLocation() const
{
	return true;
}

bool FSystemId::IsSameLocation(FSystemId System)
{
	return true;
}

bool FSystemId::IsSameSystem(FSystemId system)
{
	return true;
}

void UGalaxyAsset::CreateGalaxy()
{
	switch(GalaxyType)
	{
	case EGalaxyType::EGalaxyType_Spiral :
		{
			CreateSpiralGalaxy();
			break;
		}
	case EGalaxyType::EGalaxyType_Bar:
		{
			CreateBarGalaxy();
			break;
		}
	case EGalaxyType::EGalaxyType_Ring:
		{
			CreateRingGalaxy();
			break;
		}
	case EGalaxyType::EGalaxyType_Elliptical:
		{
			CreateEllipticalGalaxy();
			break;
		}
	}
}

void UGalaxyAsset::CreateSpiralGalaxy()
{
	
}

void UGalaxyAsset::CreateBarGalaxy()
{
	
}

void UGalaxyAsset::CreateRingGalaxy()
{
	
}

void UGalaxyAsset::CreateEllipticalGalaxy()
{
	
}
