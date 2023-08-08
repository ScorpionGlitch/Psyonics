#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionWidget.generated.h"

UCLASS(Abstract)
class PSYONIC_API UInteractionWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetInteractionText(const FText& InteractionText);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UTextBlock* InteractionTextBlock;
};