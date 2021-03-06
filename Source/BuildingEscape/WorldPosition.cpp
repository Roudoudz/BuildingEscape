// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPosition.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

	
	FString ObjectName = GetOwner()->GetName();
		
	// GetActorLocation(): returns the RootComponent (i.e. position x,y,z) of the Actor as a FVector
	// FVector transformed as FString with ToString()
	FString ObjectPosition = GetOwner()->GetActorLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s is at position:%s"), *ObjectName, *ObjectPosition);

	// GetActorTransform() : returns the position (x,y,z) & rotation (i,j,k) & scale (l,m,n)
	FString ObjectTransform = GetOwner()->GetActorTransform().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s is at position:%s"), *ObjectName, *ObjectTransform);
	

	FString ObjectRotation = GetOwner()->GetActorRotation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s is at position:%s, with rotation %s"), *ObjectName, *ObjectPosition, *ObjectRotation);


	
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

