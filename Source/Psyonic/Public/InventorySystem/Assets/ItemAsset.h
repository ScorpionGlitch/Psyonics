#pragma once

#include "../Structs/ItemDetails.h"

#include "ItemAsset.generated.h"

UCLASS(BlueprintType)
class PSYONIC_API UItemAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	FItemDetails ItemDetails;
};
