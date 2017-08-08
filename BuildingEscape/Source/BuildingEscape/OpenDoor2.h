// Copyright Damian Bomba 2017

#pragma once

#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "OpenDoor2.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor2 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor2();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = -90.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate; //Rember pawn inherit from actor

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.f;
	
	float LastDoorOpenTime;

	AActor* ActorThatOpens; //Rember pawn inherit from actor
	AActor* Owner; // The owning door
};
