// Fill out your copyright notice in the Description page of Project Settings.


#include "Flight/WorldEntities/Character/FlightCharacterMovement.h"


UFlightCharacterMovement::UFlightCharacterMovement():
	Drag(1),
	Speed(0),
	Velocity(0)
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UFlightCharacterMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	FVector ImpulseSum(0);
	for( const auto Impulse : this->Impulses )
	{
		ImpulseSum += this->GetCharacter()->GetActorRotation().RotateVector((Impulse * DeltaTime));
	}
	this->GetCharacter()->SetActorLocation(this->GetCharacter()->GetActorLocation() + Velocity + ImpulseSum);
	this->Speed = this->Velocity.Length();
	this->Impulses = {};
	UActorComponent::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
void UFlightCharacterMovement::AddImpulse(FVector Direction, float Magnitude)
{
	this->Impulses.Add(Direction * Magnitude);	
}

void UFlightCharacterMovement::SetMaxSpeed(float MaxSpeed)
{
	
}
