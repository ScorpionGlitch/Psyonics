// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PsyonicCharacterBase.h"
#include "PsyonicPlayer.generated.h"

class UMotionWarpingComponent;
class UAbilitySystemComponent;

UCLASS(config=Game)
class APsyonicPlayer : public APsyonicCharacterBase
{
	GENERATED_BODY()

public:
	APsyonicPlayer(const class FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;
};

