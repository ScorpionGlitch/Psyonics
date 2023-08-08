// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "..\Enums\InventoryCategory.h"

#include "ItemDetails.generated.h"

USTRUCT(BlueprintType)
struct PSYONIC_API FItemDetails
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory", meta = (DisplayName = "Item Name Singular"))
		FText ItemNameSingular;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory", meta = (DisplayName = "Item Name Plural"))
		FText ItemNamePlural;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory", meta = (DisplayName = "Item Description"))
		FText ItemDescription;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory", meta = (DisplayName = "Inventory Category"))
		EInventoryCategory InventoryCategory = EInventoryCategory::Weapon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory", meta = (DisplayName = "Item Icon"))
		UTexture2D* ItemIcon = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory", meta = (DisplayName = "Item Dropped Mesh"))
		UStaticMesh* ItemDroppedMesh = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory", meta = (DisplayName = "Item Value"))
		int32 ItemValue = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory", meta = (DisplayName = "ItemWeight"))
		float ItemWeight = 0.0f;
};