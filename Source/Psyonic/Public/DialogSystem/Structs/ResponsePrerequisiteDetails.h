#pragma once
#include "Engine/DataTable.h"

#include "ResponsePrerequisiteDetails.generated.h"

/** Please add a struct description */
USTRUCT(BlueprintType)
struct PSYONIC_API FResponsePrerequisiteDetails : public FTableRowBase
{
	GENERATED_BODY()

	FResponsePrerequisiteDetails()
	{
	}

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="VariableName", MakeStructureDefaultValue="None"))
	FName VariableName;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="VariableValue"))
	FString VariableValue;
};
