#pragma once

#include "TaskType.generated.h"

UENUM(BlueprintType)
enum class ETaskType : uint8
{
	Interact UMETA(DisplayName="Interact"),
	Collect UMETA(DisplayName="Collect"),
	Defeat UMETA(DisplayName="Defeat"),
	Location UMETA(DisplayName="Location")
};