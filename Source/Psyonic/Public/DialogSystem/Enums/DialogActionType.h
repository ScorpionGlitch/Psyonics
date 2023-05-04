#pragma once

#include "DialogActionType.generated.h"

UENUM(BlueprintType)
enum class EDialogActionType : uint8
{
	GivePlayerGoldFromNPC UMETA(DisplayName="Give player gold from NPC's wallet"),
	GiveNPCGoldFromPlayer UMETA(DisplayName="Give NPC gold from player's wallet"),
	SetNPCDefaultConversation UMETA(DisplayName="Set new default conversation for NPC"),
	StartQuest UMETA(DisplayName="Assign quest to player")
};