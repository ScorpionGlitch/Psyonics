// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestLogComponent.generated.h"

class AQuestBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PSYONIC_API UQuestLogComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddNewQuest(FName QuestID);

	UFUNCTION(BlueprintCallable)
	void CompleteQuest();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool QueryActiveQuest(FName QuestID);

	UFUNCTION(BlueprintCallable)
	void TrackQuest();
	
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Current Active Quests"))
	TArray<FName> CurrentActiveQuestIDs;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Completed Quests"))
	TArray<FName> CompletedQuestIDs;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Current Focused Quest"))
	FName CurrentFocusedQuestID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Current Quests"))
	TArray<AQuestBase*> CurrentQuests;
	
public:	
	// Sets default values for this component's properties
	UQuestLogComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
