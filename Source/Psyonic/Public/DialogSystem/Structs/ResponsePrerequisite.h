#pragma once
#include "Engine/DataTable.h"

#include "ResponsePrerequisite.generated.h"

/** Please add a struct description */
USTRUCT(BlueprintType)
struct FResponsePrerequisite : public FTableRowBase
{
	GENERATED_BODY()

	FResponsePrerequisite()
	{
	}

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="VariableName", MakeStructureDefaultValue="None"))
	FName VariableName;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="VariableValue"))
	FString VariableValue;
};
