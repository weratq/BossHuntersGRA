// Fill out your copyright notice in the Description page of Project Settings.


#include "BHPlayerControllerBase.h"

#include "PlayerStateBase.h"

UAbilitySystemComponent* ABHPlayerControllerBase::GetAbilitySystemComponent() const
{
	APlayerStateBase* PlayerStateBase = GetPlayerState<APlayerStateBase>();
	if (IsValid(PlayerStateBase))
	{
		return PlayerStateBase->AbilitySystemComponent;
	}
	return nullptr;
}

void ABHPlayerControllerBase::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	
	UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent();
	if (IsValid(AbilitySystemComponent))
	{
		AbilitySystemComponent->SetAvatarActor(aPawn);
		AbilitySystemComponent->RefreshAbilityActorInfo();
	}
}
