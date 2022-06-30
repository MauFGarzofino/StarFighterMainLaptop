// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveAereaJugador.h"
#include "FMCapsula.h"

//

#include "ClockTower.h"
#include "FreakyAllen.h"

//

#include "FMCapsulaArmamento.h"
#include "FMCapsulaEnergia.h"
#include "FMCapsulaVida.h"
#include "AdaptadorDeGiro.h"
#include "Escudo.h"
#include "Escudo1.h"
#include "GunAdapter.h"
#include "Projectile.h"
#include "GunAdapter.h"
#include "NaveAereaAliada.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "StarFighterMainGameModeBase.h"


ANaveAereaJugador::ANaveAereaJugador()
{
	PrimaryActorTick.bCanEverTick = true;
	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	escudoMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Escudo"));
	/*escudoMesh->SetupAttachment(GetMesh());*/
	escudoMesh->SetupAttachment(GetMesh(), USpringArmComponent::SocketName);

	//

	// Attach
	ShipInventory = CreateDefaultSubobject<UInventoryComponent>("MyInventory");

	// Propiedades
	MoveSpeed = 1000.0f;
	Energy = 100.0f;
	Salud = 1000.0f;
	NumeroDeVidas = 3;
	ProjectileDamage = 50.0f;
	a = 0;


	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.25f;
	bCanFire = false;

	//
	TimeSinceLastShot = 0.0f;


	FireForwardValue = 1.0f;
	FireRightValue = 0.0f;


}


void ANaveAereaJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ANaveAereaJugador::StartFiring);
	/*PlayerInputComponent->BindAction(TEXT("Fire1"), IE_Pressed, this, &ANaveAereaJugador::Sling);*/
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Released, this, &ANaveAereaJugador::StopFiring);
	PlayerInputComponent->BindAction(TEXT("DropItem"), EInputEvent::IE_Pressed, this, &ANaveAereaJugador::DropItem);
	PlayerInputComponent->BindAction(TEXT("FireSling"), IE_Pressed, this, &ANaveAereaJugador::Fire1);
	PlayerInputComponent->BindAction(TEXT("Rotar"), IE_Pressed, this, &ANaveAereaJugador::Rotar1);
	PlayerInputComponent->BindAction(TEXT("Escudo"), IE_Pressed, this, &ANaveAereaJugador::ponerEscudo1);
}
void ANaveAereaJugador::ponerEscudo1()
{
	if (escudo != NULL) {
		delete escudo;
	}
	escudo = new AEscudo1();
	escudo->colocar(escudoMesh);
}
void ANaveAereaJugador::Fire1() {
	Sling();
}

void ANaveAereaJugador::Rotar1() {
	//Rotar();
	
	////GiroNave->Destroy();
	//FVector NaveL = GetLocation();

	//FRotator NaveRotacion = this->GetActorRotation();
	//FVector NavePosicion = this->GetActorLocation();
	this->AddActorLocalTransform(FTransform(FVector(1200.0f, 0.0f, 0.0f)));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Nave Teletransportándose"));
	/*this->Destroy();*/
    /*this->AddActorLocalTransform(FTransform(FVector(NavePosicion + FVector(0.0f, 500.0f,0.0f))));*/
	/*this->AddActorLocalTransform(FTransform(FRotator(90.0f, 90.0f, 90.0f)));*/
	ClockTower->SetTimeOfDay("Movimiento");
	ClockTower->SetTimeOfDay("Ataque");
}

//FVector ANaveAereaJugador::NaveLocation()
//{
//	return this->GetActorLocation();
//}

void ANaveAereaJugador::StartFiring()
{
	bCanFire = true;
}

void ANaveAereaJugador::StopFiring()
{
	bCanFire = false;
}


void ANaveAereaJugador::Tick(float DeltaSeconds)
{

	//float ProbabilidadAparicionCapsula = FMath::RandRange(0, 1000);

	//if (ProbabilidadAparicionCapsula < 50.0f) {
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("PROBANDO EL TICK")));
	//	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile'"));
	//}

	// Allen se escapa si:
	if (Move == true && Dispara && true)
	{
		ClockTower->SetTimeOfDay("Escapar");
		Move = false;
		Dispara = false;
	}

	NaveLocation = GetActorLocation();
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	if (ForwardValue != 0.0f || RightValue != 0.0f) {

		if (ForwardValue != FireForwardValue) {
			FireForwardValue = ForwardValue;
		}

		if (RightValue != FireRightValue) {
			FireRightValue = RightValue;
		}
	}
	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		ClockTower->SetTimeOfDay("Movimiento");
		Move = true;
	}
	if (MoveSpeed <= 0) {
		MoveSpeed = 0;
	}
	//handle firing
	if (bCanFire) {
		if (TimeSinceLastShot > FireRate) {
			Fire();
			TimeSinceLastShot = 0.0f;
			UE_LOG(LogTemp, Warning, TEXT("a:, %d"),a)

			a += 1;
		}
	}
	TimeSinceLastShot += DeltaSeconds;
}

