// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PsyonicCharacterBase.h"
#include "PsyonicCharacter.generated.h"

class UMotionWarpingComponent;
class UAbilitySystemComponent;

UCLASS(config=Game)
class APsyonicCharacter : public APsyonicCharacterBase
{
	GENERATED_BODY()

public:
	APsyonicCharacter(const class FObjectInitializer& ObjectInitializer);
};

