// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Flight/PlayerManagers/PlayerControllerInputComponent.h"
#include "PlayerControllerMenuComponent.generated.h"

class UFlightMainMenu;
class APrimaryPlayerController;

UCLASS(Blueprintable)
class FLIGHT_API UPlayerControllerMenuComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerControllerMenuComponent();

	TArray<FInputCombination>* const GetInputScheme(EInputScheme Scheme);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	void LoadKeybindings();
private:	
	APrimaryPlayerController* ParentPlayerController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UFlightMainMenu> MainMenuClass;
	UFlightMainMenu* MainMenu;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UFlightMainMenu> InputSettingsMenuClass;

	TMap<EInputScheme, TArray<FInputCombination>> Keymap;


		
};
