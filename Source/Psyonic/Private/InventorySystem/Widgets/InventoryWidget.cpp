// Fill out your copyright notice in the Description page of Project Settings.

#include "InventorySystem/Widgets/InventoryWidget.h"
#include "InventorySystem/Structs/ItemDetails.h"

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	//TMap<FItemDetails, int32> Inventory;

	TSet<FItemDetails> Keys = TSet<FItemDetails>();
	/*
	Inventory.GetKeys(Keys);

	for (FItemDetails Item : Keys) {
		UInventoryItemWidget* Entry = CreateWidget<UInventoryItemWidget>(this, EntryClass);
		Entry->InitializeFromInventoryItem(Item);
	}
	//*/
}
