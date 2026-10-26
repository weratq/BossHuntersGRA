// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BasePlayerAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBHOnDeath, AActor*, SourceActor, AActor*, TargetActor);

/**
 * 
 */
UCLASS()
class BOSSHUNTERS_API UBasePlayerAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UBasePlayerAttributeSet();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** Broadcast on the server when Health reaches zero. */
	UPROPERTY(BlueprintAssignable, Category = "Death")
	FBHOnDeath OnDeath;

	UFUNCTION(BlueprintPure, Category = "Attributes")
	bool IsAlive() const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Resources")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Resources")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegen, Category = "Resources")
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, HealthRegen)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Resources")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, Mana)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Resources")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, MaxMana)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegen, Category = "Resources")
	FGameplayAttributeData ManaRegen;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, ManaRegen)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vitality, Category = "Core Attributes")
	FGameplayAttributeData Vitality;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, Vitality)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Core Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, Strength)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Agility, Category = "Core Attributes")
	FGameplayAttributeData Agility;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, Agility)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Core Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, Intelligence)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PhysicalDamageMin, Category = "Damage")
	FGameplayAttributeData PhysicalDamageMin;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, PhysicalDamageMin)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PhysicalDamageMax, Category = "Damage")
	FGameplayAttributeData PhysicalDamageMax;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, PhysicalDamageMax)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MagicalDamageMin, Category = "Damage")
	FGameplayAttributeData MagicalDamageMin;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, MagicalDamageMin)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MagicalDamageMax, Category = "Damage")
	FGameplayAttributeData MagicalDamageMax;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, MagicalDamageMax)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitChance, Category = "Damage")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, CriticalHitChance)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitDamage, Category = "Damage")
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, CriticalHitDamage)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Defense")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, Armor)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockDamage, Category = "Defense")
	FGameplayAttributeData BlockDamage;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, BlockDamage)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Defense")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, BlockChance)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DodgeChance, Category = "Defense")
	FGameplayAttributeData DodgeChance;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, DodgeChance)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ParryChance, Category = "Defense")
	FGameplayAttributeData ParryChance;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, ParryChance)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorAbsorption, Category = "Defense")
	FGameplayAttributeData ArmorAbsorption;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, ArmorAbsorption)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CastSpeed, Category = "Speed and Range")
	FGameplayAttributeData CastSpeed;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, CastSpeed)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AttackSpeed, Category = "Speed and Range")
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, AttackSpeed)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MovementSpeed, Category = "Speed and Range")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, MovementSpeed)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AttackRange, Category = "Speed and Range")
	FGameplayAttributeData AttackRange;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, AttackRange)

	/** Meta attribute: damage gameplay effects write here; applied to Health in PostGameplayEffectExecute. Not replicated. */
	UPROPERTY(BlueprintReadOnly, Category = "Meta")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UBasePlayerAttributeSet, Damage)

protected:
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_HealthRegen(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ManaRegen(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Vitality(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Agility(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_PhysicalDamageMin(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_PhysicalDamageMax(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MagicalDamageMin(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MagicalDamageMax(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_BlockDamage(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_DodgeChance(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ParryChance(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ArmorAbsorption(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_CastSpeed(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_AttackSpeed(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MovementSpeed(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_AttackRange(const FGameplayAttributeData& OldValue);
};
