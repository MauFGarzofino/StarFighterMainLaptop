// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShip.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"

//void ASpaceShip::Disparo()
//{
//	Super::Disparo();
//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Naves Enemigas atacando"));
//}

ASpaceShip::ASpaceShip()
{
	/*MoveSpeed = 200.0f;*/
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> SpaceShipAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile'"));
	SpaceShipMesh->SetStaticMesh(SpaceShipAsset.Object);*/
	//RootComponent = SpaceShipMesh;
	/*Super();*/
	/* INCLUDES PARA EL MESHH*/

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("StaticMesh'/Game/Meshes/LaserBolt.LaserBolt'"));
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SpaceShipAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));

	//RootComponent = SpaceShipMesh;
	//SpaceShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpaceShipMesh"));
	//SpaceShipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//SpaceShipMesh->SetStaticMesh(SpaceShipAsset.Object);
	//SpaceShipMesh->BodyInstance.SetCollisionProfileName("SpaceShipMesh");
	refMesh = TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'");
	
}

void ASpaceShip::ActivarEscudo()
{
	Super::ActivarEscudo();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Naves Enemigas sin escudo"));
	//GetWorld()->SpawnActor<AProjectile>(GetActorLocation() +FVector(0.0f,0.0f,100.0f), FRotator(0.0f, 0.0f, 0.0f));
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SpaceShipAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	//RootComponent = SpaceShipMesh;
	//SpaceShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpaceShipMesh"));
	//SpaceShipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//SpaceShipMesh->SetStaticMesh(SpaceShipAsset.Object);
	//SpaceShipMesh->BodyInstance.SetCollisionProfileName("SpaceShipMesh");
	//if (escudo != NULL) {
	//	delete escudo;
	//}
	//escudo->colocar(meshEscudo);
}

int ASpaceShip::GetDamage()
{
	return Super::GetDamage() + 10;
}

void ASpaceShip::Acelerar()
{
	Super::Acelerar();
	FVector(1000.0, 0.0f, 0.0f);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Velocidad Constante"));
}

void ASpaceShip::Die()
{
	Super::Die();
	Destroy();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Nave Enemiga Destruida"));
}

void ASpaceShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Current_Location = this->GetActorLocation();
	Current_Rotation = this->GetActorRotation();

	Current_Location.Y += FMath::Sin(TotalTime + RandomStart);

	this->SetActorLocation(Current_Location - (Current_Velocity * DeltaTime));

	TotalTime += DeltaTime;
	TotalTime += DeltaTime;
}

