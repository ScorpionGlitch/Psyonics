#pragma once

#include "../Structs/ItemDetails.h"

//#include "Engine/DataTable.h"

#include "ItemAsset.generated.h"

UCLASS()
class PSYONIC_API UItemAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	FItemDetails ItemDetails;

	/*
	FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Items", GetFName());
	}
	//*/
};