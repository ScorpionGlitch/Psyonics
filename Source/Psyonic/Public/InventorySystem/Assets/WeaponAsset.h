// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "../Structs/WeaponDetails.h"

#include "ItemAsset.h"

#include "WeaponAsset.generated.h"

UCLASS()
class PSYONIC_API UWeaponAsset : public UItemAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory|Weapon")
	FWeaponDetails WeaponDetails;

	/*
	FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Weapons", GetFName());
	}
	//*/
};