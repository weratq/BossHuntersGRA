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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGameplayEffectStackChange, int, NewStackCount, float, NewDuration);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameplayEffectRemove);

UCLASS()
class BOSSHUNTERS_API UAsyncTaskListenStackChange : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintCallable)
	static UAsyncTaskListenStackChange* ListenStackChange(UAbilitySystemComponent* OwnerASC, FActiveGameplayEffectHandle Handle);
	
	UPROPERTY(BlueprintAssignable)
	FGameplayEffectStackChange OnGameplayEffectStackChange;
	
	UPROPERTY(BlueprintAssignable)
	FGameplayEffectStackChange OnGameplayEffectTimeChange;
	
	UPROPERTY(BlueprintAssignable)
	FGameplayEffectRemove OnGameplayEffectRemove;
	
	UFUNCTION()
	void OnStackChange(FActiveGameplayEffectHandle InHandle, int32 NewCount, int32 OldCount);
	
	UFUNCTION()
	void OnTimeChange(FActiveGameplayEffectHandle InHandle, float NewStartTime, float NewDuration);
	
	UFUNCTION()
	void OnEffectRemove(const FGameplayEffectRemovalInfo& InInfo);
	
	
	
protected:
	UPROPERTY()
	UAbilitySystemComponent* ASC;
	
	int StackCount;
	
	FActiveGameplayEffectHandle EffectHandle;
};
