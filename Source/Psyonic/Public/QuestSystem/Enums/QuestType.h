#pragma once

#include "QuestType.generated.h"

UENUM(BlueprintType)
enum class EQuestType : uint8
{
	MainQuest UMETA(DisplayName="Main Quest"),
	SideQuest UMETA(DisplayName="Side Quest")
};