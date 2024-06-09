// RedRuins Softworks (c)


#include "Task1/Task01Character.h"

// Sets default values
ATask01Character::ATask01Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATask01Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATask01Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATask01Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

