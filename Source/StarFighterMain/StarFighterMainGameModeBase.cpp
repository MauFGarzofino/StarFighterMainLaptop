// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterMainGameModeBase.h"
#include "Projectile.h"

#include "NaveAereaEnemiga.h"
#include "NaveNodrizaM.h"

#include "AirDefenseSystemBuilder.h"
#include "AirDefenseSystem.h"
#include "ArchitecturalEngineer.h"

#include "ConcreteEnemy.h"
#include "MeleeEnemy.h"
#include "ProjectileEnemy.h"
#include "ConcreteShipEnemy.h"
#include "SpaceShip.h"
#include "SpaceShipUpgrade.h"



#include "GeneradorCapsulas.h"
#include "GeneradorCapsulasArmas.h"


#include "GunAdapter.h"
#include "NaveAereaJugador.h"
// quizas en el begin play de NaveAeraeJugador
#include "StarShipFacade.h"

//Freaky Allen xd
#include "ClockTower.h"
#include "FreakyAllen.h"



AStarFighterMainGameModeBase::AStarFighterMainGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AStarFighterMainGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	SpawnMyActor();

	// Prueba  Singleton

	//Intentado que aparezcan más naves nodrizas
	//GetWorld()->SpawnActor<ANaveNodrizaM>(FVector(1500.f, 10.0f, 320.0f), FRotator(0.0f, 0.0f, 0.0f));
	//GetWorld()->SpawnActor<ANaveNodrizaM>(FVector(1000.0f, 10.0f, 320.0f), FRotator(0.0f, 0.0f, 180.0f));
	//GetWorld()->SpawnActor<ANaveNodrizaM>(FVector(500.0f, 10.0f, 320.0f), FRotator(0.0f, 0.0f, 180.0f));
	//GetWorld()->SpawnActor<ANaveNodrizaM>(FVector(1500.f, 10.0f, 320.0f), FRotator(0.0f, 0.0f, 180.0f));
	//GetWorld()->SpawnActor<ANaveNodrizaM>(FVector(1000.0f, 10.0f, 320.0f), FRotator(0.0f, 0.0f, 180.0f));
	//GetWorld()->SpawnActor<ANaveNodrizaM>(FVector(-500.0f, 10.0f, 320.0f), FRotator(0.0f, 0.0f, 180.0f));
	//GetWorld()->SpawnActor<ANaveNodrizaM>(FVector(100.0f, 10.0f, 320.0f), FRotator(0.0f, 0.0f, 180.0f));
	// 

	 /*PATRON BUILDER */
	
	//Spawn Builder and Engineer
	//AirDefenseSystemBuilder = GetWorld()->SpawnActor<AAirDefenseSystemBuilder>(AAirDefenseSystemBuilder::StaticClass());
	//Engineer = GetWorld()->SpawnActor<AArchitecturalEngineer>(AArchitecturalEngineer::StaticClass());
	////Set the Builder for the Engineer and create the buildings
	//Engineer->SetInterfacePrueba(AirDefenseSystemBuilder);
	//Engineer->ConstructLodging();
	////Get the Engineer's Lodging and Logs the created buildings
	//AAirDefenseSystem* Lodging = Engineer->GetLodging();
	//Lodging->AirDefenseSystemCharacteristics();

	 //Decoradores LIBRO
    /*Spawn a Concrete Enemy*/
	//AConcreteEnemy* ConcreteEnemy = GetWorld() -> SpawnActor<AConcreteEnemy>(AConcreteEnemy::StaticClass());
	////Spawn a Melee Enemy and set its Enemy to the Concrete one
	//AMeleeEnemy* MeleeEnemy = GetWorld() -> SpawnActor<AMeleeEnemy>(AMeleeEnemy::StaticClass());
	//MeleeEnemy->SetEnemy(ConcreteEnemy);
	////Spawn a Projectile Enemy and set its Enemy to the Melee one
	//AProjectileEnemy* ProjectileEnemy = GetWorld() -> SpawnActor<AProjectileEnemy>(AProjectileEnemy::StaticClass());
	//ProjectileEnemy->SetEnemy(MeleeEnemy);
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green,TEXT("Melee Enemies are on the horizon"));
	//Enemy = MeleeEnemy;
	//Enemy->Fight();
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green,FString::Printf(TEXT("Melee Enemies cause %i damage."), Enemy -> GetDamage()));
	//Enemy->Die();
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green,TEXT("Enemies are now armed with guns"));
	//Enemy = ProjectileEnemy;
	//Enemy->Fight();
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green,FString::Printf(TEXT("Projectile Enemies cause %i damage."), Enemy -> GetDamage()));
	//Enemy->Die();

	//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	//// PATRÓN DECORADOR
	//AConcreteShipEnemy* ConcreteEnemyShip = GetWorld()->SpawnActor<AConcreteShipEnemy>(AConcreteShipEnemy::StaticClass());
	////Spawn a Melee Enemy and set its Enemy to the Concrete one
	//ASpaceShip* SpaceShip = GetWorld()->SpawnActor<ASpaceShip>(ASpaceShip::StaticClass());
	//SpaceShip->SetEnemy(ConcreteEnemyShip);
	////Spawn a Projectile Enemy and set its Enemy to the Melee one
	//ASpaceShipUpgrade* MejoraDeNave = GetWorld()->SpawnActor<ASpaceShipUpgrade>(ASpaceShipUpgrade::StaticClass());
	//MejoraDeNave->SetEnemy(SpaceShip);
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Melee Enemies are on the horizon"));
	//EnemyShip = SpaceShip;
	///*EnemyShip->Disparo();*/
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Melee Enemies cause %i damage."), EnemyShip->GetDamage()));
	//EnemyShip->ActivarEscudo();
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Enemigos ahora con escudos"));
	//EnemyShip->Die();
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Enemies are now armed with guns"));
	//EnemyShip = MejoraDeNave;
	//EnemyShip->ActivarEscudo();
	//EnemyShip->Acelerar();
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Nave Espacial con mejora de velocidad"));

	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Projectile Enemies cause %i damage."), EnemyShip->GetDamage()));
	//EnemyShip->Die();

	/// 
