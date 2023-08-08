#pragma once
#include "Engine/DataTable.h"

#include "..\Enums\TaskType.h"

#include "TaskDetails.generated.h"

USTRUCT(BlueprintType)
struct PSYONIC_API FTaskDetails
{
	GENERATED_BODY()

	FTaskDetails():
	TaskType(ETaskType::Location),
	TaskQuantity(0),
	bIsTaskOptional(false),
	XPGained(0),
	MoneyGained(0)
	{
	}

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Task Name"))
	FText TaskName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Task Description"))
	FText TaskDescription;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Task Name"))
	ETaskType TaskType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Task ID"))
	FString TaskID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Task Quantity"))
	int32 TaskQuantity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Is Task Optional"))
	bool bIsTaskOptional;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="XP Gained"))
	int32 XPGained;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Money Gained"))
	int32 MoneyGained;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Items Gained"))
	TMap<FName, int32> ItemsGained;
};
