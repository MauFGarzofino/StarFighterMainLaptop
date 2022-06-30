// Fill out your copyright notice in the Description page of Project Settings.


#include "FMCapsula.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"

// Sets default values
AFMCapsula::AFMCapsula()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CapsuleMesh(TEXT("StaticMesh'/Engine/VREditor/BasicMeshes/SM_Cube_01.SM_Cube_01'"));

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	CapsulaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	CapsulaMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CapsulaMesh->SetStaticMesh(CapsuleMesh.Object);
	CapsulaMesh->BodyInstance.SetCollisionProfileName("Projectile");

	TiempoDuracion = 5.0f;
}

// Called when the game starts or when spawned
void AFMCapsula::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFMCapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFMCapsula::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Generando la capsula %s"), *GetName()));
}

void AFMCapsula::Cargar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Cargando...")));
}

void AFMCapsula::Desplegar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se estan desplegando la capsula")));
}

void AFMCapsula::Destruir()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se esta destruyendo la capsula")));
}


