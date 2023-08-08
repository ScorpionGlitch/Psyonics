#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogSystem/Structs/ConversationDetails.h"
#include "DialogWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResponseSelected, const FResponseDetails&, ResponseDetails);

UCLASS(Abstract)
class PSYONIC_API UDialogWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetResponses(TArray<FResponseDetails> Responses);

	UFUNCTION(BlueprintCallable)
	void ClearResponses();

	FOnResponseSelected OnResponseSelected;

	UFUNCTION()
	void ResponseSelected(const FResponseDetails& ResponseDetails);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<class UResponseButtonWidget> ResponseButtonClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UTextBlock* SpeakersNameTextBlock;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UTextBlock* DialogTextBlock;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UVerticalBox* ResponsesVerticalBox;

private:
	TArray<UResponseButtonWidget*> ResponseButtons;
};