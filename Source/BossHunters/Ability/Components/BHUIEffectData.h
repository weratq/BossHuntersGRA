// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectComponent.h"
#include "UObject/SoftObjectPtr.h"

#include "BHUIEffectData.generated.h"

/**
 * 
 */
UCLASS()
class BOSSHUNTERS_API UBHUIEffectData : public UGameplayEffectComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TSoftObjectPtr<UTexture2D> Icon;
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	FText Name;
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	FText Description;
	
};
