// Fill out your copyright notice in the Description page of Project Settings.


#include "BHPlayerCharacterBase.h"

#include "PlayerStateBase.h"


UAbilitySystemComponent* ABHPlayerCharacterBase::GetAbilitySystemComponent() const
{
	APlayerStateBase* PlayerStateBase = Cast<APlayerStateBase>(GetPlayerState());
	if (IsValid(PlayerStateBase))
	{
		return PlayerStateBase->AbilitySystemComponent;
	}
	return nullptr;
}

// Sets default values
ABHPlayerCharacterBase::ABHPlayerCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABHPlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABHPlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABHPlayerCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABHPlayerCharacterBase::GrantAllAbilities()
{
	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	
	if (!ASC)
	{
		return;
	}
	
	for (TSubclassOf<UGameplayAbility> Ability : Abilities)
	{
		if (Ability->IsValidLowLevel())
		{
			ASC->K2_GiveAbility(Ability, 1, INDEX_NONE);
		}
	}
}

void ABHPlayerCharacterBase::OnPlayerStateChanged(APlayerState* NewPlayerState, APlayerState* OldPlayerState)
{
	Super::OnPlayerStateChanged(NewPlayerState, OldPlayerState);
	if (GetLocalRole() == ROLE_Authority)
	{
		GrantAllAbilities();
	}
	else if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		OnASCReadyOnOwningClient();
	}
	
}

void ABHPlayerCharacterBase::OnASCReadyOnOwningClient_Implementation()
{
	
}

