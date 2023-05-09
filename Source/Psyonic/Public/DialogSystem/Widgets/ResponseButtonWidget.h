#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogSystem/Structs/ConversationDetails.h"
#include "ResponseButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResponseClicked, FResponseDetails, ResponseDetails);

UCLASS(Abstract)
class UResponseButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetResponse(FResponseDetails ResponseDetails);
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* ResponseText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* ResponseButton;
};