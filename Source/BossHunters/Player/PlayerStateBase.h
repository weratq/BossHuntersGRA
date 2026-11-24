// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemComponent.h"
#include "PlayerStateBase.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerNameDelegate);
class UBasePlayerAttributeSet;
/**
 * 
 */
UCLASS()
class BOSSHUNTERS_API APlayerStateBase : public APlayerState
{
	GENERATED_BODY()
	
	APlayerStateBase();
	
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UAbilitySystemComponent* AbilitySystemComponent;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UBasePlayerAttributeSet* BasePlayerAttributeSet;
	
	UPROPERTY(BlueprintAssignable)
	FOnPlayerNameDelegate OnPlayerNameDelegate;
	virtual void OnRep_PlayerName() override;
	
	UFUNCTION(BlueprintCallable)
	void SetNickName(FString NickName);
};
