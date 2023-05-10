#include "InteractionSystem/ActorComponents/InteractionComponent.h"

UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInteractionComponent::ShowInteractionText(UObject* Interactable)
{
	if (Interactable->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
	{
		const FText ActionText = IInteractable::Execute_GetActionText(Interactable);
		InteractionWidget->SetInteractionText(ActionText);
		InteractionWidget->AddToPlayerScreen();
	}
}

void UInteractionComponent::HideInteractionText()
{
	InteractionWidget->SetInteractionText(FText::GetEmpty());
	InteractionWidget->RemoveFromParent();
}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	const APawn* Owner = GetOwner<APawn>();
	check(Owner);
	if (Owner->IsLocallyControlled() && InteractionWidgetClass)
	{
		APlayerController* PlayerController = Owner->GetController<APlayerController>();
		check(PlayerController);
		InteractionWidget = CreateWidget<UInteractionWidget>(PlayerController, InteractionWidgetClass);
		check(InteractionWidget);
		//InteractionWidget->AddToPlayerScreen();
	}
}

