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

	ConversationDetails = ConversationHandle.GetRow<FConversationDetails>(FString(""));
	
	if (ConversationDetails)
	{
		const ACharacter* Character = GetOwner<ACharacter>();
		APlayerController* Controller = Character->GetController<APlayerController>();

		DialogWidget->AddToPlayerScreen();
		DialogWidget->SpeakersNameTextBlock->SetText(FText::FromString("Speakers Name TBD"));

		DialogIndex = 0;
		DialogWidget->ClearResponses();
		DialogWidget->DialogTextBlock->SetText(ConversationDetails->DialogLines[DialogIndex]);

		FInputModeUIOnly InputMode = FInputModeUIOnly();
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

void UDialogComponent::Next()
{
	if (DialogIndex >= ConversationDetails->DialogLines.Num() - 1)
	{
		// TODO hide responses that do not meet prerequisites
		if (ConversationDetails->Responses.Num() > 0)
		{
			DialogWidget->SetResponses(ConversationDetails->Responses);
		} else
		{
			HideConversation();
		}
	} else
	{
		DialogIndex++;
		DialogWidget->DialogTextBlock->SetText(ConversationDetails->DialogLines[DialogIndex]);
	}
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
