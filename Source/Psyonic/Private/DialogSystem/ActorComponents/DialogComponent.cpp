// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogSystem/ActorComponents/DialogComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

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

	if (FConversationDetails *Conversation = ConversationHandle.GetRow<FConversationDetails>(FString("")))
	{
		DialogWidget->AddToPlayerScreen();
		DialogWidget->SpeakersNameTextBlock->SetText(FText::FromString("Speakers Name TBD"));
		DialogWidget->DialogTextBlock->SetText(Conversation->DialogLines[0]);
		OnDialogStart.Broadcast();
		return true;
	}
	
	return false;
}

void UDialogComponent::HideConversation()
{
	DialogWidget->SpeakersNameTextBlock->SetText(FText::GetEmpty());
	DialogWidget->DialogTextBlock->SetText(FText::GetEmpty());
	DialogWidget->RemoveFromParent();
	OnDialogEnd.Broadcast();
}

// Called when the game starts
void UDialogComponent::BeginPlay()
{
	Super::BeginPlay();

	const APawn* DialogComponentOwner = GetOwner<APawn>();
	
	check(DialogComponentOwner);
	if (DialogWidgetClass && DialogComponentOwner->IsLocallyControlled())
	{
		APlayerController* PlayerController = DialogComponentOwner->GetController<APlayerController>();
		check(PlayerController);
		DialogWidget = CreateWidget<UDialogWidget>(PlayerController, DialogWidgetClass);
		check(DialogWidget);
	}
}
