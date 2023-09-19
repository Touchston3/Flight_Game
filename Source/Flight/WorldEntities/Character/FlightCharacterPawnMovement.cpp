// Fill out your copyright notice in the Description page of Project Settings.


#include "Flight/WorldEntities/Character/FlightCharacterPawnMovement.h"
#include "Flight/PlayerManagers/FlightPlayerController.h"
#include "Flight/PlayerManagers/FlightInputComp.h"
#include "FlightCharacterPawn.h"



// Sets default values for this component's properties
UFlightCharacterPawnMovement::UFlightCharacterPawnMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFlightCharacterPawnMovement::BeginPlay()
{
	UActorComponent::BeginPlay();
	const TWeakObjectPtr<UFlightInputComp> InputManager = Cast<AFlightPlayerController>(Cast<AFlightCharacterPawn>(GetOwner())->Controller)->UserInputComponent;
	InputManager->GetDelegateFromAction(TEXT("Forward"))->AddUniqueDynamic(this, &UFlightCharacterPawnMovement::HandleForward);
	InputManager->GetDelegateFromAction(TEXT("Backward"))->AddUniqueDynamic(this, &UFlightCharacterPawnMovement::HandleBackward);
	InputManager->GetDelegateFromAction(TEXT("Left"))->AddUniqueDynamic(this, &UFlightCharacterPawnMovement::HandleLeft);
	InputManager->GetDelegateFromAction(TEXT("Right"))->AddUniqueDynamic(this, &UFlightCharacterPawnMovement::HandleRight);
	InputManager->GetDelegateFromAction(TEXT("Interact"))->AddUniqueDynamic(this, &UFlightCharacterPawnMovement::HandleInteract);
}

void UFlightCharacterPawnMovement::HandleForward(FKey Key)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Forward"));
}

void UFlightCharacterPawnMovement::HandleBackward(FKey Key)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Backward"));
}

void UFlightCharacterPawnMovement::HandleLeft(FKey Key)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Left"));
}

void UFlightCharacterPawnMovement::HandleRight(FKey Key)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Right"));
}

void UFlightCharacterPawnMovement::HandleInteract(FKey Key)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Interact"));
}


// Called every frame
void UFlightCharacterPawnMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

