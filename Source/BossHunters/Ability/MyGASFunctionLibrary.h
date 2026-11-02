// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "MyGASFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BOSSHUNTERS_API UMyGASFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	public:
	UFUNCTION(BlueprintPure, Category = "GAS|Abilities", meta = (DisplayName = "Get Ability Cooldown Tag", CompactNodeTitle = "GASAbilityCooldownTag"))
	static FGameplayTagContainer GetAbilityCooldownTag(TSubclassOf<UGameplayAbility> AbilityClass);
};
