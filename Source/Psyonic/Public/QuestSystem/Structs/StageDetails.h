#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "TaskDetails.h"

#include "StageDetails.generated.h"

USTRUCT(BlueprintType)
struct FStageDetails
{
	GENERATED_BODY()

	FStageDetails():
	XPGained(0),
	MoneyGained(0)
	{
	}

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Stage Name"))
	FText StageName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Stage Description"))
	FText StageDescription;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Stage Tasks"))
	TArray<FTaskDetails> Tasks;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="XP Gained"))
	int32 XPGained;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Money Gained"))
	int32 MoneyGained;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Items Gained"))
	TMap<FName, int32> ItemsGained;
};