void ANaveAereaJugador::Fire()
{
	bCanFire = true;
	//UE_LOG(LogTemp, Warning, TEXT("FireForwardValue: %f FireRightValue: %f"), FireForwardValue, FireRightValue);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f).GetClampedToMaxSize(1.0f);

	FireShot(FireDirection);

	// Le enviamos como parámetro 'ataque' cuando nuestra nave dispare
	ClockTower->SetTimeOfDay("Ataque");
	Dispara = true;
}

void ANaveAereaJugador::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		const FRotator FireRotation = FireDirection.Rotation();
		// Spawn projectile at an offset from this pawn
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// spawn the projectile
			World->SpawnActor<AProjectile>(SpawnLocation, FireRotation);
		}
		//bCanFire = false;
	/*	World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveAereaJugador::ShotTimerExpired, FireRate);*/
		//bCanFire = false;
	}

}

void ANaveAereaJugador::ShotTimerExpired()
{
	bCanFire = false;
}

void ANaveAereaJugador::DropItem()
{
	if (this->ShipInventory->CurrentInventory.Num() == 0)
	{
		return;
	}
	ACapsula* Item = ShipInventory->CurrentInventory.Last();
	ShipInventory->RemoveFromInventory(Item);
	//should probably use scaled bounding box
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);
}

void ANaveAereaJugador::TakeItem(ACapsula* CapsulaItem)
{
	CapsulaItem->PickUp();
	ShipInventory->AddToInventory(CapsulaItem);
}

void ANaveAereaJugador::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	ACapsula* InventoryItem = Cast<ACapsula>(Other);
	if (InventoryItem != nullptr)
	{
		FString n = InventoryItem->GetInventoryActorName();
		if (n == "AumentoDeVelocidad") {
			MoveSpeed += 500.0f;
			//UE_LOG(LogTemp, Warning, TEXT("VelocidadAumentada"));
		}
		if (n == "AumentoDeVida") {
			NumeroDeVidas += 1;
			//UE_LOG(LogTemp, Warning, TEXT("SaludAumentada"));
		}
		if (n == "MejoraDeArma") {
			// Aumentamos la velocidad de disparo
			FireRate -= 0.20f;
			//Creamos una nave aliada
			MejoraDeArma();
		}
		if (n == "DecrementoDeVelocidad") {
			//UE_LOG(LogTemp, Warning, TEXT("Decremento"));
			MoveSpeed -= 500.0f;
		}
		if (n == "DecrementoDeVida") {
			NumeroDeVidas -= 1;
		}
		if (n == "DeterioroDeArma") {

			// Reducimos la velocidad de disparo
			FireRate += 0.20f;
			ProjectileDamage += 100.0f;
		}
		GEngine->AddOnScreenDebugMessage(-1, 4, FColor::Cyan, FString::Printf(TEXT("Consumiste: %s"), *(InventoryItem->GetInventoryActorName())));
		TakeItem(InventoryItem);
	}
	//AFMCapsula* capsula = Cast<AFMCapsula>(Other);
	//if (capsula != nullptr)
	//{
	//	MoveSpeed = MoveSpeed + 500.0f;
	//	GEngine->AddOnScreenDebugMessage(-1, 4, FColor::Cyan, FString::Printf(TEXT("CHOCANDO1")));

	//}
	//AFMCapsulaArmamento* armamento = Cast<AFMCapsulaArmamento>(Other);
	//if (armamento != nullptr)
	//{
	//	MoveSpeed = MoveSpeed + 500.0f;
	//	GEngine->AddOnScreenDebugMessage(-1, 4, FColor::Cyan, FString::Printf(TEXT("CHOCANDO2")));
	//}
	//AFMCapsulaEnergia* energia = Cast<AFMCapsulaEnergia>(Other);
	//if (energia != nullptr)
	//{
	//	MoveSpeed = MoveSpeed + 500.0f;
	//	GEngine->AddOnScreenDebugMessage(-1, 4, FColor::Cyan, FString::Printf(TEXT("CHOCANDO3")));
	//}
	//AFMCapsulaVida* vida = Cast<AFMCapsulaVida>(Other);
	//if (vida != nullptr)
	//{
	//	MoveSpeed = MoveSpeed + 500.0f;
	//	GEngine->AddOnScreenDebugMessage(-1, 4, FColor::Cyan, FString::Printf(TEXT("CHOCANDO3")));
	//}
	AFMCapsula* NotifyItem = Cast<AFMCapsula>(Other);
	if (NotifyItem != nullptr) {
		FString no = NotifyItem->GetNombre();
		if (no == "Energia1") {
			MoveSpeed += 500.0f;
			UE_LOG(LogTemp, Warning, TEXT("VelocidadAumentada"));
		}
		if (no == "Vida1") {
			NumeroDeVidas += 1;
			UE_LOG(LogTemp, Warning, TEXT("Vida"));
		}
		if (no == "Armamento1") {
			FireRate -= 0.20f;
			if (FireRate < 0) {
				FireRate = 0.20f;
			}
			UE_LOG(LogTemp, Warning, TEXT("Mejora De Arma"));

		}
		GEngine->AddOnScreenDebugMessage(-1, 4, FColor::Cyan, FString::Printf(TEXT("Consumiste: %s"), *(NotifyItem->GetNombre())));
	}
}

