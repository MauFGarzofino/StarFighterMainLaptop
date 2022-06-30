// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Enemy.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Decorator.generated.h"

UCLASS()
class STARFIGHTERMAIN_API ADecorator : public AActor , public IEnemy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecorator();
private:
	/*UPROPERTY()*/
		IEnemy* Enemy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void Fight() override;
	virtual int GetDamage() override;
	virtual void Die() override;

	//Implementacion de la interface
	void SetEnemy(IEnemy* _Enemy) { Enemy = _Enemy;}
	IEnemy* GetEnemy() { return Enemy; }
};
