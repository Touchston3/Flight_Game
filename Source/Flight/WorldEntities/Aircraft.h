// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Aircraft.generated.h"

UCLASS()
class FLIGHT_API AAircraft : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAircraft();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void InstallController(AActor* Controller); //Transfer ownership to the aircraft. Also subscribe to pilot input. 
	void UninstallController();
private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	UChildActorComponent* PilotComponent;
};
/* Required stuff
	-Mesh Component
	-Interactable Component
	-Pilot input listener (Look more into delegates)
	-Actor component for pilot



*/


