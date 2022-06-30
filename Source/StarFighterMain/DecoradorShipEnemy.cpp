// Fill out your copyright notice in the Description page of Project Settings.


#include "DecoradorShipEnemy.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADecoradorShipEnemy::ADecoradorShipEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	/*PrimaryActorTick.bCanEverTick = true;*/


	// INCLUDES PARA EL MESHH

	////static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("StaticMesh'/Game/Meshes/LaserBolt.LaserBolt'"));
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SpaceShipAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));

	//RootComponent = SpaceShipMesh;
	//SpaceShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpaceShipMesh"));
	//SpaceShipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//SpaceShipMesh->SetStaticMesh(SpaceShipAsset.Object);
	//SpaceShipMesh->BodyInstance.SetCollisionProfileName("SpaceShipMesh");
}

// Called when the game starts or when spawned
//void ADecoradorShipEnemy::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}
//
//// Called every frame
//void ADecoradorShipEnemy::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void ADecoradorShipEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void ADecoradorShipEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADecoradorShipEnemy::ActivarEscudo()
{
	this->Enemy->ActivarEscudo();
}

int ADecoradorShipEnemy::GetDamage()
{
	return this->Enemy->GetDamage();
}

void ADecoradorShipEnemy::Acelerar()
{
	this->Enemy->Acelerar();
}

void ADecoradorShipEnemy::Die()
{
	this->Enemy->Die();
}

void ADecoradorShipEnemy::colocar(UStaticMeshComponent* malla, const TCHAR* ref)

{
		UStaticMesh* escudo;
	if (ref == NULL) {
		escudo = LoadObject<UStaticMesh>(NULL, refMesh);
	}
	else {
		escudo = LoadObject<UStaticMesh>(NULL, ref);
	}

	malla->SetStaticMesh(escudo);
	malla->SetVisibility(true);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Se crea NAVE ESPACIAL")));
}

