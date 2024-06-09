// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_1.generated.h"

class UDA_2;
/**
 * 
 */
UCLASS()
class TESTTASK_2024_API UDA_1 : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "References")
	UDA_2* DataAsset2Reference;

};
