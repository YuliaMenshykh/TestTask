// RedRuins Softworks (c)


#include "Task1/MarkerComponent.h"
#include "Task1/MarkerWidget.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"
#include "Engine/Engine.h"
#include <Engine/Canvas.h>

UMarkerComponent::UMarkerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UMarkerComponent::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (World)
    {
        Controller = World->GetFirstPlayerController();
        if (Controller && MarkerWidgetClass)
        {
            if (!MarkerWidget)
            {
                MarkerWidget = CreateWidget<UMarkerWidget>(Controller, MarkerWidgetClass);
                MarkerWidget->AddToViewport();
                MarkerWidget->SetOwningPlayer(Controller);

                FString ControllerName = Controller->GetName();
                GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Widget Created: ") + ControllerName);
            }
        }
    }

        if (MarkerWidget->VerticalBox)
    {
        CanvasSlot = Cast<UCanvasPanelSlot>(MarkerWidget->VerticalBox->Slot);
    }

    if (CanvasSlot)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TargetActor->GetName());
    }
}

void UMarkerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (MarkerWidget && CanvasSlot)
    {
        FGeometry CachedGeometry = MarkerWidget->GetCachedGeometry();
        LocalPosition = CachedGeometry.AbsoluteToLocal(LocalCoordinates());
        CanvasSlot->SetPosition(LocalPosition);

    }
}

FVector2D UMarkerComponent::LocalCoordinates()
{
    FVector2D ScreenPosition;
 
    if (Controller)
    {
        Controller->ProjectWorldLocationToScreen(TargetActor->GetActorLocation(),ScreenPosition);

        int32 ViewportSizeX, ViewportSizeY;
        Controller->GetViewportSize(ViewportSizeX, ViewportSizeY);
       
        FString ViewportSizeXStr = FString::FromInt(ViewportSizeX);
        FString ViewportSizeYStr = FString::FromInt(ViewportSizeY);

        // Display the viewport size on screen
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "Viewport Size X: " + ViewportSizeXStr + ", Y: " + ViewportSizeYStr);


        float ClampedX = FMath::Clamp(ScreenPosition.X + XPivotOffset, XFrameOffset, ViewportSizeX - XWidgSize);
        float ClampedY = FMath::Clamp(ScreenPosition.Y + YPivotOffset, YFrameOffset, ViewportSizeY - YWidgSize);

        return FVector2D(ClampedX, ClampedY);
    }
    
    return FVector2D::ZeroVector;
}

void UMarkerComponent::SetDistance(float Distance)
{
    if ( MarkerWidget->TextBlock)
    {
        FString DistanceString = FString::Printf(TEXT("Distance: %.2f meters"), Distance);
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, DistanceString);
        MarkerWidget->TextBlock->SetText(FText::FromString(DistanceString));
    }

}
