
#include "Data/SystemId.h"
#include "ScalableFloat.h"

FSystemId::FSystemId(const int NewSectorX, const int NewSectorY, const int NewSystemX,
                     int NewSystemY, const FVector& NewGalaxyPosition, int NewSystemZ, int64 NewSeed, int NewRing, int NewSubRing, int NewSatellite)
{
	SectorX = NewSectorX;
	SectorY = NewSectorY;
	SystemX = NewSystemX;
	SystemY = NewSystemY;
	SystemZ = NewSystemZ;
	Ring = NewRing;
	SubRing = NewSubRing;
	Satellite = NewSatellite;
	GalaxyPosition = NewGalaxyPosition;
	Seed = NewSeed;
}

bool FSystemId::IsSystem() const
{
	return Ring + SubRing + Satellite == 0;
}

bool FSystemId::IsLocation() const
{
	return Ring + SubRing + Satellite != 0;
}

bool FSystemId::IsSameLocation(const FSystemId& System) const
{
	return SectorX == System.SectorX && SectorY == System.SectorY && SystemX == System.SystemX && SystemY == System.SystemY
	&& Ring == System.Ring && SubRing == System.SubRing;
}

bool FSystemId::IsSameSystem(const FSystemId& System) const
{
	return  SectorX == System.SectorX && SectorY == System.SectorY && SystemX == System.SystemX && SystemY == System.SystemY;
}

void FSystemId::UpdatePosition(float GalaxyWidth, float SectorWidth, float GalaxyScale, FScalableFloat Heights, float MaxHeight)
{
	float X = SectorX * GalaxyWidth * SectorWidth + SystemX * SectorWidth;
	float Y = SectorY * GalaxyWidth * SectorWidth + SystemY * SectorWidth;
	float Z = 0;
	GalaxyPosition = FVector(X, Y, Z);
}

bool FSystemId::operator==(const FSystemId& Id) const
{
	return SectorX == Id.SectorX && SectorY == Id.SectorY &&
		SystemX == Id.SystemX && SystemY == Id.SystemY &&
			Ring == Id.Ring && SubRing == Id.SubRing && Satellite == Id.Satellite; 
}