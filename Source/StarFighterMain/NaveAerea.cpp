// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAerea.h"
#include "Projectile.h"

ANaveAerea::ANaveAerea()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_2.TwinStickUFO_2'"));
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
}

void ANaveAerea::BeginPlay()
{
	Super::BeginPlay();
}

void ANaveAerea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANaveAerea::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

