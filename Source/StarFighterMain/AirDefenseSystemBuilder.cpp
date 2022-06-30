// Fill out your copyright notice in the Description page of Project Settings.


#include "AirDefenseSystemBuilder.h"
#include "AirDefenseSystem.h"

// Sets default values
AAirDefenseSystemBuilder::AAirDefenseSystemBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAirDefenseSystemBuilder::BeginPlay()
{
	Super::BeginPlay();
	//Spawn the Lodging Actors
	Lodging = GetWorld()->SpawnActor<AAirDefenseSystem>
		(AAirDefenseSystem::StaticClass());
	//Attach it to the Builder (this)
	Lodging->AttachToActor(this,
		FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void AAirDefenseSystemBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAirDefenseSystemBuilder::BuildAntiAir_Turret()
{
	if (!Lodging) {
		UE_LOG(LogTemp, Error, TEXT("BuildAntiAir_Turret():Lodging is NULL, make sure it's initialized.")); return; 
	}
	Lodging->SetAntiAir_Turret("AntiAir_Turret");
}

void AAirDefenseSystemBuilder::BuildMPADS()
{
	if (!Lodging) {
		UE_LOG(LogTemp, Error, TEXT("BuildLobbyArea():Lodging is NULL, make sure it's initialized.")); return; 
	}
			//Set the Lobby Area of the Lodging
			Lodging->SetMPADS(" Defensa aérea portatil ");
}

void AAirDefenseSystemBuilder::BuildMIM_104_Patriot()
{
	if (!Lodging) {
		UE_LOG(LogTemp, Error, TEXT("BuildRestaurants():Lodging is NULL, make sure it's initialized.")); return; 
	}
			//Set the Restaurants of the Lodging
			Lodging->SetMIM_104_Patriot("IM 104 Patriot");

}

void AAirDefenseSystemBuilder::BuildNASAMS()
{
	if (!Lodging) {
		UE_LOG(LogTemp, Error, TEXT("BuildRooms():Lodging is NULL, make sure it's initialized.")); return;
	}
	//Set the Rooms of the Lodging
	Lodging->SetNASAMS("NASAMS II");
}


AAirDefenseSystem* AAirDefenseSystemBuilder::GetLodging()
{
	return Lodging;
}


