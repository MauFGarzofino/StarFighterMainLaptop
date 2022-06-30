// Fill out your copyright notice in the Description page of Project Settings.


#include "FMCapsulaEnergia.h"
#include "NaveAereaJugador.h"

AFMCapsulaEnergia::AFMCapsulaEnergia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CapsuleMesh(TEXT("StaticMesh'/Game/Meshes/defaultpickup_3.defaultpickup_3'"));
	CapsulaMesh->SetStaticMesh(CapsuleMesh.Object);
}

void AFMCapsulaEnergia::BeginPlay()
{
	Super::BeginPlay();
	Nombre = "Energia1";
	TipoCapsula = "Energia1";
	TipoEfecto = "...";
	TiempoDuracion = 10.5f;
}

void AFMCapsulaEnergia::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Generando una capsula de energia"));
}

void AFMCapsulaEnergia::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	ANaveAereaJugador* Cap = Cast<ANaveAereaJugador>(Other);
	if (Cap != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not"));
		Destroy();
	}
}
