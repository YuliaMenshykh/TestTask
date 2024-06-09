// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_2.generated.h"

class UDA_1;
/**
 * 
 */
UENUM(BlueprintType)
enum class EDAEnum : uint8
{
	ValueTrue  UMETA(DisplayName = "True"),
	ValueFalse UMETA(DisplayName = "False"),
	ValueN     UMETA(DisplayName = "N"),
};

UCLASS()
class TESTTASK_2024_API UDA_2 : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	EDAEnum EnumValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", meta = (EditCondition = "EnumValue == EDAEnum::ValueTrue"))
	UDA_1* DataAsset1Reference;


};
