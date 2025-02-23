// (c) Copyright 2024 Hollow World Games llc All Rights Reserved
#include <Attributes/AttributeTags.h>

//Race Class Profession Skill etc
UE_DEFINE_GAMEPLAY_TAG_COMMENT(RaceTag,"Character.Race","Race");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ClassTag,"Character.Class","Class");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ProfessionTag,"Character.Profession","Profession");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(SkillTag,"Character.Skill","Skill");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GenderTag,"Character.Gender","Gender");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaleTag,"Character.Gender.Male","Male");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FemaleTag,"Character.Gender.Female","Female");
// Level/ Experience
UE_DEFINE_GAMEPLAY_TAG_COMMENT(LevelTag,"Primary.Attribute.Level","Level");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ExperienceTag,"Primary.Attribute.Experience","Experience");
//Vitals
UE_DEFINE_GAMEPLAY_TAG_COMMENT(HealthTag,"Vital.Attribute.Health","Health");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxHealthTag,"Vital.Attribute.HealthMax","HealthMax");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxHealthAddendTag,"Vital.Attribute.HealthMax.Addend","HealthMax Addend");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxHealthMultiplierTag,"Vital.Attribute.HealthMax.Multiplier","HealthMax Multiplier");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EnergyTag,"Vital.Attribute.Energy","Energy");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxEnergyTag,"Vital.Attribute.EnergyMax","Energy Max");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxEnergyAddendTag,"Vital.Attribute.EnergyMax.Addend","Energy Max Addend");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxEnergyMultiplierTag,"Vital.Attribute.EnergyMax.Multiplier","Energy Max Multiplier");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ManaTag,"Vital.Attribute.Mana","Mana");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxManaTag,"Vital.Attribute.ManaMax","Mana Max");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxManaAddendTag,"Vital.Attribute.ManaMax.Addend","ManaMax Addend");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxManaMultiplierTag,"Vital.Attribute.ManaMax.Multiplier","ManaMax Multiplier");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingDamageTag, "Vital.Combat.IncomingDamage", "Incoming Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingHealingTag, "Vital.Combat.IncomingDamage", "Incoming Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(HealthRegenTag, "Vital.Regen.Health", "Health Regen");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EnergyRegenTag, "Vital.Regen.Energy", "Energy Regen");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ManaRegenTag, "Vital.Regen.Mana", "Mana Regen");
//Primary
UE_DEFINE_GAMEPLAY_TAG_COMMENT(StrengthTag, "Primary.Attribute.Strength", "Strength");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(StrengthAddendTag, "Primary.Attribute.Strength.Addend", "Strength Addend");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(StrengthMultiplierTag, "Primary.Attribute.Strength.Multiplier", "Strength Multiplier");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(AgilityTag,"Primary.Attribute.Agility","Agility");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(AgilityAddendTag,"Primary.Attribute.Agility.Addend","Agility Addend");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(AgilityMultiplierTag,"Primary.Attribute.Agility.Multiplier","Agility Multiplier");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PrecisionTag,"Primary.Attribute.Precision","Precision");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PrecisionAddendTag,"Primary.Attribute.Precision.Addend","Precision Addend");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PrecisionMultiplierTag,"Primary.Attribute.Precision.Multiplier","Precision Multiplier");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IntelligenceTag,"Primary.Attribute.Intelligence","Intelligence");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IntelligenceAddendTag,"Primary.Attribute.Intelligence.Addend","Intelligence Addend");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IntelligenceMultiplierTag,"Primary.Attribute.Intelligence.Multiplier","Intelligence Multiplier");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WisdomTag,"Primary.Attribute.Wisdom","Wisdom");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WisdomAddendTag,"Primary.Attribute.Wisdom.Addend","Wisdom Addend"); 
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WisdomMultiplierTag,"Primary.Attribute.Wisdom.Multiplier","Wisdom Multiplier"); 
UE_DEFINE_GAMEPLAY_TAG_COMMENT(LuckTag,"Primary.Attribute.Luck","Luck");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(LuckAddendTag,"Primary.Attribute.Luck.Addend","Luck Addend");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(LuckMultiplierTag,"Primary.Attribute.Luck.Multiplier","Luck Multiplier");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ConstitutionTag,"Primary.Attribute.Constitution","Constitution");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ConstitutionAddendTag,"Primary.Attribute.Constitution.Addend","Constitution Addend");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ConstitutionMultiplierTag,"Primary.Attribute.Constitution.Multiplier","Constitution Multiplier");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EnduranceTag,"Primary.Attribute.Endurance","Endurance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EnduranceAddendTag,"Primary.Attribute.Endurance.Addend","Endurance Addend");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EnduranceMultiplierTag,"Primary.Attribute.Endurance.Multiplier","Endurance Multiplier");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(CharismaTag,"Primary.Attribute.Charisma","Charisma");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(CharismaAddendTag,"Primary.Attribute.Charisma.Addend","Charisma Addend");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(CharismaMultiplierTag,"Primary.Attribute.Charisma.Multiplier","Charisma Multiplier");
//Damage
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MinDamageTag,"Combat.Parameters.Min", "Damage Minimum");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxDamageTag,"Combat.Parameters.Max", "Damage Maximum");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(DistanceTag,"Combat.Parameters.Distance", "Damage Distance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(DamageTypeTag,"Combat.DamageType", "Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MaxRangeTag,"Combat.Parameters.MaxRange","Max Range");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MinRangeTag,"Combat.Parameters.MinRange","Min Range");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(AbilityDamageBoostTag,"Ability.Damage.Boost", "Ability Damage Boost");
/*UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingDamage1Tag,"Combat.Damage.IncomingDamage1","Incoming Damage 1");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingDamage2Tag,"Combat.Damage.IncomingDamage2","Incoming Damage 2");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingDamage3Tag,"Combat.Damage.IncomingDamage3","Incoming Damage 3");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IncomingDamage4Tag,"Combat.Damage.IncomingDamage4","Incoming Damage 4");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(DamageBoost1Tag,"Combat.Damage.DamageBoost1","Damage Boost 1");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(DamageBoost2Tag,"Combat.Damage.DamageBoost2","Damage Boost 2");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(DamageBoost3Tag,"Combat.Damage.DamageBoost3","Damage Boost 3");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(DamageBoost4Tag,"Combat.Damage.DamageBoost4","Damage Boost 4");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Mitigation1Tag,"Combat.Damage.Mitigation1","Mitigation 1");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Mitigation2Tag,"Combat.Damage.Mitigation2","Mitigation 2");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Mitigation3Tag,"Combat.Damage.Mitigation3","Mitigation 3");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Mitigation4Tag,"Combat.Damage.Mitigation4","Mitigation 4");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Resistance1Tag,"Combat.Damage.Resistance1","Resistance 1");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Resistance2Tag,"Combat.Damage.Resistance1","Resistance 2");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Resistance3Tag,"Combat.Damage.Resistance1","Resistance 3");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Resistance4Tag,"Combat.Damage.Resistance1","Resistance 4");*/
//Combat
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ArmorTag,"Combat.Attribute.Armor","Armor");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PenetrationTag,"Combat.Attribute.Penetration","Penetration");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PenetrationValueTag,"Combat.Attribute.PenetrationValue","Penetration Value");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitChanceTag,"Combat.Attribute.HitChance","Hit Chance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(BlockChanceTag,"Combat.Attribute.BlockChance","Block Chance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(BlockValueTag,"Combat.Attribute.BlockValue","Block Value");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GlancingBlowChanceTag,"Combat.Attribute.GlancingBlowChance","Glancing Blow Chance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(GlancingBlowValueTag,"Combat.Attribute.GlancingBlowValue","Glancing Blow Value");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ParryChanceTag,"Combat.Attribute.ParryChance","Parry Chance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EvadeChanceTag,"Combat.Attribute.EvadeChance","Evade Chance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(CriticalChanceTag,"Combat.Attribute.CriticalChance","Critical Chance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(CriticalValueTag,"Combat.Attribute.CriticalValue","Critical Value");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(CriticalDefenseTag,"Combat.Attribute.CriticalDefense","Critical Defense");