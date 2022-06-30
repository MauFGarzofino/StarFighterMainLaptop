// Fill out your copyright notice in the Description page of Project Settings.


#include "ConcreteShipEnemy.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AConcreteShipEnemy::AConcreteShipEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SpaceShipAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/ArcadeEditorSphere.ArcadeEditorSphere'"));

	//RootComponent = SpaceShipMesh;
	//SpaceShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpaceShipMesh"));
	//SpaceShipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//SpaceShipMesh->SetStaticMesh(SpaceShipAsset.Object);
	//SpaceShipMesh->BodyInstance.SetCollisionProfileName("SpaceShipMesh");
	naveMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Escudo"));
	naveMesh -> SetupAttachment(GetMesh());
}

// Called when the game starts or when spawned
void AConcreteShipEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConcreteShipEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//void AConcreteShipEnemy::ActivarEscudo()
//{
//	if (escudo != NULL) {
//		delete escudo;
//	}
//	//escudo = new ASpaceShip();
//	escudo->colocar(naveMesh);
//}
//void AConcreteShipEnemy::Acelerar()
//{
//	if (escudo != NULL) {
//		delete escudo;
//	}
//	//escudo1 = new ASpaceShipUpgrade();
//	escudo->colocar(naveMesh);
//}
////
//void AConcreteShipEnemy::colocar(UStaticMeshComponent* malla, const TCHAR* ref)
//{
//	UStaticMesh* escudo;
//	if (ref == NULL) {
//		escudo = LoadObject<UStaticMesh>(NULL, refMesh);
//	}
//	else {
//		escudo = LoadObject<UStaticMesh>(NULL, ref);
//	}
//
//	malla->SetStaticMesh(escudo);
//	malla->SetVisibility(true);
//
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Se crea NAVE ESPACIAL")));
//}

