// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestSystem/Structs/QuestDetails.h"
#include "QuestBase.generated.h"

UCLASS()
class AQuestBase : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Quest ID", ExposeOnSpawn))
	FName QuestID;

protected:
	UPROPERTY(BlueprintReadWrite, meta=(DisplayName="Quest Details"))
	FQuestDetails QuestDetails;

	UPROPERTY(BlueprintReadWrite, meta=(DisplayName="Current Stage"))
	int32 CurrentStage;

	UPROPERTY(BlueprintReadWrite, meta=(DisplayName="Current Stage Details"))
	FStageDetails CurrentStageDetails;

	UPROPERTY(BlueprintReadWrite, meta=(DisplayName="Current Task Progress"))
	TMap<FString, int32> CurrentTaskProgress;

	UPROPERTY(BlueprintReadWrite, meta=(DisplayName="Is Completed"))
	bool bIsCompleted;
public:	
	// Sets default values for this actor's properties
	AQuestBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
