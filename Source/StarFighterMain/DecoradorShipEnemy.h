// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShipEnemyUI.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "DecoradorShipEnemy.generated.h"

UCLASS()
class STARFIGHTERMAIN_API ADecoradorShipEnemy : public AActor, public IShipEnemyUI
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecoradorShipEnemy();
//protected:
//	/** Sphere collision component */
//	UPROPERTY(EditAnywhere)
//		UStaticMeshComponent* SpaceShipMesh;
protected:
	/*UPROPERTY()*/
	IShipEnemyUI* Enemy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//float MoveSpeed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	TCHAR* refMesh = NULL;
	UStaticMeshComponent* meshEscudo = NULL;
public:
	//The pure virtual functions of the Enemy

	/*virtual void Disparo() override;*/
	virtual void ActivarEscudo() override;
	virtual int GetDamage() override;
	virtual void Acelerar() override;
	virtual void Die() override;
	//Implementacion de la interface

	
	IShipEnemyUI* GetEnemy() { return Enemy; }
	void SetEnemy(IShipEnemyUI* _Enemy) { Enemy = _Enemy; }

	/** Returns ProjectileMesh subobject **/
	//FORCEINLINE UStaticMeshComponent* GetProjectileMesh() const { return SpaceShipMesh; }
	void colocar(UStaticMeshComponent* malla, const TCHAR* ref = NULL);
};
