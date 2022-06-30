// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "NaveAereaAliada.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTERMAIN_API ANaveAereaAliada : public ANaveAerea
{
	GENERATED_BODY()
public:
	ANaveAereaAliada();

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

};
