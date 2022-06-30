// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Subscriber.h"
#include "Morph.h"
#include "FreakyAllen.generated.h"

class AClockTower;
UCLASS()
class STARFIGHTERMAIN_API AFreakyAllen : public AActor, public	ISubscriber, public IMorph

{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFreakyAllen();
public:
	/*UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))*/
	UPROPERTY(EditAnywhere)
		class	UStaticMeshComponent* FreakyAllen;
	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

	float TotalTime;
	float RandomStart2;
	float RandomStart;
	float TimeSinceLastShot;
	float fDestroyTimer;
	float fBurstDelay;
	float TimeSinceLastShotContador;
	bool bHit;
	bool bMove;
	bool Bandera1;

	UPROPERTY(EditAnywhere)
		FVector Current_Velocity;

	FVector Current_Location;
	FRotator Current_Rotation;
private:
	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	float FireForwardValue;
	float FireRightValue;

	//
	// Constantes para evitar la repetición de mensajes en pantalla 
	int a = 0;
	float j;
	
	int cont = 0;
	//
private:

	UPROPERTY()
		AClockTower* ClockTower;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Called when this Subscriber is destroyed, it will unsubscribe this from theClock Tower
		virtual void Destroyed() override;
public:
	//Called when the Plublisher changed its state, it will execute thisSubscriber routine
		virtual void Update(class APublisher* Publisher) override;
	//Execute this Subscriber routine
	virtual void Morph() override;
	//Set the Clock Tower of this Subscriber
	void SetClockTower(AClockTower* myClockTower);
};
