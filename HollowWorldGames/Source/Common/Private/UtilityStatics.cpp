// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "UtilityStatics.h"

#include "ConverterStatics.h"
#include "IXRTrackingSystem.h"
#include "PlatformFeatures.h"
#include "SaveGameSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


FVector UUtilityStatics::GetDirectionFrom(FVector from, FVector to)
{
	FVector direction = from - to;
	direction.Normalize();
	return direction;
}

FVector UUtilityStatics::GetDirectionTo(FVector from, FVector to)
{
	FVector direction = to - from;
	direction.Normalize();
	return direction;
}

FVector UUtilityStatics::GetVectorFrom(FVector from, FVector to)
{
	FVector direction = from - to;
	return direction;
}

FVector UUtilityStatics::GetVectorTo(FVector from, FVector to)
{
	FVector direction = to - from;
	return direction;
}

float UUtilityStatics::GetHeadingTo(FRotator current, FVector from, FVector to)
{
	return UConverterStatics::AngleToSigned(current.Yaw - UKismetMathLibrary::FindLookAtRotation(from, to).Yaw);
}

float UUtilityStatics::GetPitchAngleTo(FRotator current, FVector from, FVector to)
{
	return UConverterStatics::AngleToSigned(current.Pitch - UKismetMathLibrary::FindLookAtRotation(from, to).Pitch);
}

float UUtilityStatics::GetRollAngleTo(FVector from, FVector to)
{
	return UKismetMathLibrary::FindLookAtRotation(from, to).Roll;
}

float UUtilityStatics::GetBankAngleTo(FVector from, FVector to)
{
	float bank = UKismetMathLibrary::FindLookAtRotation(from, to).Roll;
	if (bank > 180)
	{
		bank = bank - 360;
	}
	return bank;
}

void UUtilityStatics::SetComponentCOM(UPrimitiveComponent* component, FVector com)
{
	FTransform transform(FRotator(), com);
	FBodyInstance* body = component->GetBodyInstance();
	if (ensure(body))
	{
		body->SetMassSpaceLocal(transform);
	}
}

float UUtilityStatics::GetAOA(FVector wind, FVector forward, FVector right, bool left)
{

	float angle = wind.Rotation().Pitch - forward.Rotation().Pitch;
	float bank = UKismetMathLibrary::MakeRotFromZ(right).Roll;
	if (bank > 180)
	{
		bank = bank - 360;
	}
	if (left)
	{
		angle = FMath::Clamp(angle + bank / 180.0f, -1.0f, 1.0f);
	}
	else
	{
		angle = FMath::Clamp(angle - bank / 180.0f, -1.0f, 1.0f);
	}
	return 0;
}

bool UUtilityStatics::IsDefensive(AActor* source, AActor* other)
{
	if(source && other)
	{
		FVector vectorTo = GetDirectionTo(source->GetActorLocation(), other->GetActorLocation());
		if (FVector::DotProduct(source->GetActorForwardVector(), vectorTo) < 0.0f)
		{
			return FVector::DotProduct(GetDirectionTo(other->GetActorLocation(), source->GetActorLocation()), source->GetActorForwardVector()) > 0.0f;
		}
	}
	return false;
}

bool UUtilityStatics::IsInRange(AActor* source, AActor* other, double distance)
{
	return Distance(source, other) < distance;
}

bool UUtilityStatics::IsOffensive(AActor* source, AActor* other)
{
	if(source && other)
	{
		FVector vectorTo = GetDirectionTo(source->GetActorLocation(), other->GetActorLocation());
		if (FVector::DotProduct(source->GetActorForwardVector(), vectorTo) > 0.0f)
		{
			return FVector::DotProduct(GetDirectionTo(other->GetActorLocation(), source->GetActorLocation()), source->GetActorForwardVector()) < 0.0f;
		}
	}
	return false;
}

bool UUtilityStatics::IsAimedAt(AActor* source, AActor* other, float accuracy)
{
	FVector directionTo = GetDirectionTo(source->GetActorLocation(), other->GetActorLocation());
	return source->GetActorForwardVector().Dot(directionTo) > accuracy;
}

