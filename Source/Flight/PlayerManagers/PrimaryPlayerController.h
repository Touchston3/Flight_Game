// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Flight/PlayerManagers/PlayerControllerInputComponent.h"
#include "Flight/WorldEntities/CharacterPawn.h"
#include "PrimaryPlayerController.generated.h"

class UPlayerControllerMenuComponent;

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
	UPROPERTY(EditDefaultsOnly)
	UPlayerControllerInputComponent* UserInputComponent;

	UPROPERTY(EditDefaultsOnly)
	UPlayerControllerMenuComponent* MainMenuComponent;
};
