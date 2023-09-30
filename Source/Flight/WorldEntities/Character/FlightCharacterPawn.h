// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FlightCharacterPawn.generated.h"

class UFlightCharacterInput;
class UFlightCharacterMovement;

UENUM() //This should be moved elsewhere
enum class EInputScheme : uint8
{
	Character,
};

UCLASS(Blueprintable)
class FLIGHT_API AFlightCharacterPawn : public APawn
{
	GENERATED_BODY()
	
public:
	AFlightCharacterPawn();
	
	virtual void PossessedBy(AController* NewController) override;
	TWeakObjectPtr<UFlightCharacterInput> GetInput() const; 
	TWeakObjectPtr<UFlightCharacterMovement> GetMovement() const;
	
private:
	UPROPERTY(EditDefaultsOnly)
	UFlightCharacterInput* Input;
	UPROPERTY(EditDefaultsOnly)
	UFlightCharacterMovement* Movement; 
};