bool UUtilityStatics::IsAlignedTo(AActor* source, FVector location, float accuracy)
{
	FVector directionTo = GetDirectionTo(source->GetActorLocation(), location);
	return source->GetActorForwardVector().Dot(directionTo) > accuracy;
}

FVector UUtilityStatics::GetAimPoint(AActor* source, AActor* target, float muzzleVelocity)
{
	float time = FVector::Distance(source->GetActorLocation(), target->GetActorLocation()) / muzzleVelocity;
	FVector distanceAim = target->GetVelocity() * time;
	return target->GetActorLocation() + distanceAim;
}


bool UUtilityStatics::IsInFront(AActor* source, FVector location)
{
	return source->GetActorForwardVector().Dot(GetDirectionTo(source->GetActorLocation(), location)) > 0;
}

bool UUtilityStatics::IsInBack(AActor* source, FVector location)
{
	return source->GetActorForwardVector().Dot(GetDirectionTo(source->GetActorLocation(), location)) < 0;
}

bool UUtilityStatics::IsRight(AActor* source, FVector location)
{
	return source->GetActorRightVector().Dot(GetDirectionTo(source->GetActorLocation(), location)) > 0;
}

bool UUtilityStatics::IsLeft(AActor* source, FVector location)
{
	return source->GetActorRightVector().Dot(GetDirectionTo(source->GetActorLocation(), location)) < 0;
}

bool UUtilityStatics::IsUp(AActor* source, FVector location)
{
	return source->GetActorUpVector().Dot(GetDirectionTo(source->GetActorLocation(), location)) > 0;
}

bool UUtilityStatics::IsDown(AActor* source, FVector location)
{
	return source->GetActorUpVector().Dot(GetDirectionTo(source->GetActorLocation(), location)) < 0;
}

float UUtilityStatics::DeadZone(float value, float limit)
{
	if (FMath::Abs(value) > limit)
	{
		return value;
	}
	return 0;
}

float UUtilityStatics::ApplySensitivity(float value, float sensitivity)
{
	if (sensitivity == 2.0f || sensitivity == 4.0f)
	{
		sensitivity += 0.01f;
	}
	if (value > 0)
	{
		return FMath::Pow(value, sensitivity);
	}
	else if (value < 0)
	{
		return -FMath::Pow(-value, sensitivity);
	}
	return 0;
}

UObject* UUtilityStatics::GetRandomFromList(TArray<UObject*>& list, bool remove)
{
	int index = FMath::RandRange(0, list.Num() - 1);
	UObject* object = list[index];
	if (remove)
	{
		list.RemoveAt(index);
	}
	return object;
}

double UUtilityStatics::InverseLerp(double value, double min, double max)
{
	return FMath::Clamp((value - min) / (max - min), 0.0, 1.0);
}

float UUtilityStatics::MapToRange(float min, float max, float value)
{
	return min + (value * (max - min));
}

const char* FirstSyllables[] = { "ob", "oc", "od","of","og","oh","oj","ok","ol","om","on","op","or","os","ot","ov","ow","ox","oy","oz",
							"B", "C", "D",
							"Eb", "Ec", "Ed","Ef","Eg","Eh","Ej","Ek","El","Em","En","Ep","Er","Es","Et","Ev","Ew","Ex","Ey","Ez",
							"F", "G", "H",
							"Ib", "Ic", "Id","If","Ig","Ih","Ij","Ik","Il","Im","In","Ip","Ir","Is","It","Iv","Iw","Ix","Iy","Iz",
							"J", "K", "L", "M", "N",
							"Ob", "Oc", "Od","Of","Og","Oh","Oj","Ok","Ol","Om","On","Op","Or","Os","Ot","Ov","Ow","Ox","Oy","Oz",
							"P", "Qu", "R", "S", "T",
							"Ub", "Uc", "Ud","Uf","Ug","Uh","Uj","Uk","Ul","Um","Un","Up","Ur","Us","Ut","Uv","Uw","Ux","Uy","Uz",
							"V", "W", "X", "Y", "Z" };
