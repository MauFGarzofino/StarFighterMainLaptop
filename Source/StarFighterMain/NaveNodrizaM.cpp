// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveNodrizaM.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ANaveNodrizaM::ANaveNodrizaM()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/Assets/Geometry/Meshes/Spaceship2.Spaceship2'"));
    // creamos la malla
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
    //RootComponent = ShipMeshComponent;
    ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
    ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

    //Search for existing Instances of this class
    TArray<AActor*> Instances;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANaveNodrizaM::StaticClass(), Instances);
    if (Instances.Num() > 1)
    {
        //If exist at least one of them, set the instance with the first found one
        Instance = Cast<ANaveNodrizaM>(Instances[0]); GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, FString::Printf(TEXT("%s Ya Existe"), *Instance->GetName()));
        //Then Destroy this Actor
        Destroy();
    }

     //Weapon
    GunOffset = FVector(90.f, 0.f, 0.0f);
    FireRate = 0.25f;
    bCanFire = false;

    
    TimeSinceLastShot = 0.0f;
    FireForwardValue = 1.0f;
    FireRightValue = 0.0f;
    b = 0;

}

// Called when the game starts or when spawned
void ANaveNodrizaM::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANaveNodrizaM::StartFiring()
{
    bCanFire = true;
}

void ANaveNodrizaM::StopFiring()
{
    bCanFire = false;
}

void ANaveNodrizaM::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Current_Location = this->GetActorLocation();
    Current_Rotation = this->GetActorRotation();

    Current_Location.Y += FMath::Sin(TotalTime + RandomStart);

    this->SetActorLocation(Current_Location - (Current_Velocity * DeltaTime));

    //handle shooting

    TotalTime += DeltaTime;
    TimeSinceLastShot += DeltaTime;

    TotalTime += DeltaTime;
    TimeSinceLastShot += DeltaTime;

    b += DeltaTime;

    if (TimeSinceLastShot >= 1.0f && !bHit) {
        const FVector FireDirection = FVector(-FireForwardValue, FireRightValue, 0.f).GetClampedToMaxSize(1.0f);
        const FRotator FireRotation = FireDirection.Rotation();
        const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
        if (fBurstDelay >= 0.01f) {
            FActorSpawnParameters Params = {};
            Params.Owner = this;
            if (b < 5) {
                b += 1;
                GetWorld()->SpawnActor<AProjectile>(SpawnLocation, FireRotation);
                GetWorld()->SpawnActor<AProjectile>(SpawnLocation + 50.0f, FireRotation + FRotator(0.0f,-45.0f,0.0f));
                GetWorld()->SpawnActor<AProjectile>(SpawnLocation + 100.0f, FireRotation + FRotator(0.0f, 45.0f, 0.0f));
                GetWorld()->SpawnActor<AProjectile>(SpawnLocation - 50.0f, FireRotation + FRotator(0.0f, 90.0f, 0.0f));
                GetWorld()->SpawnActor<AProjectile>(SpawnLocation - 100.0f, FireRotation + FRotator(0.0f, -90.0f, 0.0f));
                UE_LOG(LogTemp, Warning, TEXT("NaveNodrizaDisparando"))
                    fBurstDelay = 0.0f;
            }
        }
        TimeSinceLastShot = 0.0f;
        fBurstDelay += DeltaTime;
    }
}