void ANaveAereaJugador::MejoraDeArma()
{
	UE_LOG(LogTemp, Warning, TEXT("SeLlamoImplementarAlgunaArmaSecundaria"));
	const FVector SpawnLocation = GetActorLocation() + FVector(0.0f, 300.0f,0.0f);
	UWorld* const World = GetWorld();
	World->SpawnActor<ANaveAereaAliada>(SpawnLocation, FRotator::ZeroRotator);
}

// Le pasamos un SlingSHotObj lo casteo a un SlingSHot
void ANaveAereaJugador::SetSlingShot(AActor* SlingShotObj)
{
	SlingShot = Cast<ISlingShot>(SlingShotObj);
	if (!SlingShot) //Log Error if cast fails
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,TEXT("Invalid Cast! See Output log for more details"));
		UE_LOG(LogTemp, Error, TEXT("SetSlingShot(): The Actor is not aSlingShot!Are you sure that the Actor implements that interface ? "));
	}
}

void ANaveAereaJugador::Sling()
{
	if (!SlingShot) {
		UE_LOG(LogTemp, Error, TEXT("Sling(): SlingShot isNULL, make sure it's initialized.")); return;
		return;
	}
	//Fire
		SlingShot->Sling();
}

void ANaveAereaJugador::SetRotarNave(AActor* RotarNaveObj)
{
	RotarNave = Cast<IRotar>(RotarNaveObj);
	if (!RotarNave) //Log Error if cast fails
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,
			TEXT("Invalid Cast! See Output log for more details"));
    UE_LOG(LogTemp, Error, TEXT("SetSlingShot(): The Actor is not aSlingShot!Are you sure that the Actor implements that interface ? "));
	}
}


void ANaveAereaJugador::Rotar()
{
	if (!RotarNave) {
		UE_LOG(LogTemp, Error, TEXT("Sling(): SlingShot isNULL, make sure it's initialized.")); 
		return;
	}
	//Fire
	RotarNave->Rotar();
}

void ANaveAereaJugador::BeginPlay()
{
	Super::BeginPlay();
	//Spawn the Gun Adapter
	AGunAdapter* GunAdapter = GetWorld()->SpawnActor<AGunAdapter>(AGunAdapter::StaticClass());
	////Spawn the Shooter and set the Gun Adapter
	//Shooter = GetWorld()->SpawnActor<AShooter>(AShooter::StaticClass());
	SetSlingShot(GunAdapter);
	//Shoot
	//Shooter->Sling();B

	AAdaptadorDeGiro* GiroAdapter = GetWorld()->SpawnActor<AAdaptadorDeGiro>(AAdaptadorDeGiro::StaticClass());
	SetRotarNave(GiroAdapter);

	// Obeserver
//Spawn the Clock Tower
	ClockTower = GetWorld()->SpawnActor<AClockTower>
		(AClockTower::StaticClass());
	//Spawn the first Subscriber and set its Clock Tower
	FreakyAllen = GetWorld()->SpawnActor<AFreakyAllen>
		(FVector(0.0f, 0.0f, 100.0f), FRotator::ZeroRotator);
	FreakyAllen->SetClockTower(ClockTower);
	//Spawn the second Subscriber and set its Clock Tower
	ClockTower->SetTimeOfDay("Morning");
	ClockTower->SetTimeOfDay("Midday");
	ClockTower->SetTimeOfDay("Evening");
	
}
