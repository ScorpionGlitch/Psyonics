// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
//#include "../Structs/ItemDetails.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "InventoryItemWidget.generated.h"

/**
 *
 */
UCLASS()
class PSYONIC_API UInventoryItemWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
private:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* NameLabel;

	UPROPERTY(meta = (BindWidget))
	class UImage* IconImage;
};
