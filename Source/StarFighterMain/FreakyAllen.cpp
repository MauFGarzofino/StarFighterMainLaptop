// Fill out your copyright notice in the Description page of Project Settings.


#include "FreakyAllen.h"
#include "Kismet/GameplayStatics.h"
#include "Publisher.h"
#include "ClockTower.h"
#include "Projectile.h"

// Sets default values
AFreakyAllen::AFreakyAllen()
{
	// Set this actor to call Tick() every frame. You can turn this off toimprove performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;
		static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));

		FreakyAllen = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
		RootComponent = FreakyAllen;
		FreakyAllen->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
		FreakyAllen->SetStaticMesh(ShipMesh.Object);

		bHit = false;
		bMove = false;
		Bandera1 = false;
}
// Called when the game starts or when spawned
void AFreakyAllen::BeginPlay()
{
	Super::BeginPlay();
	RandomStart = 0;
	RandomStart2 = 0;
	j = 0.0f;
}
// Called every frame
void AFreakyAllen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RandomStart = FMath::RandRange(-2, 2);
	RandomStart2 = FMath::RandRange(-5, 5);

	if (bMove == true) {
		// MOVIMIENTO
		Current_Location = this->GetActorLocation();
		Current_Rotation = this->GetActorRotation();

		/*Current_Location.X += FMath::Sin(TotalTime + RandomStart);
		Current_Location.Y += FMath::Sin(TotalTime + RandomStart);*/

		this->SetActorLocation(Current_Location + FVector(RandomStart, RandomStart2, 0.0f)/* - (Current_Velocity * DeltaTime)*/);
		/*this->SetActorLocation(FVector(RandomStart,RandomStart,0.0f));*/
		bMove = false;
		if (Bandera1 == true) {
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,
				FString::Printf(TEXT(" Movimiento, entonces Freaky Allen se mueve ")));
		}
	}

	// CONTADOR
	j += DeltaTime;
	j += DeltaTime;

	//UE_LOG(LogTemp, Warning, TEXT("Valor de J: %f"), j)

	if (j >= 1.0f) {
		if (cont <= 5)
		{
			if (cont == 5) {
					Bandera1 = true;
					cont = cont -6;
					a = 0;
			}
			cont += 1;
			Bandera1 = false;
		}
		j = 0.0f;
	}
		
	//handle shooting

	TotalTime += DeltaTime;
	TimeSinceLastShot += DeltaTime;

	TotalTime += DeltaTime;
	TimeSinceLastShot += DeltaTime;


	if (bHit == true) {
		const FVector FireDirection = FVector(-FireForwardValue, FireRightValue, 0.f).GetClampedToMaxSize(1.0f);
		const FRotator FireRotation = FireDirection.Rotation();
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
			FActorSpawnParameters Params = {};
			Params.Owner = this;
				GetWorld()->SpawnActor<AProjectile>(SpawnLocation+FVector(70.0f,0.0f,0.0f), FireRotation);
	}
	bHit = false;
}

void AFreakyAllen::Destroyed()
{
	//Super::Destroyed();
	//Log Error if its Clock Tower is NULL
	if (!ClockTower) {
		UE_LOG(LogTemp, Error, TEXT("Destroyed():ClockTower is NULL, make sure it's initialized.")); return; }
			//Unsubscribe from the Clock Tower if it's destroyed
		ClockTower->UnSubscribe(this);
}
void AFreakyAllen::Update(APublisher* Publisher)
{
	//Execute the routine
	Morph();
}
void AFreakyAllen::Morph()
{
	//Log Error if its Clock Tower is NULL
	if (!ClockTower) {
		UE_LOG(LogTemp, Error, TEXT("Morph():lockTower is NULL, make sure it's initialized.")); return;
	}
	//Get the current time of the Clock Tower
	FString Time = ClockTower->GetTime();
	if (!Time.Compare("Morning"))
	{
		//Execute the Morning routine
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
			FString::Printf(TEXT("It is %s, so FreakyAllen makes a bowl of cereal"),
				*Time));
	}
	else if (!Time.Compare("Midday"))
	{
		//Execute the Midday routine
		GEngine->AddOnScreenDebugMessage(-1, 7.f, FColor::Yellow,
			FString::Printf(TEXT("It is %s, so FreakyAllen's right eye starts to twitch"),
				*Time));
	}
	else if (!Time.Compare("Evening"))
	{
		//Execute the Evening routine
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
			FString::Printf(TEXT("It is %s, so FreakyAllen morphs into a blood suckingwogglesnort"),
				*Time));
	}
	else if (!Time.Compare("Movimiento")) {
		for (a; a < 1; a++) {
		 	GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Red,
		FString::Printf(TEXT(" %s, entonces Freaky Allen se mueve "), *Time));
		}
		bMove = true;
	
	}
	else if (!Time.Compare("Ataque")) {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black,
			FString::Printf(TEXT(" %s, Disparando"),
				*Time));

		bHit = true;
	}
	else if (!Time.Compare("Escapar")) {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue,
			FString::Printf(TEXT(" %s, Allen huye de la nave jugador"),
				*Time));
	}
}

void AFreakyAllen::SetClockTower(AClockTower* myClockTower)
{
	//Log Error if the passed Clock Tower is NULL
	if (!myClockTower) {
		UE_LOG(LogTemp, Error,
			TEXT("SetClockTower(): myClockTower is NULL, make sure it'sinitialized.")); return; }
				//Set the Clock Tower and Subscribe to that
				ClockTower = myClockTower;
		ClockTower->Subscribe(this);
}
