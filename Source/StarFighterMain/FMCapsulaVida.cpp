// Fill out your copyright notice in the Description page of Project Settings.


#include "FMCapsulaVida.h"
#include "NaveAereaJugador.h"

AFMCapsulaVida::AFMCapsulaVida()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CapsuleMesh(TEXT("StaticMesh'/Game/Meshes/defaultpickup_4.defaultpickup_4'"));
	CapsulaMesh->SetStaticMesh(CapsuleMesh.Object);
}

void AFMCapsulaVida::BeginPlay()
{
	Super::BeginPlay();
	Nombre = "Vida1";
	TipoCapsula = "Vida1";
	TipoEfecto = "...";
	TipoDuracion = "20";
}

void AFMCapsulaVida::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Generando una capsula de vida"));
}

void AFMCapsulaVida::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	ANaveAereaJugador* Cap = Cast<ANaveAereaJugador>(Other);
	if (Cap != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not"));
		Destroy();
	}
}
