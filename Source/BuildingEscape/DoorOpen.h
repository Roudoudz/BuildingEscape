// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "DoorOpen.generated.h" //needs to be always at the bottom of the #include


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
	float TotalMassActors() const;
	void FindAudioComponent();
	void FindTriggerVolume();

	// Tracks whether the sound has been played
	bool OpenDoorSoundPlayed = false; //doors are not open at the beginning of the play
	bool CloseDoorSoundPlayed = true; // doors are closed at the beginning of the play. They are still closed until they are opened


private:

	float InitialYaw;
	float CurrentYaw;
	float CurrentTimeInTrigger = 0.f;
		
	// Edit the parameters in the UE editor
	UPROPERTY(EditAnywhere)
		float TargetYaw = 90.f;
	
	UPROPERTY(EditAnywhere)
		ATriggerVolume* Trigger_Volume = nullptr;

	// used in previous version (see .cpp)
	// UPROPERTY(EditAnywhere)
	//	AActor* ActorThatTriggers = nullptr;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.6f;

	UPROPERTY(EditAnywhere)
		float TotalMassToOpen = 60.f;

	UPROPERTY()
		UAudioComponent* AudioComponent = nullptr;
};
