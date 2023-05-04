// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/ActorComponents/QuestLogComponent.h"

#include "Kismet/GameplayStatics.h"
#include "QuestSystem/Actors/QuestBase.h"

void UQuestLogComponent::AddNewQuest(FName QuestID)
{
	CurrentActiveQuests.AddUnique(QuestID);

	AQuestBase* Quest = GetWorld()->SpawnActorDeferred<AQuestBase>(AQuestBase::StaticClass(), FTransform::Identity);
	Quest->QuestID = QuestID;
	UGameplayStatics::FinishSpawningActor(Quest, FTransform::Identity);

	CurrentQuests.Add(Quest);
}

void UQuestLogComponent::CompleteQuest()
{
}

bool UQuestLogComponent::QueryActiveQuest(FName QuestID)
{
	return CurrentActiveQuests.Contains(QuestID);
}

void UQuestLogComponent::TrackQuest()
{
}

// Sets default values for this component's properties
UQuestLogComponent::UQuestLogComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UQuestLogComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


