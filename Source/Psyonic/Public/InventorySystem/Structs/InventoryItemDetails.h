// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "../Assets/ItemAsset.h"

#include "InventoryItemDetails.generated.h"

USTRUCT(BlueprintType)
struct PSYONIC_API FInventoryItemDetails
{
	GENERATED_BODY()
	/*
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory", meta = (DisplayName = "Item Details"))
	UItemAsset* ItemAsset;
	//*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory", meta = (DisplayName = "Item Count"))
	int32 ItemCount = 0;
};