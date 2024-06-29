// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "BigPipe.h"
#include "Coin.h"
#include "Components/BoxComponent.h"
// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	RootComponent = boxComp;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(this->spawnTimer , this , &ASpawner::SpawnPipe , this->spawnInteral , true );
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UFUNCTION(BlueprintCallbale) void ASpawner::SpawnPipe()
{

	float randomHeightOffset = FMath::RandRange(-300, -200);

	FVector spawnerPosition = RootComponent->GetComponentLocation();
	FVector spawnPosition = FVector(spawnerPosition.X , spawnerPosition.Y, randomHeightOffset);

	FRotator spawnerRotation = RootComponent->GetComponentRotation();
	float randomRotation = FMath::RandRange(-30, 30);
	FRotator spawnRotation = FRotator(spawnerRotation.Roll , spawnerRotation.Yaw , randomRotation);


	auto bottomPipe = GetWorld()->SpawnActor<ABigPipe>(pipe , spawnPosition , spawnRotation);
	auto new_coin = GetWorld()->SpawnActor<ACoin>(coin, RootComponent->GetComponentLocation(), RootComponent->GetComponentRotation());
	UE_LOG(LogTemp , Warning, TEXT("Spawn height %s , %s") , *spawnPosition.ToString() , *bottomPipe->GetActorLocation().ToString());
	//auto topPipe = GetWorld()->SpawnActor<ABigPipe>(pipe, RootComponent->GetComponentLocation(), RootComponent->GetComponentRotation());
}

