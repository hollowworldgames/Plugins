// (c) Copyright 2024 Hollow World Games llc All Rights Reserved
#pragma once

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

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
const UAbilitySystemComponent * SourceComponent = ExecutionParams.GetSourceAbilitySystemComponent();\
	const UAbilitySystemComponent * TargetComponent = ExecutionParams.GetTargetAbilitySystemComponent();\
const CharacterClass * Source = Cast<CharacterClass>(SourceComponent->GetAvatarActor());\
const CharacterClass * Target = Cast<CharacterClass>(TargetComponent->GetAvatarActor());\
const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();\
FAggregatorEvaluateParameters EvaluateParameters;\
EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();\
EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

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

#define PROCESS_INCOMING_DAMAGE(IncomingAttributeName, HealthAttributeName, Data) \
if(Data.EvaluatedData.Attribute == Get##IncomingAttributeName##Attribute()) \
{\
float Damage = Get##IncomingAttributeName();\
Set##IncomingAttributeName(0);\
Set##HealthAttributeName(Get##HealthAttributeName() - Damage);\
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
