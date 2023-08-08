#pragma once

#include "InventoryCategory.generated.h"

UENUM(BlueprintType)
enum class EInventoryCategory : uint8
{
	Weapon UMETA(DisplayName="Weapon"),
	Armor UMETA(DisplayName="Armor"),
	Clothing UMETA(DisplayName="Clothing"),
	Consumable UMETA(DisplayName="Consumable")
};
