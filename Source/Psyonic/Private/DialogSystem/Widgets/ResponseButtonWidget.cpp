#include "DialogSystem/Widgets/ResponseButtonWidget.h"

#include "Components/TextBlock.h"

void UResponseButtonWidget::SetResponse(FResponseDetails ResponseDetails)
{
	ResponseText->SetText(ResponseDetails.ResponseText);
}
