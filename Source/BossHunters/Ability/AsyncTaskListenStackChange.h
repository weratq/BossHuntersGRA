// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncTaskListenStackChange.generated.h"

class UAbilitySystemComponent;
/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameplayEffectStackChange, int, NewStackCount);

UCLASS()
class BOSSHUNTERS_API UAsyncTaskListenStackChange : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintCallable)
	static UAsyncTaskListenStackChange* ListenStackChange(UAbilitySystemComponent* OwnerASC, FActiveGameplayEffectHandle Handle);
	
	UPROPERTY(BlueprintAssignable)
	FGameplayEffectStackChange OnGameplayEffectStackChange;
	
	UFUNCTION()
	void OnStackChange(FActiveGameplayEffectHandle InHandle, int32 NewCount, int32 OldCount);
	
protected:
	UPROPERTY()
	UAbilitySystemComponent* ASC;
	
	FActiveGameplayEffectHandle EffectHandle;
};
