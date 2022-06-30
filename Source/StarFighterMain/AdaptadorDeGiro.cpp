
// Fill out your copyright notice in the Description page of Project Settings.


#include "AdaptadorDeGiro.h"
#include "Eje.h"

// Sets default values
AAdaptadorDeGiro::AAdaptadorDeGiro()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAdaptadorDeGiro::BeginPlay()
{
	Super::BeginPlay();
	Timon = GetWorld()->SpawnActor<AEje>(AEje::StaticClass());
}

// Called every frame
void AAdaptadorDeGiro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAdaptadorDeGiro::Rotar()
{
	if (!Timon) {
		UE_LOG(LogTemp, Error, TEXT("Sling(): Weapon is NULL, make sure it's initialized.")); 
	return; }
			//Call the Fire function
		Timon->Girar();
}

