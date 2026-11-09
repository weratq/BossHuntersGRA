// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BHItemData.generated.h"

class UTexture2D;
class UStaticMesh;
class UGameplayAbility;
class UGameplayEffect;

UENUM(BlueprintType)
enum class EBHEquipmentSlot : uint8
{
	None,
	Head,
	Chest,
	Hands,
	Legs,
	Feet,
	MainHand,
	OffHand
};

UCLASS()
class BOSSHUNTERS_API UBHItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Display")
	FText ItemName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Display")
	TObjectPtr<UTexture2D> ItemIcon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Visual")
	TObjectPtr<UStaticMesh> Mesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Equipment")
	EBHEquipmentSlot EquipmentSlot = EBHEquipmentSlot::None;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Equipment")
	FTransform Offset = FTransform::Identity;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Abilities")
	TSubclassOf<UGameplayAbility> GrantedAbility;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Abilities")
	TSubclassOf<UGameplayEffect> EquipmentEffect;
};