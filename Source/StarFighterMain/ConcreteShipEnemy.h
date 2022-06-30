// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShipEnemyUI.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpaceShip.h"
#include "SpaceShipUpgrade.h"
#include "ConcreteShipEnemy.generated.h"

UCLASS()
class STARFIGHTERMAIN_API AConcreteShipEnemy : public AActor , public IShipEnemyUI
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AConcreteShipEnemy();
//protected:
//	/** Sphere collision component */
//	UPROPERTY(EditAnywhere)
//		UStaticMeshComponent* SpaceShipMesh;

	//TCHAR* refMesh = NULL;
	//UStaticMeshComponent* meshEscudo = NULL;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return naveMesh; }
	//The pure virtual functions of the Enemy
	virtual void ActivarEscudo() override {};
	virtual int GetDamage() override { return 10; };
	virtual void Die() override {};
	virtual void Acelerar() override{};

	UStaticMeshComponent* naveMesh = NULL;
	ASpaceShip* escudo = NULL;
	ASpaceShipUpgrade* escudo1 = NULL;
	//void colocar(UStaticMeshComponent* malla, const TCHAR* ref = NULL);
};
