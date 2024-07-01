// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "RandomGenerator.h"


// State for a singleton Mersenne Twister. If you want to make this into a
// class, these are what you need to isolate.


#define M32(x) (0x80000000 & x) // 32nd MSB
#define L31(x) (0x7FFFFFFF & x) // 31 LSBs
#define UNROLL(expr) \
y = M32(MT[i]) | L31(MT[i+1]); \
MT[i] = MT[expr] ^ (y >> 1) ^ (((int32(y) << 31) >> 31) & MAGIC); \
++i;

#define M64(x) (0x8000000000000000 & x) // 64nd MSB
#define L63(x) (0x7FFFFFFFFFFFFFFF & x) // 63 LSBs
#define UNROLL64(expr) \
  y = M64(MT[i]) | L63(MT[i+1]); \
  MT[i] = MT[expr] ^ (y >> 1) ^ (((int64(y) << 63) >> 63) & MAGIC); \
  ++i;

FVector FRandomGenerator32::RandVector(double Size)
{
	return FVector(RandDouble() * Size, RandDouble() * Size, RandDouble() * Size);	
}

FVector FRandomGenerator32::RandVector(const FVector& Min,const FVector& Max)
{
	return FVector(RandRange(Min.X, Max.X), RandRange(Min.Y, Max.Y), RandRange(Min.Z, Max.Z));
}

void FRandomGenerator32::GenerateNumbers()
{
    /*
     * For performance reasons, we've unrolled the loop three times, thus
     * mitigating the need for any modulus operations. Anyway, it seems this
     * trick is old hat: http://www.quadibloc.com/crypto/co4814.htm
     */
    size_t i = 0;
    uint32 y;
    // i = [0 ... 226]
    while ( i < DIFF )
    {
        /*
         * We're doing 226 = 113*2, an even number of steps, so we can safely
         * unroll one more step here for speed:
         */
    	UNROLL(i+PERIOD);

#ifdef MT_UNROLL_MORE
      UNROLL(i+PERIOD);
#endif
     }

  // i = [227 ... 622]
     while ( i < SIZE -1 )
     {
	    /*
	     * 623-227 = 396 = 2*2*3*3*11, so we can unroll this loop in any number
	     * that evenly divides 396 (2, 4, 6, etc). Here we'll unroll 11 times.
	     */
	     UNROLL(i-DIFF);

	#ifdef MT_UNROLL_MORE
	     UNROLL(i-DIFF);
	     UNROLL(i-DIFF);
	     UNROLL(i-DIFF);
	     UNROLL(i-DIFF);
	     UNROLL(i-DIFF);
	     UNROLL(i-DIFF);
	     UNROLL(i-DIFF);
	     UNROLL(i-DIFF);
	     UNROLL(i-DIFF);
	     UNROLL(i-DIFF);
	#endif
	}

	{
		// i = 623, last step rolls over
		y = M32(MT[SIZE-1]) | L31(MT[0]);
		MT[SIZE-1] = MT[PERIOD-1] ^ (y >> 1) ^ (((int32(y) << 31) >>
		      31) & MAGIC);
	}

    // Temper all numbers in a batch
	for (i = 0; i < SIZE; ++i)
	{
		y = MT[i];
		y ^= y >> 11;
		y ^= y << 7  & 0x9d2c5680;
		y ^= y << 15 & 0xefc60000;
		y ^= y >> 18;
		MT_TEMPERED[i] = y;
	}
    index = 0;
}

FRandomGenerator32::FRandomGenerator32()
{
	Seed(0);
}

void FRandomGenerator32::Seed(uint32 value)
{
  
  MT[0] = value;
  index = SIZE;

  for ( uint32 i=1; i<SIZE; ++i )
    MT[i] = 0x6c078965*(MT[i-1] ^ MT[i-1]>>30) + i;
}

int FRandomGenerator32::RandRange(int lower, int upper)
{
	const int32 Range = (upper - lower) + 1;
	int value = 0;
	if(Range > 0)
	{
		value = FMath::Floor(RandPositiveFloat() * static_cast<float>(Range)) + lower;
	}
	return value;
}

float FRandomGenerator32::RandRange(float lower, float Upper)
{
	const float Range = (Upper - lower) + 1.0f;
	return Range > 0.0f ? FMath::Min(RandPositiveFloat() * Range, Range - 1.0f) + lower : 0.0f;
}

double FRandomGenerator32::RandRange(double Lower, double Upper)
{
	const double Range = (Upper - Lower) + 1.0;
	return Range > 0.0 ? FMath::Min(RandPositiveDouble() * Range, Range - 1.0) + Lower : 0.0;
}

