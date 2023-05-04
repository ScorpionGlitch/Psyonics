#pragma once
#include "CoreMinimal.h"
#include "StageDetails.h"
#include "Engine/DataTable.h"
#include "..\Enums\QuestType.h"

#include "QuestDetails.generated.h"

USTRUCT(BlueprintType)
struct FQuestDetails: public FTableRowBase
{
	GENERATED_BODY()

	FQuestDetails():
	QuestType(EQuestType::MainQuest),
	XPGained(0),
	MoneyGained(0)
	{
	}

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Quest Name"))
	FText QuestName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Quest Summary"))
	FText QuestSummary;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Quest Blurb"))
	FText QuestBlurb;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Quest Type"))
	EQuestType QuestType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Quest Stages"))
	TArray<FStageDetails> Stages;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="XP Gained"))
	int32 XPGained;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Money Gained"))
	int32 MoneyGained;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Items Gained"))
	TMap<FName, int32> ItemsGained;
};
