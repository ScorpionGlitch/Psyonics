// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WeaponDetails.generated.h"

USTRUCT(BlueprintType)
struct PSYONIC_API FWeaponDetails
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory|Weapon", meta = (DisplayName = "Weapon Damage"))
	int32 WeaponDamage = 0;
};