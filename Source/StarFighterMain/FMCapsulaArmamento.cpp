// Fill out your copyright notice in the Description page of Project Settings.


#include "FMCapsulaArmamento.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "NaveAereaJugador.h"
#include "Projectile.h"


AFMCapsulaArmamento::AFMCapsulaArmamento():Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CapsuleMesh(TEXT("StaticMesh'/Game/Meshes/defaultpickup_2.defaultpickup_2'"));
	CapsulaMesh->SetStaticMesh(CapsuleMesh.Object);
}

void AFMCapsulaArmamento::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	ANaveAereaJugador* Cap = Cast<ANaveAereaJugador>(Other);
	if (Cap != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not"));
		Destroy();
	}
}

void AFMCapsulaArmamento::BeginPlay()
{
	Super::BeginPlay();
	Nombre = "Armamento1";
	TipoCapsula = "Armamento1";
	TipoEfecto = "...";
	TiempoDuracion = 15;
}

void AFMCapsulaArmamento::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Generando una capsula de mejora de arma"));
}
