// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightMenuComp.h"
#include "FlightPlayerController.h"


// Sets default values for this component's properties
UFlightMenuComp::UFlightMenuComp() :
	MainMenuRootClass(UFlightMenuRoot::StaticClass()),
	MainMenuRoot(CreateDefaultSubobject<UFlightMenuRoot>(TEXT("Temp Root"))),
	Keymap({})
{
	PrimaryComponentTick.bCanEverTick = false;
	this->LoadKeybindings();
}


TArray<FInputCombination>* const UFlightMenuComp::GetInputScheme(EInputScheme Scheme)
{
	return this->Keymap.Find(Scheme);
}


// Called when the game starts
void UFlightMenuComp::BeginPlay()
{
	UActorComponent::BeginPlay();

	this->MainMenuRoot = TStrongObjectPtr(CreateWidget<UFlightMenuRoot>(this->GetParentController(), MainMenuRootClass));
	this->MainMenuRoot->Init(this);

	this->MainMenuRoot->AddToViewport();
	this->GetParentController()->SetShowMouseCursor(true);
}

void UFlightMenuComp::LoadKeybindings()
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
