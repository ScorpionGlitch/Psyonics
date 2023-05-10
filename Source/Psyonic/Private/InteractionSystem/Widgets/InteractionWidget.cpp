#include "InteractionSystem/Widgets/InteractionWidget.h"

#include "Components/TextBlock.h"

void UInteractionWidget::SetInteractionText(const FText& InteractionText)
{
	InteractionTextBlock->SetText(InteractionText);
}