const char* MiddleSyllables[] = { "oba", "oca", "oda", "ofa","oga", "oha", "oja", "oka", "ola", "oma", "ona", "opa", "oqua", "ora", "osa", "ota", "ova", "owa", "oxa", "oya", "oza",
							"obe", "oce", "ode", "ofe","oge", "ohe", "oje", "oke", "ole", "ome", "one", "ope", "oque", "ore", "ose", "ote", "ove", "owe", "oxe", "oye", "oze",
							"obi", "oci", "odi", "ofi","ogi", "ohi", "oji", "oki", "oli", "omi", "oni", "opi", "oqui", "ori", "osi", "oti", "ovi", "owi", "oxi", "oyi", "ozi",
							"obo", "oco", "odo", "ofo","ogo", "oho", "ojo", "oko", "olo", "omo", "ono", "opo", "oquo", "oro", "oso", "oto", "ovo", "owo", "oxo", "oyo", "ozo",
							"obu", "ocu", "odu", "ofu","ogu", "ohu", "oju", "oku", "olu", "omu", "onu", "opu",  "oru", "osu", "otu", "ovu", "owu", "oxu", "oyu", "ozu",
							"eba", "eca", "eda", "efa","ega", "eha", "eja", "eka", "ela", "ema", "ena", "epa", "equa", "era", "esa", "eta", "eva", "ewa", "exa", "eya", "eza",
							"ebe", "ece", "ede", "efe","ege", "ehe", "eje", "eke", "ele", "eme", "ene", "epe", "eque", "ere", "ese", "ete", "eve", "ewe", "exe", "eye", "eze",
							"ebi", "eci", "edi", "efi","egi", "ehi", "eji", "eki", "eli", "emi", "eni", "epi", "equi", "eri", "esi", "eti", "evi", "ewi", "exi", "eyi", "ezi",
							"ebo", "eco", "edo", "efo","ego", "eho", "ejo", "eko", "elo", "emo", "eno", "epo", "equo", "ero", "eso", "eto", "evo", "ewo", "exo", "eyo", "ezo",
							"ebu", "ecu", "edu", "efu","egu", "ehu", "eju", "eku", "elu", "emu", "enu", "epu",  "eru", "esu", "etu", "evu", "ewu", "exu", "eyu", "ezu",
							"iba", "ica", "ida", "ifa","iga", "iha", "ija", "ika", "ila", "ima", "ina", "ipa", "iqua", "ira", "isa", "ita", "iva", "iwa", "ixa", "iya", "iza",
							"ibe", "ice", "ide", "ife","ige", "ihe", "ije", "ike", "ile", "ime", "ine", "ipe", "ique", "ire", "ise", "ite", "ive", "iwe", "ixe", "iye", "ize",
							"ibi", "ici", "idi", "ifi","igi", "ihi", "iji", "iki", "ili", "imi", "ini", "ipi", "iqui", "iri", "isi", "iti", "ivi", "iwi", "ixi", "iyi", "izi",
							"ibo", "ico", "ido", "ifo","igo", "iho", "ijo", "iko", "ilo", "imo", "ino", "ipo", "iquo", "iro", "iso", "ito", "ivo", "iwo", "ixo", "iyo", "izo",
							"ibu", "icu", "idu", "ifu","igu", "ihu", "iju", "iku", "ilu", "imu", "inu", "ipu",  "iru", "isu", "itu", "ivu", "iwu", "ixu", "iyu", "izu",
							"oba", "oca", "oda", "ofa","oga", "oha", "oja", "oka", "ola", "oma", "ona", "opa", "oqua", "ora", "osa", "ota", "ova", "owa", "oxa", "oya", "oza",
							"obe", "oce", "ode", "ofe","oge", "ohe", "oje", "oke", "ole", "ome", "one", "ope", "oque", "ore", "ose", "ote", "ove", "owe", "oxe", "oye", "oze",
							"obi", "oci", "odi", "ofi","ogi", "ohi", "oji", "oki", "oli", "omi", "oni", "opi", "oqui", "ori", "osi", "oti", "ovi", "owi", "oxi", "oyi", "ozi",
							"obo", "oco", "odo", "ofo","ogo", "oho", "ojo", "oko", "olo", "omo", "ono", "opo", "oquo", "oro", "oso", "oto", "ovo", "owo", "oxo", "oyo", "ozo",
							"obu", "ocu", "odu", "ofu","ogu", "ohu", "oju", "oku", "olu", "omu", "onu", "opu",  "oru", "osu", "otu", "ovu", "owu", "oxu", "oyu", "ozu",
							"uba", "uca", "uda", "ufa","uga", "uha", "uja", "uka", "ula", "uma", "una", "upa", "uqua", "ura", "usa", "uta", "uva", "uwa", "uxa", "uya", "uza",
							"ube", "uce", "ude", "ufe","uge", "uhe", "uje", "uke", "ule", "ume", "une", "upe", "uque", "ure", "use", "ute", "uve", "uwe", "uxe", "uye", "uze",
							"ubi", "uci", "udi", "ufi","ugi", "uhi", "uji", "uki", "uli", "umi", "uni", "upi", "uqui", "uri", "usi", "uti", "uvi", "uwi", "uxi", "uyi", "uzi",
							"ubo", "uco", "udo", "ufo","ugo", "uho", "ujo", "uko", "ulo", "umo", "uno", "upo", "uquo", "uro", "uso", "uto", "uvo", "uwo", "uxo", "uyo", "uzo",
							"ubu", "ucu", "udu", "ufu","ugu", "uhu", "uju", "uku", "ulu", "umu", "unu", "upu",  "uru", "usu", "utu", "uvu", "uwu", "uxu", "uyu", "uzu",
							"yba", "yca", "yda", "yfa","yga", "yha", "yja", "yka", "yla", "yma", "yna", "ypa", "yqua", "yra", "ysa", "yta", "yva", "ywa", "yxa", "yya", "yza",
							"ybe", "yce", "yde", "yfe","yge", "yhe", "yje", "yke", "yle", "yme", "yne", "ype", "yque", "yre", "yse", "yte", "yve", "ywe", "yxe", "yye", "yze",
							"ybi", "yci", "ydi", "yfi","ygi", "yhi", "yji", "yki", "yli", "ymi", "yni", "ypi", "yqui", "yri", "ysi", "yti", "yvi", "ywi", "yxi", "yyi", "yzi",
							"ybo", "yco", "ydo", "yfo","ygo", "yho", "yjo", "yko", "ylo", "ymo", "yno", "ypo", "yquo", "yro", "yso", "yto", "yvo", "ywo", "yxo", "yyo", "yzo",
							"ybu", "ycu", "ydu", "yfu","ygu", "yhu", "yju", "yku", "ylu", "ymu", "ynu", "ypu",  "yru", "ysu", "ytu", "yvu", "ywu", "yxu", "yyu", "yzu", };
