// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogSystem/Structs/ConversationDetails.h"
#include "DialogSystem/Widgets/DialogWidget.h"
#include "DialogComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PSYONIC_API UDialogComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void StartConversation(FConversationDetails ConversationDetails);

	UFUNCTION(BlueprintCallable)
	void HideConversation();

	UFUNCTION(BlueprintCallable)
	void Next();
	
	UDialogComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UDialogWidget> DialogWidgetClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDialogWidget* DialogWidget;

	UFUNCTION()
	void ResponseSelected(const FResponseDetails& Response);
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	int32 DialogIndex = 0;

	UPROPERTY()
	FConversationDetails Conversation;
};
