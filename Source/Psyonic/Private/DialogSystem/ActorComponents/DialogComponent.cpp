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

void UDialogComponent::StartConversation(const FConversationDetails& ConversationDetails)
{
	Conversation = ConversationDetails;
	const ACharacter* Character = GetOwner<ACharacter>();
	APlayerController* Controller = Character->GetController<APlayerController>();

	DialogWidget->AddToPlayerScreen();
	DialogWidget->SpeakersNameTextBlock->SetText(FText::FromString("Speakers Name TBD"));

	DialogIndex = -1;
	DialogWidget->ClearResponses();
	DialogWidget->OnResponseSelected.AddDynamic(this, &UDialogComponent::ResponseSelected);
	Next();
	//DialogWidget->DialogTextBlock->SetText(Conversation.DialogLines[DialogIndex]);

	FInputModeUIOnly InputMode = FInputModeUIOnly();
	InputMode.SetWidgetToFocus(DialogWidget->TakeWidget());
		
	Controller->SetInputMode(InputMode);
	Controller->SetShowMouseCursor(true);
}

void UDialogComponent::HideConversation()
{
	const ACharacter* Character = GetOwner<ACharacter>();
	APlayerController* Controller = Character->GetController<APlayerController>();
	Controller->SetInputMode(FInputModeGameOnly());
	Controller->SetShowMouseCursor(false);
	
	DialogWidget->SpeakersNameTextBlock->SetText(FText::GetEmpty());
	DialogWidget->DialogTextBlock->SetText(FText::GetEmpty());
	DialogWidget->RemoveFromParent();

	DialogWidget->OnResponseSelected.RemoveAll(this);
}

void UDialogComponent::Next()
{
	if (DialogIndex < Conversation.DialogLines.Num() - 1)
	{
		DialogIndex++;
		DialogWidget->DialogTextBlock->SetText(Conversation.DialogLines[DialogIndex]);
		if (DialogIndex >= Conversation.DialogLines.Num() - 1)
		{
			// TODO hide responses that do not meet prerequisites
			if (Conversation.Responses.Num() > 0)
			{
				DialogWidget->SetResponses(Conversation.Responses);
			} else
			{
				HideConversation();
			}
		}
	}
}

void UDialogComponent::ResponseSelected(const FResponseDetails& Response)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Response.ResponseText.ToString())
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
