// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Task01Actor.generated.h"

class UAIPerceptionComponent;
class UAISenseConfig_Sight;
struct FAIStimulus;
class UMarkerComponent;

UCLASS()
class TESTTASK_2024_API ATask01Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATask01Actor();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "AI")
	UAIPerceptionComponent* PerceptionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAISenseConfig_Sight* SightConfig;

	UPROPERTY(EditAnywhere, Category = Combat)
	float CombatRadius = 200;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* SphereComponent;

	void ChangeSphereColor();

	UPROPERTY(EditAnywhere)
	UMaterial* StartMaterial;

	UPROPERTY(EditAnywhere)
	UMaterial* ChangedMaterial;

	//UPROPERTY(VisibleAnywhere)
	//UMarkerComponent* Widget;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	//class ATask01Character* Target;

private:

	void UpdateDistanceToPlayer();


};