const char* LastSyllables[] = { "ba", "be", "bi", "bo", "bu", "by",
							"ca", "ce", "ci", "co", "cu", "cy",
							"da", "de", "di", "do", "du", "dy",
							"fa", "fe", "fi", "fo", "fu", "fy",
							"ga", "ge", "gi", "go", "gu", "gy",
							"ha", "he", "hi", "ho", "hu", "hy",
							"ja", "je", "ji", "jo", "ju", "jy",
							"ka", "ke", "ki", "ko", "ku", "ky",
							"la", "le", "li", "lo", "lu", "ly",
							"ma", "me", "mi", "mo", "mu", "my",
							"na", "ne", "ni", "no", "nu", "ny",
							"pa", "pe", "pi", "po", "pu", "py",
							"qua", "que", "qui", "quo", "qu", "quy",
							"va", "ve", "vi", "vo", "vu", "vy",
							"wa", "we", "wi", "wo", "wu", "wy",
							"za", "ze", "zi", "zo", "zu", "zy", };

FName UUtilityStatics::MakeName(int seed)
{
	int first = sizeof(FirstSyllables) / sizeof(char*);
	int middle = sizeof(MiddleSyllables) / sizeof(char*);
	int last = sizeof(LastSyllables) / sizeof(char*);
	FRandomStream stream(seed);

	FString name = FirstSyllables[stream.RandRange(0, first - 1)];
	name += MiddleSyllables[stream.RandRange(0, middle - 1)];
	name += LastSyllables[stream.RandRange(0, last - 1)];
	return FName(name);
}

