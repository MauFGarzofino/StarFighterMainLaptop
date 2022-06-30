// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfacePrueba.h"
#include "AirDefenseSystemBuilder.generated.h"

UCLASS()
class STARFIGHTERMAIN_API AAirDefenseSystemBuilder : public AActor , public IInterfacePrueba
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAirDefenseSystemBuilder();

private:
	//The Lodging Actor
	UPROPERTY(VisibleAnywhere, Category = "Air Defense System")
		class AAirDefenseSystem* Lodging;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BuildAntiAir_Turret() override;
	// man portable air defense system)
	virtual void BuildMPADS() override;
	// sistema de misiles tierra aire 
	virtual void BuildMIM_104_Patriot() override;
	//Norwegian Advanced Surface to Air Missile System
	virtual void BuildNASAMS() override;
	virtual class AAirDefenseSystem* GetLodging() override;
};
