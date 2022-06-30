// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Muro.generated.h"

UCLASS()
class STARFIGHTERMAIN_API AMuro : public AActor
{
	GENERATED_BODY()
protected:
	/** Sphere collision component */
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MuroMesh;
public:	
	// Sets default values for this actor's properties
	AMuro();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/** Returns ProjectileMesh subobject **/
	FORCEINLINE UStaticMeshComponent* GetMuroMesh() const { return MuroMesh; }
};
