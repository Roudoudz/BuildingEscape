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

	// Used to assign the DefaultPawn to the class DoorOpen directly in UE. Will appear in the details of the class. Can be assigned with drop-down list when the 
	// game runs, so that the player can 'eject' (otherwise, the default pawn does not appear).
	// UPROPERTY(EditAnywhere)
	//	AActor* Pawn = nullptr;  // Pawn derives from the class AActor, so can be defined as such. 

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.6f;

	UPROPERTY(EditAnywhere)
		float TotalMassToOpen = 60.f;

	UPROPERTY()
		UAudioComponent* AudioComponent = nullptr;
};
