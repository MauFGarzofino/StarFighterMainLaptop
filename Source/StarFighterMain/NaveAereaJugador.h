// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "Escudo.h"
#include "InventoryComponent.h"
#include "Capsula.h"
#include "SlingShot.h"
#include "Rotar.h"
#include "Components/PrimitiveComponent.h"
#include "ClockTower.h"
#include "NaveAereaJugador.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTERMAIN_API ANaveAereaJugador : public ANaveAerea, public ISlingShot, public IRotar
{
	GENERATED_BODY()
public:

	/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	///** Camera boom positioning the camera above the character */
	//UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//	class AClockTower* ClockTower
public:
	ANaveAereaJugador();

	//
	void StartFiring();
	void StopFiring();
	int a;

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End Actor Interface


	//
	void ponerEscudo1();
	void Fire1();
	void Fire();
	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection);
	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;
	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;
	//
	// 
	class AClockTower* ClockTower;
	class AFreakyAllen* FreakyAllen;
	//
	// 
	UPROPERTY()
		FVector NaveLocation;

	//Inventario
	UPROPERTY()
		UInventoryComponent* ShipInventory;
	UFUNCTION()
		void TakeItem(ACapsula* CapsulaItem);
	UFUNCTION()
		void DropItem();
	UFUNCTION()
		virtual void NotifyHit(UPrimitiveComponent* MyComp,
			AActor* Other, class UPrimitiveComponent* OtherComp,
			bool bSelfMoved, FVector HitLocation, FVector HitNormal,
			FVector NormalImpulse, const FHitResult& Hit) override;
	UFUNCTION()
		void MejoraDeArma();

	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return escudoMesh; }
	FORCEINLINE FVector GetLocation() const { return NaveLocation; }
	FORCEINLINE float GetMoveSpeed() const { return MoveSpeed; }

private:

	/* Flag to control firing  */
	uint32 bCanFire : 1;
	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	float FireForwardValue;
	float FireRightValue;
	float TimeSinceLastShot;

private:
	ISlingShot* SlingShot;
public:

	void SetSlingShot(AActor* SlingShotObj);

	void Sling();

	// Giro
private:
	IRotar* RotarNave;
public:
	void SetRotarNave(AActor* RotarNaveObj);
	void Rotar();
	void Rotar1();

	//ESCUDO PRUEBA
	UStaticMeshComponent* escudoMesh = NULL;
	AEscudo* escudo = NULL;

	/*FVector NaveLocation();*/
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public: 
	bool Dispara = false;
	bool Move = false;
};
