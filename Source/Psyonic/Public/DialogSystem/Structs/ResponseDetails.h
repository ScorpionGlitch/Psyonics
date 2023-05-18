#pragma once
#include "Engine/DataTable.h"
#include "ResponsePrerequisiteDetails.h"
#include "ResponseDetails.generated.h"

//struct FResponsePrerequisite;
/** Please add a struct description */
USTRUCT(BlueprintType)
struct FResponseDetails : public FTableRowBase
{
	GENERATED_BODY()

	FResponseDetails()
	{
	}

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="ResponseText"))
	FText ResponseText;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Prerequisites"))
	TArray<FResponsePrerequisiteDetails> Prerequisites;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="NextConversationHandle"))
	FDataTableRowHandle NextConversationHandle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Items to give the player from NPC Inventory"))
	TMap<FName, int32> ItemsToGivePlayer;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Items to give the NPC from player Inventory"))
	TMap<FName, int32> ItemsToGiveNPC;
};
