// RedRuins Softworks (c)


#include "Task1/Task01Actor.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionTypes.h" 
#include "Task1/Task01Character.h"
#include "Task1/MarkerComponent.h"


ATask01Actor::ATask01Actor()
{
	PrimaryActorTick.bCanEverTick = true;

    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
    if (SightConfig)
    {
        SightConfig->SightRadius = CombatRadius;
        SightConfig->LoseSightRadius = CombatRadius + 1.f;
        SightConfig->PeripheralVisionAngleDegrees = 360.0f;
        SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
    }
    
    PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception Component"));
    if (PerceptionComponent)
    {
        PerceptionComponent->ConfigureSense(*SightConfig);
        PerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
    }
    
    //Widget = CreateDefaultSubobject<UMarkerComponent>(TEXT("WidgetMarker"));
    //Widget->SetupAttachment(GetRootComponent());
    //Widget->TargetActor = this;

}

void ATask01Actor::BeginPlay()
{
	Super::BeginPlay();
    PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ATask01Actor::OnTargetPerceptionUpdated);

    SphereComponent = FindComponentByClass<UStaticMeshComponent>();
    if (SphereComponent && StartMaterial)
    {
        SphereComponent->SetMaterial(0, StartMaterial);
    }

}

void ATask01Actor::ChangeSphereColor()
{
    if (SphereComponent && ChangedMaterial)
    {
        SphereComponent->SetMaterial(0, ChangedMaterial);
    }
}

void ATask01Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATask01Actor::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
    if (Actor)
    {
        if (Stimulus.WasSuccessfullySensed())
        {
            ChangeSphereColor();
        }
        else
        {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Blue, FString("Player is out of sight or behind an obstruction"));
                
            }
        }
    }
}

void ATask01Actor::UpdateDistanceToPlayer()
{
    //if (Target && Widget)
    //{
    //    FVector ActorLocation = GetActorLocation();
    //    FVector PlayerLocation = Target->GetActorLocation();

    //    // Calculate the distance
    //    float Distance = FVector::Dist(ActorLocation, PlayerLocation);

    //    FString DistanceStr = FString::Printf(TEXT("Distance: %.2f meters"), Distance / 100.0f);
    //    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, DistanceStr);
    //    Widget->SetDistance(Distance);
    //}
    
}


