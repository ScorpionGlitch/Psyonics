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
		}
	}
}

void UDialogWidget::ClearResponses()
{
	ResponsesVerticalBox->ClearChildren();
}
