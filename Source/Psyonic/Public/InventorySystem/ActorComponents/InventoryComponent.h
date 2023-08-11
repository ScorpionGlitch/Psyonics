// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Structs/InventoryItemDetails.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PSYONIC_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
/*
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
	TArray<FInventoryItemDetails> Inventory;
//*/
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
};
