// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStateBase.h"
#include "AbilitySystemComponent.h"
#include "Ability/BasePlayerAttributeSet.h"


APlayerStateBase::APlayerStateBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("ASC");
	
	BasePlayerAttributeSet = CreateDefaultSubobject<UBasePlayerAttributeSet>("BasePlayerAttributeSet");
	
}

void APlayerStateBase::OnRep_PlayerName()
{
	Super::OnRep_PlayerName();
	OnPlayerNameDelegate.Broadcast();
}

void APlayerStateBase::SetNickName(FString NickName)
{
	SetPlayerName(NickName);
}

