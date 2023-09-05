// Fill out your copyright notice in the Description page of Project Settings.


#include "Aircraft.h"

// Sets default values
AAircraft::AAircraft() :
	StaticMeshComponent(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"))),
	PilotComponent(CreateDefaultSubobject<UChildActorComponent>(TEXT("Pilot")))
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	this->PrimaryActorTick.bCanEverTick = true;

	this->RootComponent = this->StaticMeshComponent;
	this->PilotComponent->SetupAttachment(this->StaticMeshComponent);

}

// Called when the game starts or when spawned
void AAircraft::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAircraft::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAircraft::InstallController(AActor* Controller)
{
}

void AAircraft::UninstallController()
{
}


