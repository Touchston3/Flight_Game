// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightCharacterPawn.h"
#include "FlightCharacterInput.h"
#include "FlightCharacterMovement.h"
#include "Flight/PlayerManagers/FlightPlayerController.h"


// Sets default values
AFlightCharacterPawn::AFlightCharacterPawn() :
	Input(CreateDefaultSubobject<UFlightCharacterInput>(TEXT("InputComp"))),
	Movement(CreateDefaultSubobject<UFlightCharacterMovement>(TEXT("MovementComp")))

{
	PrimaryActorTick.bCanEverTick = true;
	this->Input->RegisterComponent();
	this->Movement->RegisterComponent();
}

void AFlightCharacterPawn::PossessedBy(AController* NewController)
{
	if(AFlightPlayerController* FlightPlayerController = Cast<AFlightPlayerController>(NewController))
	{
		this->Input->SetupOnControlled(FlightPlayerController);
	}
	APawn::PossessedBy(NewController);
}

TWeakObjectPtr<UFlightCharacterInput> AFlightCharacterPawn::GetInput() const
{
	return this->Input;
}

TWeakObjectPtr<UFlightCharacterMovement> AFlightCharacterPawn::GetMovement() const
{
	return this->Movement;
}



