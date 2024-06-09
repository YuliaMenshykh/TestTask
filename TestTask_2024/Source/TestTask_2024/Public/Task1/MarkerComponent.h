// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "MarkerComponent.generated.h"

class UMarkerWidget;
/**
 * 
 */
UCLASS()
class TESTTASK_2024_API UMarkerComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
public:
	UMarkerComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
private :


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
	class UMarkerWidget* MarkerWidget;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMarkerWidget> MarkerWidgetClass;

	UFUNCTION(BlueprintCallable)
	FVector2D LocalCoordinates();

	UPROPERTY()
	class UCanvasPanelSlot* CanvasSlot;

	APlayerController* Controller;

	FVector2D LocalPosition;

public :
	float XFrameOffset = 10.f;
	float YFrameOffset = 10.f;
	float XPivotOffset = -15.f;
	float YPivotOffset = -70.f;
	float XWidgSize = 30.f;
	float YWidgSize = 40.f;

	UPROPERTY()
	AActor* TargetActor;

	void SetDistance(float Distance);
};
