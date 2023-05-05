// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PSYONIC_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText ActionText1;
	UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
	FText ActionText2;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FText ActionText3;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText ActionText4;
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	FText ActionText5;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FText ActionText6;
	
public:	
	// Sets default values for this component's properties
	UInteractionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
