// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightPlayerController.h"
#include "FlightMenuComp.h"
#include "FlightInputComp.h"
#include "Flight/WorldEntities/Character/FlightCharacterPawn.h"

AFlightPlayerController::AFlightPlayerController() :
	MainMenuComponent(CreateDefaultSubobject<UFlightMenuComp>(TEXT("MainMenuComponent"))),
	PlayerInputComponent(CreateDefaultSubobject<UFlightInputComp>(TEXT("PlayerInputComponent")))

{
	this->MainMenuComponent->RegisterComponent();
	this->PlayerInputComponent->RegisterComponent();
}


void AFlightPlayerController::SetupInputComponent()
{
	APlayerController::SetupInputComponent();
}

void AFlightPlayerController::OnPossess(APawn* aPawn)
{
	if (AFlightCharacterPawn* CastedPawn = Cast<AFlightCharacterPawn>(APlayerController::GetPawn())) //Why tf does .isA() not work in this case?
	{
	}
	APlayerController::OnPossess(aPawn);
}

void AFlightPlayerController::OnUnPossess()
{
	if (AFlightCharacterPawn* CastedPawn = Cast<AFlightCharacterPawn>(APlayerController::GetPawn())) 
	{
	}
	APlayerController::OnUnPossess();
}

