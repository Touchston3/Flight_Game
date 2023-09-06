// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimaryPlayerController.h"
#include "Engine/InputDelegateBinding.h"
#include "Flight/PlayerManagers/PlayerControllerMenuComponent.h"

APrimaryPlayerController::APrimaryPlayerController() :
	UserInputComponent(CreateDefaultSubobject<UPlayerControllerInputComponent>(TEXT("UserInputComponent"))),
	MainMenuComponent(CreateDefaultSubobject<UPlayerControllerMenuComponent>(TEXT("MainMenuComponent")))
{
	//I HATE ALL OF THIS CRAP!!!!!!!! InputComponent holds the reference to the actual InputComponent being used. Cannot access from UserInputComponent. Need to learn why. 
	APlayerController::InputComponent = this->UserInputComponent; 
	if (UInputDelegateBinding::SupportsInputDelegate(GetClass()))
	{
		InputComponent->bBlockInput = bBlockInput;		
		UInputDelegateBinding::BindInputDelegatesWithSubojects(this, APlayerController::InputComponent); //This seems like a likely culprit? Need to learn more about how delegate binding works 
	}
}

void APrimaryPlayerController::BeginPlay()
{
	APlayerController::BeginPlay();
}

//Called in random init function in PlayerController. I am sorta taking over handling.
//I am just going to register the input component. I am going to handle keybinding in the component itself and actual movement in a pawn's movement component
void APrimaryPlayerController::SetupInputComponent()
{
}

void APrimaryPlayerController::OnPossess(APawn* aPawn)
{
	APlayerController::OnPossess(aPawn);
	if (ACharacterPawn* CastedPawn = Cast<ACharacterPawn>(APlayerController::GetPawn())) //Why tf does .isA() not work in this case?
	{
		//This breaks if the characters input scheme doesn't exist in the settings map. 
		Cast<UPlayerControllerInputComponent>(this->InputComponent)->LoadKeymap(CastedPawn->InputScheme, this->MainMenuComponent->GetInputScheme(CastedPawn->InputScheme));
	}
}

void APrimaryPlayerController::OnUnPossess()
{
	if (ACharacterPawn* CastedPawn = Cast<ACharacterPawn>(APlayerController::GetPawn())) 
	{
		Cast<UPlayerControllerInputComponent>(this->InputComponent)->UnloadKeymap(Cast<ACharacterPawn>(this->GetPawn())->InputScheme);
	}
	Super::OnUnPossess();
}

void APrimaryPlayerController::AttachToPawn(APawn* InPawn)
{
	Super::AttachToPawn(InPawn);
}

void APrimaryPlayerController::DetachFromPawn()
{
	Super::DetachFromPawn();
}

