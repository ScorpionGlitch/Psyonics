// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameModes/PsyonicGameMode.h"
#include "UObject/ConstructorHelpers.h"

APsyonicGameMode::APsyonicGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/PsyonicCharacter/BP_PsyonicCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
