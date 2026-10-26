// Fill out your copyright notice in the Description page of Project Settings.


#include "BHBaseAiChar.h"

#include "AbilitySystemComponent.h"
#include "Ability/BasePlayerAttributeSet.h"


UAbilitySystemComponent* ABHBaseAiChar::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Sets default values
ABHBaseAiChar::ABHBaseAiChar()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UBasePlayerAttributeSet>("AttributeSet");
}

// Called when the game starts or when spawned
void ABHBaseAiChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABHBaseAiChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABHBaseAiChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

