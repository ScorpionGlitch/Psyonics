#pragma once
#include "Engine/DataTable.h"
#include "ResponsePrerequisite.h"
#include "Response.generated.h"

//struct FResponsePrerequisite;
/** Please add a struct description */
USTRUCT(BlueprintType)
struct FResponse : public FTableRowBase
{
	GENERATED_BODY()

	FResponse()
	{
	}

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="ResponseText"))
	FText ResponseText;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Prerequisites"))
	TArray<FResponsePrerequisite> Prerequisites;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="NextConversationName"))
	FName NextConversationName;
};
