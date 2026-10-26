// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BHBaseAiChar.generated.h"

class UBasePlayerAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class BOSSHUNTERS_API ABHBaseAiChar : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
public:
	// Sets default values for this character's properties
	ABHBaseAiChar();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAbilitySystemComponent* AbilitySystemComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBasePlayerAttributeSet* AttributeSet;
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
