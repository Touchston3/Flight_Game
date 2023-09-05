// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FFlightModuleCore : public IModuleInterface
{
public:
	void StartupModule() override;


	void ShutdownModule() override;

};

/*
	Game Framework Overview:
	1. Module Init
	2. Game Instance Init (last for lifetime of application)
	3. Default Level/World is loaded
		- GameModeBase are rules tied to the lifetime of the world. Exists on server
		- GameStateBase is the data tied to the lifetime of the world. Replicated to each User. How is this created?
	
	Player Framework Overview:
	1. Player Controller is representation of User. It is an actor but I believe it's lifetime is tied to the lifecycle of the game instance. Not exactly sure how that works.  
		- Contains Input Controller
		- Contains UI
		- Contains Camera Manager
	2. Player State is replicated to all Users. I believe it is tied to the lifetime of Controller/User
	



*/
