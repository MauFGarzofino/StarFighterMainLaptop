// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Rotar.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AdaptadorDeGiro.generated.h"

class AEje;

UCLASS()
class STARFIGHTERMAIN_API AAdaptadorDeGiro : public AActor , public IRotar
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAdaptadorDeGiro();
private:
	UPROPERTY()
	 AEje* Timon;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Rotamos la nave
	void Rotar() override;
};
