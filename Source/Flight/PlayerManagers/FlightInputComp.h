// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "FlightInputComp.generated.h"

#define MAX_ACTIVE_MODIFIERS 3

class AFlightPlayerController;
class UInputMappingContext;
class UPlayerMappableInputConfig;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFlightInputActionDelegate, FKey, Key);

UCLASS(Blueprintable)
class FLIGHT_API UFlightInputComp : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	UFlightInputComp();

	//void LoadKeymap(EInputScheme InputScheme, const TArray<FInputActionKeyMapping>* const Keymap);
	//void UnloadKeymap(EInputScheme InputScheme);
	AFlightPlayerController* GetParentController() const;
	virtual void OnComponentCreated() override;
	

//--------------------------------------------------

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UPlayerMappableInputConfig* ActiveInputConfig;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UPlayerMappableInputConfig* DefaultInputConfig;

private:
	void ClearEngineInputSettings();
	void ClearParentInputBindings();
	void SetDefaultInputBindings();

	void KeyPressedHandler(FKey Key);
	void KeyReleasedHandler(FKey Key);

//---------------------------------------------------

	
	
};
