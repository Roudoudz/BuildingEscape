// Copyright Nicolas Ory 2021.


#include "DoorOpen.h"
#include "Components/AudioComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"

#define OUT // allows to markup the text


// Sets default values for this component's properties
UDoorOpen::UDoorOpen()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorOpen::BeginPlay()
{
	Super::BeginPlay();

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw += InitialYaw; //Compond assigner equivalent to TargetYaw = TargetYaw + InitialYaw;

	FindTriggerVolume();
	FindAudioComponent();

	// Get the pawn, i.e. what is controlled by the player (only used in previous version, see comment below)
	// Is used to trigger the TriggerVolume
	// Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	
}



void UDoorOpen::FindTriggerVolume()
{
	if (!Trigger_Volume)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has the OpenDoor but no Volume_Trigger set!"), *GetOwner()->GetName());
	}
}



// Find the audio component attached to door
void UDoorOpen::FindAudioComponent()
{
	AudioComponent = GetOwner()->FindComponentByClass<UAudioComponent>();

	if (!AudioComponent) 
	{
		UE_LOG(LogTemp, Error, TEXT("No audio component attached to %s"), *GetOwner()->GetName());
	}
}



// Called every frame
void UDoorOpen::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// The 1st 'Trigger_Volume' argument allows the code to run even if a scene object as the 
	// 'DoorOpen' class but no 'Volume_Trigger' component attach to it (i.e. null pointer)  	
	// Previous version: 
	//if (Trigger_Volume && Trigger_Volume->IsOverlappingActor(Pawn))

	if (TotalMassActors() > TotalMassToOpen)
	{
		OpenDoor(DeltaTime);
		CurrentTimeInTrigger = GetWorld()->GetTimeSeconds();

	}
	else
	{
		if (GetWorld()->GetTimeSeconds() - CurrentTimeInTrigger > DoorCloseDelay)
		{
			CloseDoor(DeltaTime);
		}
	}
}



void UDoorOpen::OpenDoor(float DeltaTime)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	//UE_LOG(LogTemp, Warning, TEXT("Yaw is: %f"), GetOwner()->GetActorRotation().Yaw);

    CurrentYaw = FMath::FInterpConstantTo(CurrentYaw, TargetYaw, DeltaTime, 45);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);

	CloseDoorSoundPlayed = false;
	if (!AudioComponent) { return; }
	if (!OpenDoorSoundPlayed)
	{
		// Play sound when door opens
		AudioComponent->Play();
		OpenDoorSoundPlayed = true;
		//CloseDoorSoundPlayed = true;

	}
}



void UDoorOpen::CloseDoor(float DeltaTime)
{
	CurrentYaw = FMath::FInterpConstantTo(CurrentYaw, InitialYaw, DeltaTime, 180);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);

	OpenDoorSoundPlayed = false;
	if (!AudioComponent) { return; }
	if (!CloseDoorSoundPlayed) 
	{
		// Play sound when door closes
		AudioComponent->Play();
		CloseDoorSoundPlayed = true;
		//OpenDoorSoundPlayed = true;
	}
}



float UDoorOpen::TotalMassActors() const
{
	float TotalMass = 0.f;

	// Find and store in an array (list) all overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!Trigger_Volume) { return TotalMass; } //needs to return a float, so implement 'TotalMass', which will be null anyway if Trigger_Volume refers to nothing
	Trigger_Volume->GetOverlappingActors(OverlappingActors);

	// add their masses

	for (AActor* Actor : OverlappingActors)
	{
		// Do not forget to check the box 'Details/Collision/Generat overlap events' in details of each actor in UE
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		
		// For testing purpose only:
		//UE_LOG(LogTemp, Warning, TEXT("The total mass is: %f"), TotalMass)
		//UE_LOG(LogTemp, Warning, TEXT ("%s is on the pressure volume"), *Actor->GetName())
	}
	return TotalMass;
}
