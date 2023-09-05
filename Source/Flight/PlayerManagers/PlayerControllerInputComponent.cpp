// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerInputComponent.h"
#include "Framework/Commands/InputChord.h"
#include "GameFramework/InputSettings.h"

UPlayerControllerInputComponent::UPlayerControllerInputComponent() :
	ActiveKeymaps({}),
	ActiveModifiers({})
{
}

void UPlayerControllerInputComponent::BeginPlay()
{
	Super::BeginPlay();
	this->ClearEngineInputSettings();
	this->ClearParentInputBindings();
	this->SetDefaultInputBindings();
}

void UPlayerControllerInputComponent::LoadKeymap(EInputScheme InputScheme, const TArray<FInputCombination>& Keymap)
{
	this->ActiveKeymaps.Add(InputScheme, Keymap);
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, Keymap[0].Key.GetFName().ToString());
}

void UPlayerControllerInputComponent::UnloadKeymap(EInputScheme InputScheme)
{
	this->ActiveKeymaps.Remove(InputScheme);
}

void UPlayerControllerInputComponent::ClearEngineInputSettings()
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

void UPlayerControllerInputComponent::ClearParentInputBindings()
{
	UInputComponent::ClearActionBindings();
	UInputComponent::ClearAxisBindings();
}

//Setup all default input bindings. Basically, set delegates to handle every type of input. These delegates will populate input and active modifier buffers. 
void UPlayerControllerInputComponent::SetDefaultInputBindings()
{
	UInputComponent::BindKey(EKeys::AnyKey, EInputEvent::IE_Pressed, this, &UPlayerControllerInputComponent::KeyPressedHandler);
	UInputComponent::BindKey(EKeys::AnyKey, EInputEvent::IE_Released, this, &UPlayerControllerInputComponent::KeyReleasedHandler);
}

//Handler for all keypressed input events. This will call delegates depending on current input buffer and active key modifier. 
void UPlayerControllerInputComponent::KeyPressedHandler(FKey Key)
{

	this->ActiveModifiers.Add(Key);

	for (auto InputScheme : this->ActiveKeymaps)
	{
		for (auto InputCombination : InputScheme.Value)
		{
			if (Key == InputCombination.Key)
			{
				//Check modifiers
				bool ModifiersPressed = true;
				bool ModifierKeyInActiveBuffer = false;

				for (auto ModifierKey : InputCombination.Modifiers)
				{
					if (ModifierKey != FKey() && ModifierKey != Key)
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
					if(GEngine)
						GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, Key.GetFName().ToString());
				}
			}
		}
	}

}

void UPlayerControllerInputComponent::KeyReleasedHandler(FKey Key)
{
	this->ActiveModifiers.Remove(Key);
	//
}

