// Fill out your copyright notice in the Description page of Project Settings.


#include "Eje.h"
#include "NaveAereaJugador.h"
#include "Projectile.h"

// Sets default values
AEje::AEje()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEje::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEje::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEje::Girar()
{
	//Print Fire log
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("Adapter"));
	//GiroNave->Destroy();
	// 	FRotator NaveRotacion = this->GetActorRotation();
	//FVector NavePosicion = GiroNave->GetActorLocation();
	GiroNave->AddActorLocalTransform(FTransform(FVector(1200.0f, 0.0f, 0.0f)));
	/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Nave Teletransportándose"));*/
	//FVector NaveL = GiroNave->GetLocation();
	//float Valor = GiroNave->GetMoveSpeed();
	//
	//GetWorld()->SpawnActor<AProjectile>(FVector(200.0f,100.0f,100.0f), FRotator(0.0f, 0.0f, 0.0f));
	/*UE_LOG(LogTemp, Warning, TEXT("Valor de la velocidad"), Valor);*/
}

