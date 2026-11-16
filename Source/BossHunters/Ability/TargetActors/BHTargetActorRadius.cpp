// Fill out your copyright notice in the Description page of Project Settings.


#include "BHTargetActorRadius.h"


// Sets default values
ABHTargetActorRadius::ABHTargetActorRadius()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABHTargetActorRadius::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABHTargetActorRadius::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABHTargetActorRadius::ConfirmTargetingAndContinue()
{
	check(ShouldProduceTargetData());
	if (SourceActor)
	{
		FVector Origin = GetActorLocation();
		FGameplayAbilityTargetDataHandle Handle = MakeTargetData(PerformOverlap(Origin), Origin);
		TargetDataReadyDelegate.Broadcast(Handle);
	}
}

