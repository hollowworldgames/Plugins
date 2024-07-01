// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RandomGenerator.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct COMMON_API FRandomGenerator32 
{
	GENERATED_BODY()
	public :
		FRandomGenerator32();
	FRandomGenerator32(uint32 seed) { Seed(seed); }
	void Seed(uint32 seed);
	int RandRange(int lower, int upper);
	float RandRange(float lower, float upper);
	double RandRange(double lower, double upper);
	float RandFloat();
	double RandDouble();
	float RandPositiveFloat();
	double RandPositiveDouble();
	int RandInt();
	template<class t> t GetRandomItemFromArray(TArray<t>& List);
	FVector RandVector(double Size);
	FVector RandVector(const FVector& Min,const FVector& Max);
	protected :
		void GenerateNumbers();
	static const size_t SIZE   = 624;
	static const size_t PERIOD = 397;
	static const size_t DIFF   = SIZE - PERIOD;
	static const uint32 MAGIC = 0x9908b0df;
	uint32 MT[SIZE];
	uint32 MT_TEMPERED[SIZE];
	size_t index = SIZE;
};




template <class t>
t FRandomGenerator32::GetRandomItemFromArray(TArray<t>& List)
{
	int i = RandRange(0, List.Num()-1);
	return List[i];
}


USTRUCT(BlueprintType)
struct COMMON_API FRandomGenerator64
{
	GENERATED_BODY()
	public :
		FRandomGenerator64();
	FRandomGenerator64(uint64 seed) { Seed(seed); }
	void Seed(uint64 seed);
	int RandRange(int lower, int upper);
	float RandRange(float lower, float upper);
	double RandRange(double lower, double upper);
	FVector RandVector(FVector min, FVector max);
	FVector RandVector(double size);
	float RandFloat();
	double RandDouble();
	int RandInt64();
	protected :
		void GenerateNumbers();
	static const size_t SIZE   = 624;
	static const size_t PERIOD = 397;
	static const size_t DIFF   = SIZE - PERIOD;
	static const uint64 MAGIC = 0x9908b0df;
	uint64 MT[SIZE];
	uint64 MT_TEMPERED[SIZE];
	size_t index = SIZE;
};


