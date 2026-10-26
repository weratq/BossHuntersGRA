// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BHPlayerCharacterBase.generated.h"

UCLASS()
class BOSSHUNTERS_API ABHPlayerCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

public:
	// Sets default values for this character's properties
	ABHPlayerCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
