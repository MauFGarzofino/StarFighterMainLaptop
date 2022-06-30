// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DecoradorShipEnemy.h"
#include "SpaceShip.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTERMAIN_API ASpaceShip : public ADecoradorShipEnemy
{
	GENERATED_BODY()
public:
		ASpaceShip();
	protected:
	/** Sphere collision component */
	//UPROPERTY(EditAnywhere)
	//	UStaticMeshComponent* SpaceShipMesh;
public:
	//virtual void Disparo() override;
	virtual void ActivarEscudo() override;
	virtual int GetDamage() override;
	virtual void Acelerar() override;
	virtual void Die() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float TotalTime;
	float RandomStart;
	UPROPERTY(EditAnywhere)
		FVector Current_Velocity;

	//AConcreteShipEnemy* escudo = NULL;

	FVector Current_Location;
	FRotator Current_Rotation;
};
