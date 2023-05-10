// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogSystem/ActorComponents/DialogComponent.h"
#include "Blueprint/UserWidget.h"

UDialogComponent::UDialogComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	DialogWidgetClass = nullptr;
	DialogWidget = nullptr;
}

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

// Called when the game starts
void UDialogComponent::BeginPlay()
{
	Super::BeginPlay();

	const APawn* Owner = GetOwner<APawn>();
	check(Owner);
	if (Owner->IsLocallyControlled() && DialogWidgetClass)
	{
		APlayerController* PlayerController = Owner->GetController<APlayerController>();
		check(PlayerController);
		DialogWidget = CreateWidget<UDialogWidget>(PlayerController, DialogWidgetClass);
		check(DialogWidget);
		DialogWidget->AddToPlayerScreen();
	}
}
