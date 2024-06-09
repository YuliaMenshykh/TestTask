// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MarkerWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTTASK_2024_API UMarkerWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite,meta = (BindWidget))
	class UVerticalBox* VerticalBox;

	UPROPERTY(meta = (BindWidget))
	class UImage* Image;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextBlock;


};
