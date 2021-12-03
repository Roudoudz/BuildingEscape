// Copyright Nicolas Ory 2021.


#include "DoorOpen.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"


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

	if (!Trigger_Volume)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has the OpenDoor but no Volume_Trigger set!"), *GetOwner()->GetName());
	}

	// Get the pawn, i.e. what is controlled by the player
	ActorThatTriggers = GetWorld()->GetFirstPlayerController()->GetPawn();
	

}


// Called every frame
void UDoorOpen::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// The 1st 'Trigger_Volume' argument allows the code to run even if a scene object as the 
	// 'DoorOpen' class but no 'Volume_Trigger' component attach to it (i.e. null pointer)  	
	if (Trigger_Volume && Trigger_Volume->IsOverlappingActor(ActorThatTriggers))
	{
		OpenDoor(DeltaTime);
		CurrentTimeInTrigger = GetWorld()->GetTimeSeconds();
	}
	
	else
	{
		CurrentTimeOutTrigger = GetWorld()->GetTimeSeconds();
		if (CurrentTimeOutTrigger - CurrentTimeInTrigger > DoorCloseDelay)
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

}

void UDoorOpen::CloseDoor(float DeltaTime)
{
	CurrentYaw = FMath::FInterpConstantTo(CurrentYaw, InitialYaw, DeltaTime, 180);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}