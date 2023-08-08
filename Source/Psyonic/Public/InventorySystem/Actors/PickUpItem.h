// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Assets/ItemAsset.h"
#include "PickUpItem.generated.h"

UCLASS()
class PSYONIC_API APickUpItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpItem();

	UPROPERTY(BlueprintReadWrite, meta = (DisplayName = "Item Details"))
	FItemDetails ItemDetails;

	UPROPERTY(BlueprintReadWrite, meta = (DisplayName = "Item Count"))
	int32 ItemCount;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
