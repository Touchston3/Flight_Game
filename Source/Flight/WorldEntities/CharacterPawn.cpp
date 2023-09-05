// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPawn.h"
#include "Flight/PlayerManagers/PlayerControllerInputComponent.h"
#include "Aircraft.h"

// Sets default values
ACharacterPawn::ACharacterPawn() :
	SkeletalMesh(CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"))),
	CameraComponent(CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"))),
	InputScheme(EInputScheme::Character)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->RootComponent = this->SkeletalMesh;
	this->CameraComponent->SetupAttachment(this->SkeletalMesh);


}

// Called when the game starts or when spawned
void ACharacterPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACharacterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


