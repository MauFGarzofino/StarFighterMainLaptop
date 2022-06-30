// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShipUpgrade.h"
#include "Projectile.h"

//void ASpaceShipUpgrade::Disparo()
//{
//	Super::Disparo();
//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Naves Enemigas atacando"));
//}

ASpaceShipUpgrade::ASpaceShipUpgrade()/*:Super()*/
{
	/*Super();*/
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SpaceShipAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile'"));
	//RootComponent = SpaceShipMesh;
	//SpaceShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpaceShipMesh"));
	//SpaceShipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//SpaceShipMesh->SetStaticMesh(SpaceShipAsset.Object);
	//SpaceShipMesh->BodyInstance.SetCollisionProfileName("SpaceShipMesh");
	refMesh = TEXT("StaticMesh'/Game/Assets/Geometry/Meshes/Turret1_2.Turret1_2'");
}

void ASpaceShipUpgrade::ActivarEscudo()
{
	Super::ActivarEscudo();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Naves Enemigas adquieren escudo"));
	//MoveSpeed = 2000.0f;
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SpaceShipAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile'"));
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> SpaceShipAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile'"));*/
	
}

int ASpaceShipUpgrade::GetDamage()
{
	return Super::GetDamage() + 200;
}

void ASpaceShipUpgrade::Acelerar()
{
	Super::Acelerar();
	//MoveSpeed = 5000.0f;
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Naves Enemigas con mejora de velocidad"));
}

void ASpaceShipUpgrade::Die()
{
	Super::Die();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Nave Enemiga Destruida"));
}

void ASpaceShipUpgrade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Current_Location = this->GetActorLocation();
	Current_Rotation = this->GetActorRotation();

	Current_Location.Y += FMath::Sin(TotalTime + RandomStart);

	this->SetActorLocation(Current_Location - (Current_Velocity * DeltaTime));

	TotalTime += DeltaTime * DeltaTime;
	TotalTime += DeltaTime * DeltaTime;
}



