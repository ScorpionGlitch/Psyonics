// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystem/ActorComponents/InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}
