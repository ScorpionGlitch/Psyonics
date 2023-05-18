// Fill out your copyright notice in the Description page of Project Settings.


#include "..\..\..\Public\DialogSystem\Actors\ConversationBase.h"

// Sets default values
AConversationBase::AConversationBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

TArray<FDialogLineDetails> AConversationBase::GetDialogLines()
{
	return ConversationDetails.DialogLines;
}

TArray<FResponseDetails> AConversationBase::GetResponses()
{
	return ConversationDetails.Responses;
}

// Called when the game starts or when spawned
void AConversationBase::BeginPlay()
{
	Super::BeginPlay();

	if (ConversationDetailsHandle.DataTable)
	{
		ConversationDetails = *ConversationDetailsHandle.GetRow<FConversationDetails>(TEXT(""));
	}
}
