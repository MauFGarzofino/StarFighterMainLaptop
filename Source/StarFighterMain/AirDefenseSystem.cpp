// Fill out your copyright notice in the Description page of Project Settings.


#include "AirDefenseSystem.h"

// Sets default values
AAirDefenseSystem::AAirDefenseSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAirDefenseSystem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAirDefenseSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAirDefenseSystem::SetAntiAir_Turret(FString myAntiAir_Turret)
{
	AntiAir_Turret = myAntiAir_Turret;
}

void AAirDefenseSystem::SetMPADS(FString myMPADS)
{
	MPADS = myMPADS;
}

void AAirDefenseSystem::SetMIM_104_Patriot(FString myMIM_104_Patriot)
{
	MIM_104_Patriot = myMIM_104_Patriot;
}

void AAirDefenseSystem::SetNASAMS(FString myNASAMS)
{
	NASAMS = myNASAMS;
}

void AAirDefenseSystem::AirDefenseSystemCharacteristics()
{
	//Logs the name of each floors
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
		FString::Printf(TEXT("%s"),
			*AntiAir_Turret));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
		FString::Printf(TEXT("%s"),
			*MPADS));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
		FString::Printf(TEXT("%s"),
			*MIM_104_Patriot));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
		FString::Printf(TEXT("%s"),
			*NASAMS));
}

