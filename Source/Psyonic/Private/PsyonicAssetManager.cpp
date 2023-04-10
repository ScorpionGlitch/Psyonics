// Fill out your copyright notice in the Description page of Project Settings.


#include "PsyonicAssetManager.h"
#include "AbilitySystemGlobals.h"

UPsyonicAssetManager& UPsyonicAssetManager::Get()
{
	if (UPsyonicAssetManager* Singleton = Cast<UPsyonicAssetManager>(GEngine->AssetManager))
	{
		return *Singleton;
	}
	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("Invalid Assetmanager in DefaultEngine.ini, must be PsyonicAssetManager!"));
		// This is never called as the Fata message closes the game
		return *NewObject<UPsyonicAssetManager>();
	}
}

void UPsyonicAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	UAbilitySystemGlobals::Get().InitGlobalData();
}
