// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "DoorOpen.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UDoorOpen : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorOpen();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);


private:

	float InitialYaw;
	float CurrentYaw;
	float CurrentTimeInTrigger = 0.f;
	float CurrentTimeOutTrigger = 0.f;
	
	// Edit the parameters in the UE editor
	UPROPERTY(EditAnywhere)
		float TargetYaw = 90.f;
	
	UPROPERTY(EditAnywhere)
		ATriggerVolume* Trigger_Volume;

	UPROPERTY(EditAnywhere)
		AActor* ActorThatTriggers;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.6f;

};
