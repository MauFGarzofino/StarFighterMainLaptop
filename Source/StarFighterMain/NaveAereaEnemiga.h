// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "NaveAereaEnemiga.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTERMAIN_API ANaveAereaEnemiga : public ANaveAerea
{
	GENERATED_BODY()
public:
	ANaveAereaEnemiga();

	//
	int b;
	float c;
	int Temporizador;

	void Fire();
	void FireShot(FVector FireDirection);
	UWorld* ThisWorld;

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;
	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	void Contador();

protected:
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
		virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	float TotalTime;
	float RandomStart;
	float TimeSinceLastShot;
	float fDestroyTimer;
	float fBurstDelay;
	float TimeSinceLastShotContador;
	bool bHit;
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

//private:
//	static ANaveAereaEnemiga* Instance;
//	ANaveAereaEnemiga();
//public:
//	static ANaveAereaEnemiga* GetANaveAereaEnemiga();

	//EXAMEN
	int vidaNave;
	int numNavesDestruidas;
};
