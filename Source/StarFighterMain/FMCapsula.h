// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FMCapsula.generated.h"

UCLASS()
class STARFIGHTERMAIN_API AFMCapsula : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AFMCapsula();
protected:
	/** Capsule collision component */
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* CapsulaMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FString Nombre;
	FString TipoCapsula; //Vida, Energia, Armadura, Armas, ....
	FString TipoEfecto; //Agregar salud, agregar arma
	FString TipoDuracion; //A partir de su uso hasta que pierda la vida el jugador, por 10 segundos
	float TiempoDuracion;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Generar();
	void Cargar();
	void Desplegar();
	void Destruir();

	FString GetNombre() { return Nombre; }
};
