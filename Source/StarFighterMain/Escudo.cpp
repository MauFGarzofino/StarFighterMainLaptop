// Fill out your copyright notice in the Description page of Project Settings.


#include "Escudo.h"

// Sets default values
AEscudo::AEscudo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	/*PrimaryActorTick.bCanEverTick = true;*/

}

// //Called when the game starts or when spawned
//void AEscudo::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}

void AEscudo::colocar(UStaticMeshComponent* malla, const TCHAR* ref)
{
	UStaticMesh* escudo;
	if (ref == NULL) {
		escudo = LoadObject<UStaticMesh>(NULL, refEscudo);
	}
	else {
		escudo = LoadObject<UStaticMesh>(NULL, ref);
	}

	malla->SetStaticMesh(escudo);
	malla->SetVisibility(true);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Se crea escudo")));
}

