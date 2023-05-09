// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogSystem/ActorComponents/DialogComponent.h"

bool UDialogComponent::StartConversation(const FDataTableRowHandle& ConversationHandle)
{
	if (ConversationHandle.IsNull())
		return false;
	
	FConversationDetails *Conversation = ConversationHandle.GetRow<FConversationDetails>(FString(""));
	if (Conversation)
	{
		return true;
	}
	
	return false;
}

// Sets default values for this component's properties
UDialogComponent::UDialogComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UDialogComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
