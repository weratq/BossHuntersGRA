// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStateBase.h"
#include "Player/PlayerStateBase.h"

#include "AbilitySystemComponent.h"


APlayerStateBase::APlayerStateBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("ASC");
	
}
