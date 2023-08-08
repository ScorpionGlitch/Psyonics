#pragma once
#include "DialogSystem/Enums/DialogActionType.h"
#include "Engine/DataTable.h"
#include "DialogLineDetails.generated.h"

//struct FResponsePrerequisite;
/** Please add a struct description */
USTRUCT(BlueprintType)
struct PSYONIC_API FDialogLineDetails : public FTableRowBase
{
	GENERATED_BODY()

	FDialogLineDetails()
	{
	}

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="DialogText"))
	FText DialogText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Dialog Actions"))
	TMap<EDialogActionType, FString> DialogActions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Items to give the player from NPC Inventory"))
	TMap<FName, int32> ItemsToGivePlayer;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Items to give the NPC from player Inventory"))
	TMap<FName, int32> ItemsToGiveNPC;
};
