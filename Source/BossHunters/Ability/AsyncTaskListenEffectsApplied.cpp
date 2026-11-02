// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncTaskListenEffectsApplied.h"

#include "AbilitySystemComponent.h"
#include "Components/BHUIEffectData.h"

UAsyncTaskListenEffectsApplied* UAsyncTaskListenEffectsApplied::ListenApplyedEffects(UAbilitySystemComponent* FromASC)
{
	UAsyncTaskListenEffectsApplied* Result = NewObject<UAsyncTaskListenEffectsApplied>();
	Result->ASC = FromASC;
	
	Result->ASC->OnActiveGameplayEffectAddedDelegateToSelf.AddUObject(Result,&UAsyncTaskListenEffectsApplied::OnEffectApply);
	
	return Result;
}

void UAsyncTaskListenEffectsApplied::OnEffectApply(UAbilitySystemComponent* SourceASC,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	const UBHUIEffectData* BHUIEffectData = EffectSpec.Def->FindComponent<UBHUIEffectData>();
	if (IsValid(BHUIEffectData))
	{
		FUIEffectListenData EffectListenData;
        EffectListenData.Spec = EffectSpec;
        EffectListenData.Tag = EffectSpec.Def->GetGrantedTags().First();
		EffectListenData.Duration = EffectSpec.GetDuration();
		EffectListenData.StackCount = EffectSpec.GetStackCount();
		EffectListenData.Texture = BHUIEffectData->Icon;
		NewEffectAppliedDelegate.Broadcast(EffectListenData);
	}
}


