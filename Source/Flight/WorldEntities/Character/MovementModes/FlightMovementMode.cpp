#include "FlightMovementMode.h"

UFlightMovementMode::UFlightMovementMode()
{
}

float UFlightMovementMode::GetSpeed()
{
	return 0;
}

FVector UFlightMovementMode::GetVelocity()
{
	return FVector(0);
}

FVector UFlightMovementMode::HandleImpulse()
{
	return FVector(0);
}
