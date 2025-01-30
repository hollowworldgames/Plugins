// (c) Copyright 2024 Hollow World Games llc All Rights Reserved
#pragma once

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

#define ATTRIBUTE_TAG_ACCESSOR(ClassName, PropertyName) \
	FGameplayTag Get##PropertyName##Tag() const { return PropertyName##Tag; }

#define DECLARE_ATTRIBUTE(AttributeName, CategoryName)\
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_##AttributeName, Category=CategoryName)\
FGameplayAttributeData AttributeName;\
UFUNCTION()\
void OnRep_##AttributeName(const FGameplayAttributeData& Old##AttributeName) const;


#define ATTRIBUTE_IMPLEMENT(ClassName, AttributeName)\
void ClassName::OnRep_##AttributeName(const FGameplayAttributeData& Old##AttributeName) const\
{\
GAMEPLAYATTRIBUTE_REPNOTIFY(ClassName, AttributeName, Old##AttributeName);\
}\

#define CAP_ATTRIBUTE(AttributeName, CapWith, Data) \
if(Data.EvaluatedData.Attribute == Get##AttributeName##Attribute()) \
{\
Set##AttributeName(FMath::Clamp(Get##AttributeName(), 0.f, Get##CapWith()));\
}

#define CAP_ATTRIBUTE_MaxValue(AttributeName, MaxValue, Data) \
if(Data.EvaluatedData.Attribute == Get##AttributeName##Attribute()) \
{\
Set##AttributeName(FMath::Clamp(Get##AttributeName(), 0.f, MaxValue));\
}

#define INITIALIZE_EXECUTION_CALC(CharacterClass, ExecutionParams) \
const UGameplayAbilitySystemComponent * SourceComponent = Cast<UGameplayAbilitySystemComponent>(ExecutionParams.GetSourceAbilitySystemComponent());\
const UGameplayAbilitySystemComponent * TargetComponent = Cast<UGameplayAbilitySystemComponent>(ExecutionParams.GetTargetAbilitySystemComponent());\
const CharacterClass * Source = Cast<CharacterClass>(SourceComponent->GetAvatarActor());\
const CharacterClass * Target = Cast<CharacterClass>(TargetComponent->GetAvatarActor());\
const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();\
FAggregatorEvaluateParameters EvaluateParameters;\
EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();\
EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

#define INITIALIZE_EXECUTION_CALC2(SourceClass, TargetClass, ExecutionParams) \
const UGameplayAbilitySystemComponent * SourceComponent = Cast<UGameplayAbilitySystemComponent>(ExecutionParams.GetSourceAbilitySystemComponent());\
const UGameplayAbilitySystemComponent * TargetComponent = Cast<UGameplayAbilitySystemComponent>(ExecutionParams.GetTargetAbilitySystemComponent());\
const SourceClass * Source = Cast<SourceClass>(SourceComponent->GetAvatarActor());\
const TargetClass * Target = Cast<TargetClass>(TargetComponent->GetAvatarActor());\
const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();\
FAggregatorEvaluateParameters EvaluateParameters;\
EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();\
EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

#define GET_EXECUTION_SOURCE_OWNER(SourceClass) \
const SourceClass * SourceOwner = Cast<SourceClass>(SourceComponent->GetOwnerActor());

#define GET_EXECUTION_TARGET_OWNER(TargetClass) \
const TargetClass * TargetOwner = Cast<TargetClass>(TargetComponent->GetOwnerActor());

#define GET_EXECUTION_OWNERS(SourceClass , TargetClass) \
const SourceClass * SourceOwner = Cast<SourceClass>(SourceComponent->GetOwnerActor());\
const TargetClass * TargetOwner = Cast<TargetClass>(TargetComponent->GetOwnerActor());

#define GET_EXECUTION_ATTRIBUTE(Attribute, ExecutionParams) \
float Attribute = 0; \
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Attribute##Def, EvaluateParameters, Attribute );

#define WRITE_EXECUTION_ATTRIBUTE(PropertyClass, Property, OutParams)\
OutParams.AddOutputModifier(FGameplayModifierEvaluatedData(PropertyClass::Get##Property##Attribute(), EGameplayModOp::Override, Property));

#define WRITE_EXECUTION_ATTRIBUTE_LOCAL(PropertyClass, Property, OutParams, Local)\
OutParams.AddOutputModifier(FGameplayModifierEvaluatedData(PropertyClass::Get##Property##Attribute(), EGameplayModOp::Override, Local));

#define DECLARE_ATTRIBUTE_CAPTUREDEF2(P) \
FGameplayEffectAttributeCaptureDefinition P##Def; 

#define DEFINE_ATTRIBUTE_CAPTUREDEF2(PropertyClass, Property, Source, Snapshot, AddToRelevant) \
{ \
	Property##Def = FGameplayEffectAttributeCaptureDefinition(PropertyClass::Get##Property##Attribute(), EGameplayEffectAttributeCaptureSource::Source, Snapshot); \
	if(AddToRelevant) RelevantAttributesToCapture.Add(Property##Def);\
}

#define ProcessIncomingDamage(IncomingAttributeName, HealthAttributeName, Data) \
	if(Data.EvaluatedData.Attribute == Get##IncomingAttributeName##Attribute()) \
	{\
		float Damage = Get##IncomingAttributeName();\
		Set##IncomingAttributeName(0);\
		Set##HealthAttributeName(Get##HealthAttributeName() - Damage);\
	}

#define ProcessIncomingHealing(IncomingAttributeName, HealthAttributeName, Data) \
if(Data.EvaluatedData.Attribute == Get##IncomingAttributeName##Attribute()) \
{\
float Damage = Get##IncomingAttributeName();\
Set##IncomingAttributeName(0);\
Set##HealthAttributeName(Get##HealthAttributeName() + Damage);\
}

#define PROCESS_INCOMING_HEALING(IncomingAttributeName, HealthAttributeName, Data) \
if(Data.EvaluatedData.Attribute == Get##IncomingAttributeName##Attribute()) \
{\
float Damage = Get##IncomingAttributeName();\
Set##IncomingAttributeName(0);\
Set##HealthAttributeName(Get##HealthAttributeName() + Damage);\
}

#define PROCESS_INCOMING_EXPERIENCE(IncomingExperience, Experience, LevelFromExperience, Level, OnLevelChanged, Data)\
if(Data.EvaluatedData.Attribute == Get##IncomingExperience##Attribute())\
	{\
		Set##Experience(Get##Experience() + Get##IncomingExperience());\
		Set##IncomingExperience(0);\
		float NewLevel = LevelFromExperience.GetValueAtLevel(Get##Experience());\
		if(NewLevel > Get##Level())\
		{\
			Set##Level(NewLevel);\
			OnLevelChanged.Broadcast(NewLevel);\
		}\
	}

#define PROCESS_INCOMING_EXPERIENCE_NOTIFY_ONLY(IncomingExperience, Experience, LevelFromExperience, Level, OnLevelChanged, Data)\
if(Data.EvaluatedData.Attribute == Get##IncomingExperience##Attribute())\
{\
Set##Experience(Get##Experience() + Get##IncomingExperience());\
Set##IncomingExperience(0);\
float NewLevel = LevelFromExperience.GetValueAtLevel(GetExperience());\
if(NewLevel > Level)\
{\
	Level = NewLevel;\
OnLevelChanged.Broadcast(NewLevel);\
}\
}

#define PROCESS_INCOMING_DAMAGE_NO_NOTIFY(IncomingAttributeName, HealthAttributeName, Data) \
if(Data.EvaluatedData.Attribute == Get##IncomingAttributeName##Attribute()) \
{\
float PreviousHealth = Get##HealthAttributeName();\
float Damage = Get##IncomingAttributeName();\
Set##IncomingAttributeName(0);\
Set##HealthAttributeName(Get##HealthAttributeName() - Damage);}

#define PROCESS_INCOMING_DAMAGE(IncomingAttributeName, HealthAttributeName, Data, OnDead) \
if(Data.EvaluatedData.Attribute == Get##IncomingAttributeName##Attribute()) \
{\
float PreviousHealth = Get##HealthAttributeName();\
float Damage = Get##IncomingAttributeName();\
Set##IncomingAttributeName(0);\
Set##HealthAttributeName(Get##HealthAttributeName() - Damage);\
if(PreviousHealth > 0 && Get##HealthAttributeName() <= 0) { OnDead.Broadcast(); }\
}

#define PROCESS_INCOMING_COMPONENT_DAMAGE(IncomingAttributeName, HealthAttributeName, Data, Component, OnDead) \
if(Data.EvaluatedData.Attribute == Get##IncomingAttributeName##Attribute()) \
{\
float PreviousHealth = Get##HealthAttributeName();\
float Damage = Get##IncomingAttributeName();\
Set##IncomingAttributeName(0);\
Set##HealthAttributeName(Get##HealthAttributeName() - Damage);\
if(PreviousHealth > 0 && Get##HealthAttributeName() <= 0) { OnDead.Broadcast(Component); }\
}

#define PROCESS_INCOMING_DAMAGE_NOTIFY(IncomingAttributeName, HealthAttributeName, Data, Notify) \
if(Data.EvaluatedData.Attribute == Get##IncomingAttributeName##Attribute()) \
{\
float Damage = Get##IncomingAttributeName();\
Set##IncomingAttributeName(0);\
Set##HealthAttributeName(Get##HealthAttributeName() - Damage);\
if(Get##HealthAttributeName() == 0) \
{\
Notify.Broadcast(IncomingAttributeName);\
}\
}

