// Fill out your copyright notice in the Description page of Project Settings.


#include "StarShipOperationsOfficer.h"

AStarShipOperationsOfficer::AStarShipOperationsOfficer()
{
}

void AStarShipOperationsOfficer::BeginPlay()
{
}

void AStarShipOperationsOfficer::Tick(float DeltaTime)
{
}

void AStarShipOperationsOfficer::Duty()
{
	//Print Duty string
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
		FString::Printf(TEXT("%s synthesizes and disseminates incominginformation."),* CrewTitle()));
}

FString AStarShipOperationsOfficer::CrewTitle()
{
	return "The Ops Officer";
}
