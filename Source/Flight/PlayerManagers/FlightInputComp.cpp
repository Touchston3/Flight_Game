// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightInputComp.h"
#include "FlightPlayerController.h"
#include "PlayerMappableInputConfig.h"
#include "GameFramework/InputSettings.h"


UFlightInputComp::UFlightInputComp() :
	ActiveInputConfig(CreateDefaultSubobject<UPlayerMappableInputConfig>(TEXT("ActiveInputConfig"))),
	DefaultInputConfig(CreateDefaultSubobject<UPlayerMappableInputConfig>(TEXT("DefaultInputConfig")))
{
}
AFlightPlayerController* UFlightInputComp::GetParentController() const
{
	 return Cast<AFlightPlayerController>(UInputComponent::GetOwner());
}

void UFlightInputComp::OnComponentCreated()
{
	UInputComponent::OnComponentCreated();
}



void UFlightInputComp::ClearEngineInputSettings()
{
	UInputSettings* const InputSettings = UInputSettings::GetInputSettings();
	TArray<FInputActionKeyMapping> ActionMappings = InputSettings->GetActionMappings();
	for (auto iterator = ActionMappings.begin(); iterator != ActionMappings.end(); ++iterator)
	{
		InputSettings->RemoveActionMapping(*iterator);
	}

	TArray<FInputAxisKeyMapping> AxisMappings = InputSettings->GetAxisMappings();
	for (auto iterator = AxisMappings.begin(); iterator != AxisMappings.end(); ++iterator)
	{
		InputSettings->RemoveAxisMapping(*iterator);
	}
	InputSettings->SaveKeyMappings();
}

void UFlightInputComp::ClearParentInputBindings()
{
	UInputComponent::ClearActionBindings();
	UInputComponent::ClearAxisBindings();
	
}

//Setup all default input bindings. Basically, set delegates to handle every type of input. These delegates will populate input and active modifier buffers. 
void UFlightInputComp::SetDefaultInputBindings()
{
	UInputComponent::BindKey(EKeys::AnyKey, EInputEvent::IE_Pressed, this, &UFlightInputComp::KeyPressedHandler);
	UInputComponent::BindKey(EKeys::AnyKey, EInputEvent::IE_Released, this, &UFlightInputComp::KeyReleasedHandler);
}

//Handler for all keypressed input events. This will call delegates depending on current input buffer and active key modifier. 
void UFlightInputComp::KeyPressedHandler(FKey Key)
{
}

void UFlightInputComp::KeyReleasedHandler(FKey Key)
{
}

