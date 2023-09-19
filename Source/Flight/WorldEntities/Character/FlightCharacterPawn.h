// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FlightCharacterPawn.generated.h"

class UFlightCharacterPawnMovement;

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
	// Sets default values for this pawn's properties
	AFlightCharacterPawn();

	UPROPERTY(EditAnywhere)
	EInputScheme InputScheme;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly)
	UFlightCharacterPawnMovement* MovementComp;
};

/* Required stuff
	-Input component
	-Skeletal Mesh Component
	-Collision Component
	-Camera Component
	-Line trace interaction component

	-Ability to pilot vehicle - attach self as actor component to vehicle. Forward input to vehicle. 


*/
