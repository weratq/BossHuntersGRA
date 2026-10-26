// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/BasePlayerAttributeSet.h"
//#include "Ability/BHTags.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"
//#include "Player/BHPlayerController.h"

UBasePlayerAttributeSet::UBasePlayerAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitHealthRegen(1.f);
	InitMana(100.f);
	InitMaxMana(100.f);
	InitManaRegen(1.f);

	InitVitality(10.f);
	InitStrength(10.f);
	InitAgility(10.f);
	InitIntelligence(10.f);

	InitPhysicalDamageMin(10.f);
	InitPhysicalDamageMax(20.f);
	InitMagicalDamageMin(0.f);
	InitMagicalDamageMax(0.f);
	InitCriticalHitChance(0.05f);
	InitCriticalHitDamage(1.5f);

	InitArmor(0.f);
	InitBlockDamage(0.f);
	InitBlockChance(0.f);
	InitDodgeChance(0.f);
	InitParryChance(0.f);
	InitArmorAbsorption(0.f);

	InitCastSpeed(1.f);
	InitAttackSpeed(1.f);
	InitMovementSpeed(600.f);
	InitAttackRange(200.f);
}

void UBasePlayerAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetMaxHealthAttribute())
	{
		NewValue = FMath::Max(NewValue, 0.f);
	}
	else if (Attribute == GetMaxManaAttribute())
	{
		NewValue = FMath::Max(NewValue, 0.f);
	}
	else if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, FMath::Max(GetMaxHealth(), 0.f));
	}
	else if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, FMath::Max(GetMaxMana(), 0.f));
	}
	else if (Attribute == GetCriticalHitChanceAttribute()
		|| Attribute == GetBlockChanceAttribute()
		|| Attribute == GetDodgeChanceAttribute()
		|| Attribute == GetParryChanceAttribute()
		|| Attribute == GetArmorAbsorptionAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, 1.f);
	}
}

void UBasePlayerAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);

	// Lowering a maximum must also pull the current resource down with it.
	if (Attribute == GetMaxHealthAttribute() && GetHealth() > NewValue)
	{
		SetHealth(NewValue);
	}
	else if (Attribute == GetMaxManaAttribute() && GetMana() > NewValue)
	{
		SetMana(NewValue);
	}
}

void UBasePlayerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute != GetDamageAttribute())
	{
		return;
	}

	// Damage is a meta attribute: consume it and apply the result to Health.
	const float LocalDamage = FMath::Max(GetDamage(), 0.f);
	SetDamage(0.f);

	const float OldHealth = GetHealth();
	if (LocalDamage <= 0.f || OldHealth <= 0.f)
	{
		return;
	}

	SetHealth(FMath::Clamp(OldHealth - LocalDamage, 0.f, GetMaxHealth()));

	const FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* SourceASC = Context.GetOriginalInstigatorAbilitySystemComponent();
	AActor* SourceActor = Context.GetEffectCauser();
	AController* SourceController = nullptr;
/*
	if (SourceASC)
	{
		if (!SourceActor)
		{
			SourceActor = SourceASC->GetAvatarActor();
		}
		if (SourceASC->AbilityActorInfo.IsValid())
		{
			SourceController = SourceASC->AbilityActorInfo->PlayerController.Get();
		}
		if (!SourceController)
		{
			if (APawn* SourcePawn = Cast<APawn>(SourceActor))
			{
				SourceController = SourcePawn->GetController();
			}
		}
	}
/*
	AActor* TargetActor = Data.Target.GetAvatarActor();
	if (ABHPlayerController* PlayerController = Cast<ABHPlayerController>(SourceController))
	{
		FGameplayTagContainer AssetTags;
		Data.EffectSpec.GetAllAssetTags(AssetTags);
		PlayerController->ClientShowDamageNumber(LocalDamage, TargetActor, AssetTags.HasTagExact(BHTags::Damage_Critical), true);
	}

	if (GetHealth() <= 0.f)
	{
		OnDeath.Broadcast(SourceActor, TargetActor);
	}
*/	
}

bool UBasePlayerAttributeSet::IsAlive() const
{
	return GetHealth() > 0.f;
}

void UBasePlayerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, HealthRegen, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, ManaRegen, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, Vitality, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, Agility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, PhysicalDamageMin, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, PhysicalDamageMax, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, MagicalDamageMin, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, MagicalDamageMax, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, CriticalHitChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, CriticalHitDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, BlockDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, BlockChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, DodgeChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, ParryChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, ArmorAbsorption, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, CastSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBasePlayerAttributeSet, AttackRange, COND_None, REPNOTIFY_Always);
}

void UBasePlayerAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, Health, OldValue);
}

void UBasePlayerAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, MaxHealth, OldValue);
}

void UBasePlayerAttributeSet::OnRep_HealthRegen(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, HealthRegen, OldValue);
}

void UBasePlayerAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, Mana, OldValue);
}

void UBasePlayerAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, MaxMana, OldValue);
}

void UBasePlayerAttributeSet::OnRep_ManaRegen(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, ManaRegen, OldValue);
}

void UBasePlayerAttributeSet::OnRep_Vitality(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, Vitality, OldValue);
}

void UBasePlayerAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, Strength, OldValue);
}

void UBasePlayerAttributeSet::OnRep_Agility(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, Agility, OldValue);
}

void UBasePlayerAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, Intelligence, OldValue);
}

void UBasePlayerAttributeSet::OnRep_PhysicalDamageMin(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, PhysicalDamageMin, OldValue);
}

void UBasePlayerAttributeSet::OnRep_PhysicalDamageMax(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, PhysicalDamageMax, OldValue);
}

void UBasePlayerAttributeSet::OnRep_MagicalDamageMin(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, MagicalDamageMin, OldValue);
}

void UBasePlayerAttributeSet::OnRep_MagicalDamageMax(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, MagicalDamageMax, OldValue);
}

void UBasePlayerAttributeSet::OnRep_CriticalHitChance(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, CriticalHitChance, OldValue);
}

void UBasePlayerAttributeSet::OnRep_CriticalHitDamage(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, CriticalHitDamage, OldValue);
}

void UBasePlayerAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, Armor, OldValue);
}

void UBasePlayerAttributeSet::OnRep_BlockDamage(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, BlockDamage, OldValue);
}

void UBasePlayerAttributeSet::OnRep_BlockChance(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, BlockChance, OldValue);
}

void UBasePlayerAttributeSet::OnRep_DodgeChance(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, DodgeChance, OldValue);
}

void UBasePlayerAttributeSet::OnRep_ParryChance(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, ParryChance, OldValue);
}

void UBasePlayerAttributeSet::OnRep_ArmorAbsorption(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, ArmorAbsorption, OldValue);
}

void UBasePlayerAttributeSet::OnRep_CastSpeed(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, CastSpeed, OldValue);
}

void UBasePlayerAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, AttackSpeed, OldValue);
}

void UBasePlayerAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, MovementSpeed, OldValue);
}

void UBasePlayerAttributeSet::OnRep_AttackRange(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePlayerAttributeSet, AttackRange, OldValue);
}

