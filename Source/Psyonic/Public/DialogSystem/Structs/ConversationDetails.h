// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogLineDetails.h"
#include "Engine/DataTable.h"
#include "ResponseDetails.h"
#include "../Enums/DialogActionType.h"

#include "ConversationDetails.generated.h"

/** Please add a struct description */
USTRUCT(BlueprintType)
struct FConversationDetails : public FTableRowBase
{
	GENERATED_BODY()

	FConversationDetails()
	{
	}

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Dialog Lines"))
	TArray<FDialogLineDetails> DialogLines;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Responses"))
	TArray<FResponseDetails> Responses;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Dialog Actions"))
	TMap<EDialogActionType, FString> DialogActions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Items to give the player from NPC Inventory"))
	TMap<FName, int32> ItemsToGivePlayer;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Items to give the NPC from player Inventory"))
	TMap<FName, int32> ItemsToGiveNPC;
};
