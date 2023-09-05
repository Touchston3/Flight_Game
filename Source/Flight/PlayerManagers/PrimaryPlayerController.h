// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Flight/PlayerManagers/PlayerControllerInputComponent.h"
#include "Flight/WorldEntities/CharacterPawn.h"
#include "PrimaryPlayerController.generated.h"

class UFlightMainMenu;

UCLASS(Blueprintable)
class FLIGHT_API APrimaryPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	APrimaryPlayerController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
protected:
	//IDK I might need these
	void OnPossess(APawn* aPawn) override;
	void OnUnPossess() override;
	void AttachToPawn(APawn* InPawn) override;
	void DetachFromPawn() override;



private:
	UPROPERTY(EditAnywhere)
	UPlayerControllerInputComponent* UserInputComponent;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UFlightMainMenu> MainMenuClass;
	
	UFlightMainMenu* MainMenu;

	TMap<EInputScheme, TArray<FInputCombination>> TmpAllKeymaps;
	//UserSettingsComponent

};
//This will need to know all possible keybindings so the player can set them up in the UI. This means we should have the 
