// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListView.h"
#include "InventoryItemWidget.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class PSYONIC_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* EntriesVerticalBox;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UInventoryItemWidget> EntryClass;

	/*
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	UListView* InventoryList;
	*/
};
