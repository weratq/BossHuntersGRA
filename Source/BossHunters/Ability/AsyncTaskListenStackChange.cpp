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
	
	return Result;
	
}

void UAsyncTaskListenStackChange::OnStackChange(FActiveGameplayEffectHandle InHandle, int32 NewCount, int32 OldCount)
{
	OnGameplayEffectStackChange.Broadcast(NewCount);
}