//Create the Ship Facade Actor
	//AStarShipFacade* ShipFacade = GetWorld() -> SpawnActor<AStarShipFacade>(AStarShipFacade::StaticClass());
	////Execute the needed tasks
	//ShipFacade->Reveille(); 
	//ShipFacade->PlanOfTheDay();
	//ShipFacade->Taps();

	// ADAPTER
	/*Super::BeginPlay();*/
	//Spawn the Gun Adapter
	//AGunAdapter* GunAdapter = GetWorld()->SpawnActor<AGunAdapter>
	//	(AGunAdapter::StaticClass());
	////Spawn the Shooter and set the Gun Adapter
	//Shooter = GetWorld()->SpawnActor<ANaveAereaJugador>(ANaveAereaJugador::StaticClass());
	//Shooter->SetSlingShot(GunAdapter);
	////Shoot
	//Shooter->Sling();
	////

	//// Obeserver
	////Spawn the Clock Tower
	//AClockTower* ClockTower = GetWorld()->SpawnActor<AClockTower>
	//	(AClockTower::StaticClass());
	////Spawn the first Subscriber and set its Clock Tower
	//AFreakyAllen* FreakyAllen = GetWorld()->SpawnActor<AFreakyAllen>
	//	(AFreakyAllen::StaticClass());
	//FreakyAllen->SetClockTower(ClockTower);
	////Spawn the second Subscriber and set its Clock Tower
 //   ClockTower->SetTimeOfDay("Morning");
	//ClockTower->SetTimeOfDay("Midday");
	//ClockTower->SetTimeOfDay("Evening");
	//ClockTower->SetTimeOfDay("Movimiento");

}

void AStarFighterMainGameModeBase::SpawnMyActor()
{
	FTransform SpawnLocation;
	SpawnedActor = GetWorld()->SpawnActor<ANaveAereaEnemiga>(FVector(-460.0f, 0.0f, 100.0f), FRotator(0.0f, 0.0f, 0.0f));
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AStarFighterMainGameModeBase::DestroyActorFunction, 120);
}

//ANaveAereaEnemiga* AStarFighterMainGameModeBase::GetSpawnMyActor()
//{
//	if (SpawnedActor == 0)
//	{
//		SpawnedActor = NewObject<ANaveAereaEnemiga>();
//	}
//	return SpawnedActor;
//}


void AStarFighterMainGameModeBase::DestroyActorFunction()
{
	if (SpawnedActor) {
		SpawnedActor->Destroy();
		UE_LOG(LogTemp, Warning, TEXT("ActorDestruido"));
	}
}

void AStarFighterMainGameModeBase::Tick(float DeltaSeconds)
{
	 /*Factory Method*/
	 
	Super::Tick(DeltaSeconds);
	float ProbabilidadAparicionCapsula = FMath::RandRange(0, 1000);


	if (ProbabilidadAparicionCapsula < 3.0f) {

		//Create the Shops
		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
		AFMCapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Arma1");
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	}
	else if (ProbabilidadAparicionCapsula < 4.0f) {

		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
		AFMCapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Energia1");
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	}
	else if (ProbabilidadAparicionCapsula < 5.0f ) {


		AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
		AFMCapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Vida1");
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	}
	//if (ProbabilidadAparicionCapsula < 10.0f) {
	//	// PATRÓN DECORADOR
	//	AConcreteShipEnemy* ConcreteEnemyShip = GetWorld()->SpawnActor<AConcreteShipEnemy>(FVector(290.0f, 0.0f, 100.0f), FRotator(0.0f, 0.0f, 0.0f));
	//	//Spawn a Melee Enemy and set its Enemy to the Concrete one
	//	ASpaceShip* SpaceShip = GetWorld()->SpawnActor<ASpaceShip>(ASpaceShip::StaticClass());
	//	SpaceShip->SetEnemy(ConcreteEnemyShip); //Esta es tu clase base
	//	//Spawn a Projectile Enemy and set its Enemy to the Melee one
	//	ASpaceShipUpgrade* MejoraDeNave = GetWorld()->SpawnActor<ASpaceShipUpgrade>(ASpaceShipUpgrade::StaticClass());
	//	MejoraDeNave->SetEnemy(SpaceShip); // Ahora al enemingo SpaceShip le da como valor base
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Melee Enemies are on the horizon"));
	//	EnemyShip = SpaceShip;
	//	/*EnemyShip->Disparo();*/
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Melee Enemies cause %i damage."), EnemyShip->GetDamage()));
	//	EnemyShip->ActivarEscudo();
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Enemigos ahora con escudos"));
	//	EnemyShip->Die();
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Enemies are now armed with guns"));
	//    EnemyShip = MejoraDeNave;
	//    EnemyShip->ActivarEscudo();
	//	EnemyShip->Acelerar();
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Nave Espacial con mejora de velocidad"));

	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Projectile Enemies cause %i damage."), EnemyShip->GetDamage()));
	//	EnemyShip->Die();
	//}

}
