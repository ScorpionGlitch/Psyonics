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
	bool StartConversation(const FDataTableRowHandle& ConversationHandle);

	UFUNCTION(BlueprintCallable)
	void HideConversation();

	UDialogComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UDialogWidget> DialogWidgetClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDialogWidget* DialogWidget;
	
protected:
	virtual void BeginPlay() override;
};