float FRandomGenerator32::RandFloat()
{
	return static_cast<float>(RandInt()) / static_cast<float>(INT32_MAX);
}

double FRandomGenerator32::RandDouble()
{
	return static_cast<double>(RandInt()) / static_cast<double>(INT32_MAX);
}

float FRandomGenerator32::RandPositiveFloat()
{
	return FMath::Abs(static_cast<float>(RandInt()) / static_cast<float>(INT32_MAX));
}

double FRandomGenerator32::RandPositiveDouble()
{
	return FMath::Abs(static_cast<double>(RandInt()) / static_cast<double>(INT32_MAX));
}

int FRandomGenerator32::RandInt()
{
	if (index == SIZE ) {
		GenerateNumbers();
		index = 0;
	}
	return MT_TEMPERED[index++];
}


FRandomGenerator64::FRandomGenerator64()
{
	Seed(0);
}

void FRandomGenerator64::Seed(uint64 seed)
{
	MT[0] = seed;
	index = SIZE;

	for ( uint32 i=1; i<SIZE; ++i )
		MT[i] = 0x6c078965*(MT[i-1] ^ MT[i-1]>>60) + i;
}

int FRandomGenerator64::RandRange(int lower, int upper)
{
	const int64 Range = (upper - lower) + 1;
	return Range > 0 ? FMath::Min(FMath::Floor(RandFloat() * static_cast<double>(Range)), static_cast<double>(Range) - 1) : 0;
}

int FRandomGenerator64::RandInt64()
{
	if (index == SIZE ) {
		GenerateNumbers();
		index = 0;
	}
	return MT_TEMPERED[index++];
}

float FRandomGenerator64::RandFloat()
{
	const float f = RandInt64();
	return f / static_cast<float>(INT64_MAX);
}

double FRandomGenerator64::RandDouble()
{
	const double f = RandInt64();
	return f / static_cast<double>(INT64_MAX);
}

float FRandomGenerator64::RandRange(float lower, float upper)
{
	return static_cast<float>(RandInt64()) / static_cast<float>(INT64_MAX);
}

double FRandomGenerator64::RandRange(double lower, double upper)
{
	return static_cast<double>(RandInt64()) / static_cast<double>(INT64_MAX);
}

FVector FRandomGenerator64::RandVector(FVector min, FVector max)
{
	return FVector(RandRange(min.X, max.X), RandRange(min.Y, max.Y), RandRange(min.Z, max.Z));
}

FVector FRandomGenerator64::RandVector(double size)
{
	return FVector(RandDouble() * size, RandDouble() * size, RandDouble() * size);
}

void FRandomGenerator64::GenerateNumbers()
{
	/*
	 * For performance reasons, we've unrolled the loop three times, thus
	 * mitigating the need for any modulus operations. Anyway, it seems this
	 * trick is old hat: http://www.quadibloc.com/crypto/co4814.htm
	 */
	size_t i = 0;
	uint64 y;
	// i = [0 ... 226]
	while ( i < DIFF )
	{
		/*
		 * We're doing 226 = 113*2, an even number of steps, so we can safely
		 * unroll one more step here for speed:
		 */
		UNROLL64(i+PERIOD);

#ifdef MT_UNROLL_MORE
		UNROLL64(i+PERIOD);
#endif
	}

	// i = [227 ... 622]
	while ( i < SIZE -1 )
	{
		/*
		 * 623-227 = 396 = 2*2*3*3*11, so we can unroll this loop in any number
		 * that evenly divides 396 (2, 4, 6, etc). Here we'll unroll 11 times.
		 */
		UNROLL64(i-DIFF);

#ifdef MT_UNROLL_MORE
		UNROLL64(i-DIFF);
		UNROLL64(i-DIFF);
		UNROLL64(i-DIFF);
		UNROLL64(i-DIFF);
		UNROLL64(i-DIFF);
		UNROLL64(i-DIFF);
		UNROLL64(i-DIFF);
		UNROLL64(i-DIFF);
		UNROLL64(i-DIFF);
		UNROLL64(i-DIFF);
#endif
	}

	{
		// i = 623, last step rolls over
		y = M64(MT[SIZE-1]) | L63(MT[0]);
		MT[SIZE-1] = MT[PERIOD-1] ^ (y >> 1) ^ (((int64(y) << 63) >>
			  63) & MAGIC);
	}

	// Temper all numbers in a batch
	for (i = 0; i < SIZE; ++i)
	{
		y = MT[i];
		y ^= y >> 11;
		y ^= y << 7  & 0x9d2c5680;
		y ^= y << 15 & 0xefc60000;
		y ^= y >> 18;
		MT_TEMPERED[i] = y;
	}
	index = 0;
}