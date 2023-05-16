#include "DialogSystem/Widgets/ResponseButtonWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

bool UResponseButtonWidget::Initialize()
{
	bool Result = Super::Initialize();

	ResponseButton->OnClicked.AddDynamic(this, &UResponseButtonWidget::ResponseClicked);
	
	return Result;
}

void UResponseButtonWidget::SetResponse(FResponseDetails& ResponseDetails)
{
	ResponseText->SetText(ResponseDetails.ResponseText);
	Response = ResponseDetails;
}

void UResponseButtonWidget::ResponseClicked()
{
	OnResponseClicked.Broadcast(Response);
}
