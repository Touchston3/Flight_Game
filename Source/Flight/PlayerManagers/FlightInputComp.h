// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "Flight/WorldEntities/Character/FlightCharacterPawn.h"
#include "FlightInputComp.generated.h"

#define MAX_ACTIVE_MODIFIERS 3

class AFlightPlayerController;

USTRUCT()
struct FInputCombination
{
	GENERATED_BODY()

	FKey Key;
	TStaticArray<FKey, MAX_ACTIVE_MODIFIERS> Modifiers;
	FString ActionName;

	bool operator==(FInputCombination& OtherKey)
	{
		if (this->Key != OtherKey.Key)
			return false;
		for (UINT i = 0; i < MAX_ACTIVE_MODIFIERS; i++)
		{
			if (this->Modifiers[i] != OtherKey.Modifiers[i])
			{
				return false;
			}
		}
		return true;
	}
	//Does the other key have a subset of the chord of this Combination
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestDelegate, FKey, TestName);

UCLASS(Blueprintable)
class FLIGHT_API UFlightInputComp : public UInputComponent
{
	GENERATED_BODY()
public:
	UFlightInputComp();

	void BeginPlay() override;
	void LoadKeymap(EInputScheme InputScheme, const TArray<FInputCombination>* const Keymap);
	void UnloadKeymap(EInputScheme InputScheme);
	AFlightPlayerController* GetParentController() const;
	
	void TmpSetupDelegates();
	FTestDelegate* const GetDelegateFromAction(FString ActionName);
//--------------------------------------------------
	
private:
	void ClearEngineInputSettings();
	void ClearParentInputBindings();
	void SetDefaultInputBindings();

	void KeyPressedHandler(FKey Key);
	void KeyReleasedHandler(FKey Key);

//---------------------------------------------------

	TMap<EInputScheme, TArray<FInputCombination>> AllKeymaps;
	TMap<EInputScheme, const TArray<FInputCombination>*> ActiveKeymaps;
	TArray<FKey> ActiveModifiers;

	TMap<FString, FTestDelegate> InputDelegates;
	
};
