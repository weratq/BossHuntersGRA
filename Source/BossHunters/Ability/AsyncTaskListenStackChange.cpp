// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncTaskListenStackChange.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"

UAsyncTaskListenStackChange* UAsyncTaskListenStackChange::ListenStackChange(UAbilitySystemComponent* OwnerASC,
                                                                            FActiveGameplayEffectHandle Handle)
{
	UAsyncTaskListenStackChange* Result = NewObject<UAsyncTaskListenStackChange>();
	
	Result->ASC = OwnerASC;
	Result->EffectHandle = Handle;
	
	FOnActiveGameplayEffectStackChange* DelPtr = Result->ASC->OnGameplayEffectStackChangeDelegate(Handle);
	if (DelPtr)
	{
		DelPtr->AddUObject(Result, &UAsyncTaskListenStackChange::OnStackChange);
	}
	
	FOnActiveGameplayEffectRemoved_Info* RemPtr = Result->ASC->OnGameplayEffectRemoved_InfoDelegate(Handle);
	if (RemPtr)
	{
		RemPtr->AddUObject(Result, &UAsyncTaskListenStackChange::OnEffectRemove);
	}
	
	FOnActiveGameplayEffectTimeChange* TimeChangePtr = Result->ASC->OnGameplayEffectTimeChangeDelegate(Handle);
	if (TimeChangePtr)
	{
		TimeChangePtr->AddUObject(Result, &UAsyncTaskListenStackChange::OnTimeChange);
	}
	
	return Result;
	
}

void UAsyncTaskListenStackChange::OnStackChange(FActiveGameplayEffectHandle InHandle, int32 NewCount, int32 OldCount)
{
	StackCount = NewCount;
	OnGameplayEffectStackChange.Broadcast(NewCount, -1.f);
}

void UAsyncTaskListenStackChange::OnTimeChange(FActiveGameplayEffectHandle InHandle, float NewStartTime,
	float NewDuration)
{
	OnGameplayEffectTimeChange.Broadcast(StackCount ,NewDuration);
}

void UAsyncTaskListenStackChange::OnEffectRemove(const FGameplayEffectRemovalInfo& InInfo)
{
	OnGameplayEffectRemove.Broadcast();
	SetReadyToDestroy();
}
