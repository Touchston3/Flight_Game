// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "Flight/WorldEntities/CharacterPawn.h"
#include "PlayerControllerInputComponent.generated.h"

class APrimaryPlayerController;
#define MAX_ACTIVE_MODIFIERS 3

USTRUCT()
struct FInputCombination
{
	GENERATED_BODY()

	FKey Key;
	TStaticArray<FKey, MAX_ACTIVE_MODIFIERS> Modifiers;
	FString ActionName;

	inline bool operator==(FInputCombination& OtherKey)
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

UCLASS(Blueprintable)
class FLIGHT_API UPlayerControllerInputComponent : public UInputComponent
{
	GENERATED_BODY()
public:
	UPlayerControllerInputComponent();

	void BeginPlay() override;
	void LoadKeymap(EInputScheme InputScheme, const TArray<FInputCombination>* const Keymap);
	void UnloadKeymap(EInputScheme InputScheme);
private:
	void ClearEngineInputSettings();
	void ClearParentInputBindings();
	void SetDefaultInputBindings();

	void KeyPressedHandler(FKey Key);
	void KeyReleasedHandler(FKey Key);
private:
	APrimaryPlayerController* ParentPlayerController;

	TMap<EInputScheme, const TArray<FInputCombination>*> ActiveKeymaps;
	TArray<FKey> ActiveModifiers;

};
