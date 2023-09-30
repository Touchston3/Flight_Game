// Fill out your copyright notice in the Description page of Project Settings.


#include "Flight/WorldEntities/Character/FlightCharacterInput.h"
#include "Flight/PlayerManagers/FlightPlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "FlightCharacterMovement.h"
#include "FlightCharacterPawn.h"



// Sets default values for this component's properties
UFlightCharacterInput::UFlightCharacterInput() :
	CharacterMappingContext(CreateDefaultSubobject<UInputMappingContext>(TEXT("CharacterMappingContext"))),
	MoveInputAction(CreateDefaultSubobject<UInputAction>(TEXT("MoveAction"))),
	LocalAcceleration(0),
	MaxSpeed(500)
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UFlightCharacterInput::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	this->UpdateCharacterPosition(DeltaTime);
	UEnhancedInputComponent::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
void UFlightCharacterInput::UpdateCharacterPosition(float DeltaTime)
{
}

void UFlightCharacterInput::SetupOnControlled(TWeakObjectPtr<AFlightPlayerController> PlayerController)
{
	if(UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) //These variable name lengths are getting outta hand
	{
		EnhancedInputSubsystem->AddMappingContext(this->CharacterMappingContext, 1);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Setting up mapping context"));
	}
	UEnhancedInputComponent::BindAction(this->MoveInputAction, ETriggerEvent::Triggered, this, &UFlightCharacterInput::HandleMove);	
	UEnhancedInputComponent::BindAction(this->LookInputAction, ETriggerEvent::Triggered, this, &UFlightCharacterInput::HandleLook);	
	UEnhancedInputComponent::BindAction(this->InteractInputAction, ETriggerEvent::Triggered, this, &UFlightCharacterInput::HandleInteract);	
}



void UFlightCharacterInput::HandleMove(const FInputActionValue& InputActionValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("HandleMove"));
	const FVector2d InputActionData = InputActionValue.Get<FVector2d>();
	const FVector MoveData(InputActionData.Y, InputActionData.X, 0);
	this->GetCharacter()->GetMovement()->AddImpulse(MoveData.GetSafeNormal(), MaxSpeed);
}

void UFlightCharacterInput::HandleLook(const FInputActionValue& InputActionValue)
{
	const FVector2d LookData = InputActionValue.Get<FVector2d>();
	this->GetCharacter()->AddControllerPitchInput(LookData.Y);
	this->GetCharacter()->AddControllerYawInput(LookData.X);
}

void UFlightCharacterInput::HandleInteract(const FInputActionValue& InputActionValue)
{
}

