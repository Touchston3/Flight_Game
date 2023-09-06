// Fill out your copyright notice in the Description page of Project Settings.


#include "Flight/PlayerManagers/PlayerControllerMenuComponent.h"
#include "Flight/FlightMainMenu.h"
#include "Flight/PlayerManagers/PrimaryPlayerController.h"

// Sets default values for this component's properties
UPlayerControllerMenuComponent::UPlayerControllerMenuComponent() :
	ParentPlayerController(nullptr),
	MainMenuClass(TSubclassOf<UFlightMainMenu>()),
	MainMenu(nullptr),
	InputSettingsMenuClass(TSubclassOf<UFlightMainMenu>()),
	Keymap({})
{
	PrimaryComponentTick.bCanEverTick = false;
	this->LoadKeybindings();
}


TArray<FInputCombination>* const UPlayerControllerMenuComponent::GetInputScheme(EInputScheme Scheme)
{
	return this->Keymap.Find(Scheme);
}

// Called when the game starts
void UPlayerControllerMenuComponent::BeginPlay()
{
	UActorComponent::BeginPlay();


	this->ParentPlayerController = Cast<APrimaryPlayerController>(UActorComponent::GetOwner());
	this->MainMenu = CreateWidget<UFlightMainMenu>(this->ParentPlayerController, MainMenuClass);

	this->MainMenu->AddToViewport();
	this->ParentPlayerController->SetShowMouseCursor(true);
	
}

void UPlayerControllerMenuComponent::LoadKeybindings()
{
	//I am going to want to load saved keybindings from a file 

	FInputCombination ForwardInput;
	ForwardInput.Key = EKeys::W;
	ForwardInput.ActionName = TEXT("Forward");

	FInputCombination BackwardInput;
	BackwardInput.Key = EKeys::S;
	BackwardInput.ActionName = TEXT("Backward");

	FInputCombination LeftInput;
	LeftInput.Key = EKeys::A;
	LeftInput.ActionName = TEXT("Left");

	FInputCombination RightInput;
	RightInput.Key = EKeys::D;
	RightInput.ActionName = TEXT("Right");

	FInputCombination InteractInput;
	InteractInput.Key = EKeys::F;
	InteractInput.ActionName = TEXT("Interact");

	this->Keymap.Add(EInputScheme::Character, { ForwardInput, BackwardInput, LeftInput, RightInput, InteractInput });
}
