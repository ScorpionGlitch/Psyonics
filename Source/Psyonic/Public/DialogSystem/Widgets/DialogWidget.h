#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogSystem/Structs/ConversationDetails.h"
#include "DialogWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResponseSelected, FResponseDetails, ResponseDetails);

UCLASS(Abstract)
class UDialogWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetSpeakersName(FString SpeakersName);
	void SetConversation(FConversationDetails Conversation);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<class UResponseButtonWidget> ResponseButtonClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UTextBlock* SpeakersNameTextBlock;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UTextBlock* DialogTextBlock;
};