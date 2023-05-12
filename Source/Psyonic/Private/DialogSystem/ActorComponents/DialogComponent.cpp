// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogSystem/ActorComponents/DialogComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/Character.h"

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
		const ACharacter* Character = GetOwner<ACharacter>();
		APlayerController* Controller = Character->GetController<APlayerController>();

		DialogWidget->AddToPlayerScreen();
		DialogWidget->SpeakersNameTextBlock->SetText(FText::FromString("Speakers Name TBD"));
		DialogWidget->DialogTextBlock->SetText(Conversation->DialogLines[0]);

		FInputModeUIOnly InputMode = FInputModeUIOnly();
		//InputMode.SetWidgetToFocus(DialogWidget->GetCachedWidget());
		InputMode.SetWidgetToFocus(DialogWidget->TakeWidget());
		
		Controller->SetInputMode(InputMode);
		Controller->SetShowMouseCursor(true);
		
		return true;
	}
	
	return false;
}

void UDialogComponent::HideConversation()
{
	ACharacter* Character = GetOwner<ACharacter>();
	APlayerController* Controller = Character->GetController<APlayerController>();
	Controller->SetInputMode(FInputModeGameOnly());
	Controller->SetShowMouseCursor(false);
	
	DialogWidget->SpeakersNameTextBlock->SetText(FText::GetEmpty());
	DialogWidget->DialogTextBlock->SetText(FText::GetEmpty());
	DialogWidget->RemoveFromParent();
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
	}
}
