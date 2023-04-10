// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "PsyonicAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class PSYONIC_API UPsyonicAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UPsyonicAssetManager& Get();
	
	virtual void StartInitialLoading() override;
};
