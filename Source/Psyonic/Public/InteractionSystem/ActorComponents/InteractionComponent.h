// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionSystem/Widgets/InteractionWidget.h"
#include "InteractionSystem/Interfaces/Interactable.h"
#include "InteractionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PSYONIC_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();

	UFUNCTION(BlueprintCallable)
	void ShowInteractionText(UObject* Interactable);

	UFUNCTION(BlueprintCallable)
	void HideInteractionText();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UInteractionWidget> InteractionWidgetClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInteractionWidget* InteractionWidget;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
};
