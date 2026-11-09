// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncTaskListenEffectsApplied.generated.h"

class UAbilitySystemComponent;
/**
 * 
 */


USTRUCT(BlueprintType)
struct FUIEffectListenData
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	FGameplayEffectSpec Spec;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UTexture2D> Texture;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTag Tag;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int StackCount;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Duration;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FActiveGameplayEffectHandle GameplayEffectHandle;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUIEffectAppliedDelegate, FUIEffectListenData, Data);

UCLASS()
class BOSSHUNTERS_API UAsyncTaskListenEffectsApplied : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	/*Icon
	 *Tag
	 *Name/Descr
	 * Stack Count
	 * Duration 
	 * 
	 * OnActiveGameplayEffectAddedDelegateToSelf
	 * UAbilitySystemComponent*, const FGameplayEffectSpec&, FActiveGameplayEffectHandle
	 */
	
	UFUNCTION(BlueprintCallable)
	static UAsyncTaskListenEffectsApplied* ListenApplyedEffects(UAbilitySystemComponent* FromASC);
	
	UFUNCTION()
	void OnEffectApply(UAbilitySystemComponent* SourceASC, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle);
	
	UPROPERTY(BlueprintAssignable)
	FUIEffectAppliedDelegate NewEffectAppliedDelegate;

	
private:
	
	UPROPERTY()
	UAbilitySystemComponent* ASC;
	
	
	
};
