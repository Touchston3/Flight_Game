// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightPlayerController.h"
#include "FlightMenuComp.h"
#include "Engine/InputDelegateBinding.h"

AFlightPlayerController::AFlightPlayerController() :
	UserInputComponent(CreateDefaultSubobject<UFlightInputComp>(TEXT("UserInputComponent"))),
	MainMenuComponent(CreateDefaultSubobject<UFlightMenuComp>(TEXT("MainMenuComponent")))
{
	//I HATE ALL OF THIS CRAP!!!!!!!! InputComponent holds the reference to the actual InputComponent being used. Cannot access from UserInputComponent. Need to learn why. 
	APlayerController::InputComponent = this->UserInputComponent; 
	if (UInputDelegateBinding::SupportsInputDelegate(GetClass()))
	{
		InputComponent->bBlockInput = bBlockInput;		
		UInputDelegateBinding::BindInputDelegatesWithSubojects(this, APlayerController::InputComponent); //This seems like a likely culprit? Need to learn more about how delegate binding works 
	}
}

void AFlightPlayerController::BeginPlay()
{
	APlayerController::BeginPlay();
}

//Called in random init function in PlayerController. I am sorta taking over handling.
//I am just going to register the input component. I am going to handle keybinding in the component itself and actual movement in a pawn's movement component
void AFlightPlayerController::SetupInputComponent()
{
}

void AFlightPlayerController::OnPossess(APawn* aPawn)
{
	APlayerController::OnPossess(aPawn);
	if (AFlightCharacterPawn* CastedPawn = Cast<AFlightCharacterPawn>(APlayerController::GetPawn())) //Why tf does .isA() not work in this case?
	{
		//This breaks if the characters input scheme doesn't exist in the settings map. 
		Cast<UFlightInputComp>(this->InputComponent)->LoadKeymap(CastedPawn->InputScheme, this->MainMenuComponent->GetInputScheme(CastedPawn->InputScheme));
		Cast<UFlightInputComp>(this->InputComponent)->TmpSetupDelegates();
	}
}

void AFlightPlayerController::OnUnPossess()
{
	if (AFlightCharacterPawn* CastedPawn = Cast<AFlightCharacterPawn>(APlayerController::GetPawn())) 
	{
		Cast<UFlightInputComp>(this->InputComponent)->UnloadKeymap(Cast<AFlightCharacterPawn>(this->GetPawn())->InputScheme);
	}
	Super::OnUnPossess();
}

void AFlightPlayerController::AttachToPawn(APawn* InPawn)
{
	Super::AttachToPawn(InPawn);
}

void AFlightPlayerController::DetachFromPawn()
{
	Super::DetachFromPawn();
}

