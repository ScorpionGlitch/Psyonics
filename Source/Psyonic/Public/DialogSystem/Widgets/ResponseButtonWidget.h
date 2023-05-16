#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogSystem/Structs/ConversationDetails.h"
#include "ResponseButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResponseClicked, const FResponseDetails&, ResponseDetails);

UCLASS(Abstract)
class UResponseButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	FOnResponseClicked OnResponseClicked;

	virtual bool Initialize() override;

	UFUNCTION()
	void SetResponse(FResponseDetails& ResponseDetails);

	UFUNCTION()
	void ResponseClicked();

	FDataTableRowHandle DataTableRowHandle;
	
	FResponseDetails Response;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* ResponseText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* ResponseButton;
};