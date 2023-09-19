// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightInputComp.h"
#include "Framework/Commands/InputChord.h"
#include "FlightPlayerController.h"
#include "GameFramework/InputSettings.h"

UFlightInputComp::UFlightInputComp() :
	ActiveKeymaps({}),
	ActiveModifiers({})
{
	//TEMP WHILE I REFACTOR THIS OUT FROM THE MENU COMPONENT
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
	
	this->AllKeymaps.Add(EInputScheme::Character, {ForwardInput, BackwardInput, LeftInput, RightInput, InteractInput});
}

void UFlightInputComp::BeginPlay()
{
	Super::BeginPlay();
	this->ClearEngineInputSettings();
	this->ClearParentInputBindings();
	this->SetDefaultInputBindings();
}

void UFlightInputComp::LoadKeymap(EInputScheme InputScheme, const TArray<FInputCombination>* const Keymap)
{
	this->ActiveKeymaps.Add(InputScheme, Keymap);
}

void UFlightInputComp::UnloadKeymap(EInputScheme InputScheme)
{
	this->ActiveKeymaps.Remove(InputScheme);
}

AFlightPlayerController* UFlightInputComp::GetParentController() const
{
	 return Cast<AFlightPlayerController>(UInputComponent::GetOwner());
}

void UFlightInputComp::TmpSetupDelegates()
{
	for(auto InputScheme : this->ActiveKeymaps)
	{
		for(auto InputCombo : *InputScheme.Value)
		{
			InputDelegates.Add(InputCombo.Key.GetFName().ToString(), FTestDelegate());
		}
	}
}

FTestDelegate* const UFlightInputComp::GetDelegateFromAction(FString ActionName)
{
	for(auto InputScheme : this->AllKeymaps)
	{
		for(auto InputCombo : InputScheme.Value)
		{
			if(InputCombo.ActionName == ActionName)
			{
				 return this->InputDelegates.Find(InputCombo.Key.GetFName().ToString());
			}
		}
	}
	return nullptr;
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


	for (auto InputScheme : this->ActiveKeymaps)
	{
		for (auto InputCombination : *InputScheme.Value)
		{
			if (Key == InputCombination.Key)
			{
				//Check modifiers
				bool ModifiersPressed = true;
				bool ModifierKeyInActiveBuffer = false;

				
				for (auto ModifierKey : InputCombination.Modifiers)
				{
					if(ModifierKey != FKey())
					{
						ModifierKeyInActiveBuffer = false;
						for (auto BufferKey : this->ActiveModifiers)
						{
							if (ModifierKey == BufferKey)
							{
								ModifierKeyInActiveBuffer = true;
								break;
							}
						}
						if (!ModifierKeyInActiveBuffer)
						{
							ModifiersPressed = ModifierKeyInActiveBuffer;
							break;
						}
					}
				}
				if (ModifiersPressed)
				{
					//publish delegate
					this->InputDelegates.FindRef(Key.GetFName().ToString()).Broadcast(Key);	
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, Key.GetFName().ToString());
				}
			}
		}
	}
	this->ActiveModifiers.Add(Key);
}

void UFlightInputComp::KeyReleasedHandler(FKey Key)
{
	this->ActiveModifiers.Remove(Key);
	//
}

