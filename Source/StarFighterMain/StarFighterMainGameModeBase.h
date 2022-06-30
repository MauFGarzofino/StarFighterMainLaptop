// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Enemy.h"
#include "ShipEnemyUI.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StarFighterMainGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTERMAIN_API AStarFighterMainGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AStarFighterMainGameModeBase();

////	//The main Enemy Actor
//	IEnemy* Enemy;
	IShipEnemyUI* EnemyShip;

//	//d
private:
	//The Builder Actor
	UPROPERTY(VisibleAnywhere, Category = "Main")
		class AAirDefenseSystemBuilder* AirDefenseSystemBuilder;

	//The Engineer Actor
	UPROPERTY(VisibleAnywhere, Category = "Main")
		class AArchitecturalEngineer* Engineer;
	//
private:
	//The Shooter Actor that holds the Gun Adapter
	UPROPERTY()
		class ANaveAereaJugador* Shooter;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	UFUNCTION()
		void SpawnMyActor();
	UPROPERTY()
		class ANaveAereaEnemiga* SpawnedActor;

	UFUNCTION()
		void DestroyActorFunction();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
//private:
//	static class ANaveAereaEnemiga* SpawnedActor;
//	void SpawnMyActor();
//public:
//	static class ANaveAereaEnemiga* GetSpawnMyActor();
};
