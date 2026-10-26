// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerController.h"
#include "BHPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class BOSSHUNTERS_API ABHPlayerControllerBase : public APlayerController, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void OnPossess(APawn* aPawn) override;
};
