// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGASFunctionLibrary.h"
#include "GameplayEffect.h"

FGameplayTagContainer UMyGASFunctionLibrary::GetAbilityCooldownTag(TSubclassOf<UGameplayAbility> AbilityClass)
{
	if (!AbilityClass) return FGameplayTagContainer();

	if (const UGameplayAbility* DefaultAbility = AbilityClass->GetDefaultObject<UGameplayAbility>())
	{
		const FGameplayTagContainer* CooldownTags = DefaultAbility->GetCooldownTags();
		if (CooldownTags)
		{
		
			return *CooldownTags;
		}
	}
	return FGameplayTagContainer();
}
