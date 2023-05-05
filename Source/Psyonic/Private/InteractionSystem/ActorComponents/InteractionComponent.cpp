// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/InteractionSystem/ActorComponents/InteractionComponent.h"

UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
}
