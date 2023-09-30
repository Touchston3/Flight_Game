// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlightCharacterPawn.h"
#include "FlightCharacterMovement.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FLIGHT_API UFlightCharacterMovement : public UActorComponent
{
public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	GENERATED_BODY()

public:
	UFlightCharacterMovement();
	void AddImpulse(FVector Direction, float Magnitude);

	void SetMaxSpeed(float MaxSpeed);
	FORCEINLINE TWeakObjectPtr<AFlightCharacterPawn> GetCharacter() const { return Cast<AFlightCharacterPawn>(UActorComponent::GetOwner()); }
protected:
private:
	float Drag;
	float Speed;
	FVector Velocity;
	TStrongObjectPtr<UFlightCharacterMovement> ActiveMovementMode;
	TArray<FVector> Impulses;
};
