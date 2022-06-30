// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NaveNodrizaM.generated.h"

UCLASS()
class STARFIGHTERMAIN_API ANaveNodrizaM : public APawn
{
	GENERATED_BODY()
public:
    ANaveNodrizaM();
    UPROPERTY()
        ANaveNodrizaM* Instance;
protected:
// StaticMesh component that will be the visuals for our flying pawn
    UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
       class UStaticMeshComponent* ShipMeshComponent;
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
public:

	// 
	int b;
	
    // Called every frame
    virtual void Tick(float DeltaTime) override;
// Arm
    void StartFiring();
    void StopFiring();

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;
	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;
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
