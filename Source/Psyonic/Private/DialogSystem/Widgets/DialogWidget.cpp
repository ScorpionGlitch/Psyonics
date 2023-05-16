#include "DialogSystem/Widgets/DialogWidget.h"

#include "DialogSystem/Widgets/ResponseButtonWidget.h"
#include "Components/VerticalBox.h"

void UDialogWidget::SetResponses(TArray<FResponseDetails> Responses)
{
	if (Responses.Num() == 0)
	{
		ClearResponses();
	} else
	{
		ClearResponses();
		for (FResponseDetails ResponseDetails : Responses)
		{
			UResponseButtonWidget* ResponseButtonWidget = CreateWidget<UResponseButtonWidget>(this, ResponseButtonClass);
			ResponseButtonWidget->SetResponse(ResponseDetails);
			ResponsesVerticalBox->AddChild(ResponseButtonWidget);

			ResponseButtonWidget->OnResponseClicked.AddDynamic(this, &UDialogWidget::ResponseSelected);
		}
	}
}

void UDialogWidget::ClearResponses()
{
	ResponsesVerticalBox->ClearChildren();

	for (UResponseButtonWidget* ResponseButton : ResponseButtons)
	{
		ResponseButton->OnResponseClicked.RemoveAll(this);
	}
	ResponseButtons.Empty();
}

void UDialogWidget::ResponseSelected(const FResponseDetails& ResponseDetails)
{
	OnResponseSelected.Broadcast(ResponseDetails);
}
