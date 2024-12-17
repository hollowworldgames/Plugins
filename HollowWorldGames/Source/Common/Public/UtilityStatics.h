// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilityStatics.generated.h"

#define FlagActive(value, flag) (value & flag) == flag


USTRUCT()
struct COMMON_API FMultiControlAxis
{
	GENERATED_BODY()
	public :
		float Value = 0;
	void UpdateValue(int controlId, float value, bool increment)
	{
		Value = 0;
		if(Value > 0)
		{
			int n = 0;
		}
		if (increment)
		{
			if (Values.Contains(controlId))
			{
				float newValue = Values[controlId];
				if (value > 0)
				{
					newValue = FMath::Clamp(newValue += 0.01f, -1.0f, 1.0f);
				}
				else if (value < 0)
				{
					newValue = FMath::Clamp(newValue -= 0.01f, -1.0f, 1.0f);
				}
				Values[controlId] = newValue;
			}
			else
			{
				float newValue = 0;
				if (value > 0)
				{
					newValue = FMath::Clamp(newValue += 0.01f, -1.0f, 1.0f);
				}
				else if (value < 0)
				{
					newValue = FMath::Clamp(newValue -= 0.01f, -1.0f, 1.0f);
				}
				Values.Add(controlId, newValue);
			}
		}
		else
		{
			Values.Emplace(controlId, value);
		}
		for (const TPair<int,float> f : Values)
		{
			if (f.Value != 0.0)
			{
				Value = f.Value;
			}
		}
	}
	protected :
		TMap<int,float> Values;
};


UCLASS()
class COMMON_API UUtilityStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static FVector GetDirectionFrom(FVector from, FVector to);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static FVector GetDirectionTo(FVector from, FVector to);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static FVector GetVectorFrom(FVector from, FVector to);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static FVector GetVectorTo(FVector from, FVector to);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static float GetHeadingTo(FRotator current, FVector from, FVector to);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static float GetPitchAngleTo(FRotator current, FVector from, FVector to);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static float GetRollAngleTo(FVector from, FVector to);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static float GetBankAngleTo(FVector from, FVector to);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static float GetAOA(FVector wind, FVector forward, FVector right, bool left);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static void SetComponentCOM(UPrimitiveComponent* component, FVector com);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static bool IsOffensive(AActor* source, AActor* other);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static bool IsDefensive(AActor* source, AActor* other);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static bool IsInRange(AActor* source, AActor * other, double distance);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static bool IsAimedAt(AActor* source, AActor* other, float accuracy);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static bool IsAlignedTo(AActor* source, FVector location, float accuracy);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static FVector GetAimPoint(AActor* source, AActor* target, float muzzleVelocity);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static bool IsInFront(AActor* source, FVector location);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static bool IsInBack(AActor* source, FVector location);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static bool IsRight(AActor* source, FVector location);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static bool IsLeft(AActor* source, FVector location);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static bool IsUp(AActor* source, FVector location);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static bool IsDown(AActor* source, FVector location);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static float DeadZone(float value, float limit = 0.1f);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static float ApplySensitivity(float value, float sensitivity = 1);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static UObject* GetRandomFromList(TArray<UObject*>& list, bool remove = false);
	template<typename t> static t GetRandomItem(TArray<t>& list) //note no checks here
	{
		ensure(list.Num() > 0);
		int index = FMath::RandRange(0, list.Num()-1);
		return list[index];
	}
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static double InverseLerp(double value, double min, double max);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static float MapToRange(float min, float max, float value);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static FName MakeName(int seed);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static FVector2D GetViewportSize();
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static FVector2D GetViewportCenter();
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static float NormalizeValue(float value, float min, float max);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static float ComputeAOA(FVector forward, const FVector& Wind, const FVector& axis);
	UFUNCTION(BlueprintPure, Category = "Utility Statics")
		static TArray<FString> GetAllSaveGameSlotNames();
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static double Distance(AActor* Character, AActor* Opponent);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static FVector ComputeTorqueFromForce(FVector force, FVector location, FRotator orientation);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static float MoveTowardTargetValue(float current, float target, float rate, float delta, float min, float max);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static int MakeIndex2D(int x, int y, int sliceSize);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
		static FVector2D ToIndex2D(int index, int sliceSize);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
	static int MakeIndex3D(int x, int y, int z, FVector sliceSize);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
	static FVector ToIndex3D(int index, FVector sliceSize);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
	static UObject * GetDefaultObject(TSubclassOf<UObject> ObjectClass);
	template<typename t> static t GetNextItem(TArray<t>& items, t item)
	{
		ensure(items.Num());
		bool Next = false;
		for(int x = 0;x < items.Num();x++)
		{
			if(Next)
			{
				return items[x];
			}
			if(items[x] == item)
			{
				Next = true;
			}
		}
		return items[0];
	}
	
	template<typename t> static t GetPreviousItem(TArray<t>& items, t item)
	{
		ensure(items.Num());
		bool Next = false;
		for(int x = items.Num()-1;x > -1;x--)
		{
			if(Next)
			{
				return items[x];
			}
			else if(items[x] == item)
			{
				Next = true;
			}
		}
		return items[items.Num()-1];
	}
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
	static FVector ComputeImpactForce(AActor* Me, AActor* Them);
	UFUNCTION(BlueprintPure, Meta = (WorldContext = "WorldContext"), Category = "Utility Statics")
	static APawn * GetLocalPlayerPawn(const UObject * WorldContext);
	template <typename t> static t* GetTableRowByTag(UDataTable* Table, const FGameplayTag Tag)
	{
		return Table->FindRow<t>(Tag.GetTagName(), TEXT(""));
	}
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
	static float GetHighestFloat(TArray<float> Array);// Doesn't check array is value
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
	static float Roll(float Sides);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
	static bool RollChance(float Sides, float Chance);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
	static bool Roll100(float Chance);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
	static bool Roll1000(float Chance);
	UFUNCTION(BlueprintCallable, Category = "Utility Statics")
	static bool IsHit(float Accuracy, float EvadeChance, float BlockChance, bool& IsBlocked, bool& IsEvaded);
	UFUNCTION(BlueprintCallable, Meta = (WorldContext = "WorldContext"), Category = "Utility Statics")
	static void ShowMouse(const UObject * WorldContext);
	UFUNCTION(BlueprintCallable, Meta = (WorldContext = "WorldContext"), Category = "Utility Statics")
	static void HideMouse(const UObject * WorldContext);
	UFUNCTION(BlueprintPure, Category = "Utility Statics")
	static float ScaleAxisTo01(double Value);
	static void CopyTextureToArray(UTexture2D *Texture, TArray<FColor> &Array);
};

enum class LogSeverity
{
	Information,
	Warning,
	Error,
};

class COMMON_API  LogStop
{
};

class COMMON_API  LogStart
{
public :
	LogStart(LogSeverity severity, bool display);
	LogStart& operator << (const TCHAR * str);
	LogStart& operator << (FString& str);
	LogStart& operator << (const FName& name);
	LogStart& operator << (const int& value);
	LogStart& operator << (const float& value);
	LogStart& operator << (const double& value);
	LogStart& operator << (const FVector& value);
	LogStart& operator << (const FRotator& value);
	LogStart& operator << (LogStop stop);
protected :
	LogSeverity Severity;
	bool Display;
	FString Message;
};