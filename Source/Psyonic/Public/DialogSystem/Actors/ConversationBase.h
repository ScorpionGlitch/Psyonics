// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogSystem/Structs/ConversationDetails.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "ConversationBase.generated.h"

UCLASS()
class PSYONIC_API AConversationBase : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Conversation", ExposeOnSpawn, RowStructure="ConversationDetails"))
	FDataTableRowHandle ConversationDetailsHandle;
	
	// Sets default values for this actor's properties
	AConversationBase();

	UFUNCTION(BlueprintCallable)
	TArray<FDialogLineDetails> GetDialogLines();
	
	UFUNCTION(BlueprintCallable)
	TArray<FResponseDetails> GetResponses();

protected:
	UPROPERTY()
	int32 DialogLineIndex;

	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Quest Details"))
	FConversationDetails ConversationDetails;
};
