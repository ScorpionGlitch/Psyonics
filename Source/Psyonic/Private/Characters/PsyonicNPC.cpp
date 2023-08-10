// Copyright Epic Games, Inc. All Rights Reserved.

#include "Public/Characters/PsyonicNPC.h"

APsyonicNPC::APsyonicNPC(const class FObjectInitializer& ObjectInitializer) :
Super(ObjectInitializer)
{
	QuestGiver = CreateDefaultSubobject<UQuestGiverComponent>(TEXT("QuestGiver"));
}