FVector2D UUtilityStatics::GetViewportSize()
{
	return FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
}

FVector2D UUtilityStatics::GetViewportCenter()
{
	//Viewport Size
	const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());

	//Viewport Center!			
	return FVector2D(ViewportSize.X/2, ViewportSize.Y/2);
}

float UUtilityStatics::NormalizeValue(float value, float min, float max)
{
	if(max == min)
	{
		return 0;
	}
	return FMath::Clamp((value - min) / (max - min), 0, 1);
}

float UUtilityStatics::ComputeAOA(FVector forward, const FVector& Wind, const FVector& axis)
{
	float f = (acos(forward.Cross(Wind).Dot(axis)) >= 0) ? 1 : -1;
	return acos(forward.Dot(Wind)) * f;
}

TArray<FString> UUtilityStatics::GetAllSaveGameSlotNames()
{
	TArray<FString> Saves;
	ISaveGameSystem* SaveSystem = IPlatformFeaturesModule::Get().GetSaveGameSystem();
	if(SaveSystem)
	{
		SaveSystem->GetSaveGameNames(Saves, 0);
	}
	return Saves;
}

double UUtilityStatics::Distance(AActor* source, AActor* other)
{
	if(ensure(source) && ensure(other))
	{
		return FVector::Distance(source->GetActorLocation(), other->GetActorLocation());
	}
	return 0;
}

FVector UUtilityStatics::ComputeTorqueFromForce(FVector force, FVector location, FRotator orientation)
{
	return orientation.RotateVector(location.Cross(force));
}

float UUtilityStatics::MoveTowardTargetValue(float current, float target, float rate, float delta, float min, float max)
{
	if(current < target)
	{
		return FMath::Clamp(current + rate * delta, min, target);
	}
	else if(current > target)
	{
		return FMath::Clamp(current - rate * delta, target, max);
	}
	return current;
}

int UUtilityStatics::MakeIndex2D(int x, int y, int sliceSize)
{
	return x * sliceSize + y;
}

FVector2d UUtilityStatics::ToIndex2D(int index, int sliceSize)
{
	FVector2d out;
	out.X = index / sliceSize;
	out.Y = index % sliceSize;
	return out;
}

int UUtilityStatics::MakeIndex3D(int x, int y, int z, FVector sliceSize)
{
	return x * sliceSize.X + y * sliceSize.Y + z;
}

FVector UUtilityStatics::ToIndex3D(int index, FVector sliceSize)
{
	return FVector::Zero();
}

UObject * UUtilityStatics::GetDefaultObject(TSubclassOf<UObject> ObjectClass)
{
	if (ObjectClass)
		return ObjectClass->GetDefaultObject();
	return nullptr;
}

FVector UUtilityStatics::ComputeImpactForce(AActor* Me, AActor* Them)
{
	FVector Result;
	FVector Velocity1 = Me->GetVelocity();
	const UPrimitiveComponent * MyRoot = Cast<UPrimitiveComponent>(Me->GetRootComponent());
	if(MyRoot && MyRoot->IsSimulatingPhysics())
	{
		Velocity1 *= static_cast<double>(MyRoot->GetMass());
	}
	FVector Velocity2 = Them->GetVelocity();
	const UPrimitiveComponent * TheirRoot = Cast<UPrimitiveComponent>(Them->GetRootComponent());
	if(TheirRoot && TheirRoot->IsSimulatingPhysics())
	{
		Velocity2 *= static_cast<double>(TheirRoot->GetMass());
	}
	if(Velocity1.Dot(Velocity2) < 0)
	{
		Result = Velocity1 + Velocity2;
	}
	else
	{
		Result = Velocity1 - Velocity2;
	}
	return Result;
}

APawn* UUtilityStatics::GetLocalPlayerPawn(const UObject * WorldContext)
{
	return UGameplayStatics::GetPlayerPawn(WorldContext, 0);
}

float UUtilityStatics::GetHighestFloat(TArray<float> Array)
{
	ensure(Array.Num() > 0);
	float Highest = Array[0];
	for(float Value : Array)
	{
		if(Value > Highest)
		{
			Highest = Value;
		}
	}
	return Highest;
}

