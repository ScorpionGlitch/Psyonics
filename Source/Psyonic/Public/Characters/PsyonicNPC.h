// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PsyonicCharacterBase.h"
#include "PsyonicNPC.generated.h"

UCLASS(config=Game)
class PSYONIC_API APsyonicNPC : public APsyonicCharacterBase
{
	GENERATED_BODY()

public:
	APsyonicNPC(const class FObjectInitializer& ObjectInitializer);
};

