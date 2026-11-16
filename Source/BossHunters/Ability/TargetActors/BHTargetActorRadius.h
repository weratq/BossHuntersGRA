// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor_Radius.h"
#include "BHTargetActorRadius.generated.h"

UCLASS()
class BOSSHUNTERS_API ABHTargetActorRadius : public AGameplayAbilityTargetActor_Radius
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABHTargetActorRadius();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void ConfirmTargetingAndContinue() override;
	
};