float UUtilityStatics::Roll(float Sides)
{
	return FMath::RandRange(0.0f, Sides);
}

bool UUtilityStatics::RollChance(float Sides, float Chance)
{
	return FMath::RandRange(0.0f,Sides) <= FMath::Clamp(Chance,0.0f,Sides);
}

bool UUtilityStatics::Roll100(float Chance)
{
	return FMath::RandRange(0,100) <= FMath::Clamp(Chance,0.0f,100.0f);
}

bool UUtilityStatics::Roll1000(float Chance)
{
	return FMath::RandRange(0,1000) <= FMath::Clamp(Chance,0.0f,1000.0f);
}

bool UUtilityStatics::IsHit(float Accuracy, float EvadeChance, float BlockChance, bool& IsBlocked, bool& IsEvaded)
{
	if(FMath::RandRange(0.0f, EvadeChance + Accuracy) < EvadeChance)
	{
		IsEvaded = true;
		return false;
	}
	if(FMath::RandRange(0.0f, BlockChance + Accuracy) < BlockChance)
	{
		IsBlocked = true;
		return false;
	}
	return FMath::RandRange(0.0f, Accuracy) < Accuracy;
}

void UUtilityStatics::ShowMouse(const UObject* WorldContext)
{
	APlayerController * Controller = GetLocalPlayerPawn(WorldContext)->GetController<APlayerController>();
	if(ensure(Controller))
	{
		Controller->bShowMouseCursor = true;
		Controller->DefaultMouseCursor = EMouseCursor::Default;
		FInputModeGameAndUI InputModeData;
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		InputModeData.SetHideCursorDuringCapture(false);
		Controller->SetInputMode(InputModeData);
	}
}

void UUtilityStatics::HideMouse(const UObject* WorldContext)
{
	APlayerController * Controller = GetLocalPlayerPawn(WorldContext)->GetController<APlayerController>();
	if(ensure(Controller))
	{
		Controller->bShowMouseCursor = false;
		Controller->SetInputMode(FInputModeGameOnly());
	}
}

float UUtilityStatics::ScaleAxisTo01(double Value)
{
	return (Value + 1) / 2;
}

LogStart::LogStart(LogSeverity severity, bool display)
{
	Severity = severity;
	Message = TEXT("");
	Display = display;
}

LogStart& LogStart::operator<<(const TCHAR* str)
{
	Message.Append(str);
	return *this;
}

LogStart& LogStart::operator<<(FString& str)
{
	Message.Append(str);
	return *this;
}

LogStart& LogStart::operator<<(const FName& name)
{
	Message.Append(name.ToString());
	return *this;
}


LogStart& LogStart::operator<<(const int& value)
{
	Message.Append(FString::Printf(TEXT("%d"),value));
	return *this;
}

LogStart& LogStart::operator<<(const float& value)
{
	Message.Append(FString::Printf(TEXT("%f"),value));
	return *this;
}

LogStart& LogStart::operator<<(const double& value)
{
	Message.Append(FString::Printf(TEXT("%f"),value));
	return *this;
}

LogStart& LogStart::operator<<(const FVector& value)
{
	Message.Append(FString::Printf(TEXT("[x = %f,y = %f,z=%f]"),value.X,value.Y,value.Z));
	return *this;
}

LogStart& LogStart::operator<<(const FRotator& value)
{
	Message.Append(FString::Printf(TEXT("[Pitch = %f,Yaw = %f,Roll=%f]"),value.Pitch,value.Yaw,value.Roll));
	return *this;
}

LogStart& LogStart::operator<<(LogStop stop)
{
	switch(Severity)
	{
	case LogSeverity::Information :
		{
			if(Display)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::White, Message);
			}
			UE_LOG(LogTemp,  Display, TEXT("%s"), *Message);
			break;
		}
	case LogSeverity::Warning :
		{
			if(Display)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, Message);
			}
			UE_LOG(LogTemp,  Warning, TEXT("%s"), *Message);
			break;
		}
	case LogSeverity::Error :
		{
			if(Display)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, Message);
			}
			UE_LOG(LogTemp,  Error, TEXT("%s"), *Message);
			break;
		}
	}
	return *this;
}