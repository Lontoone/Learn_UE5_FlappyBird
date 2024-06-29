// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = capsuleComp;

	baseMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base mesh"));
	baseMeshComp->SetupAttachment(capsuleComp); //set this as a child to capsule component
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector move = FVector::ZeroVector;

	move.Y = moveSpeed * DeltaTime;
	RootComponent->SetWorldLocation(RootComponent->GetComponentLocation() - move);


	if (RootComponent->GetComponentLocation().Y < -200) {
		Destroy();
	}
}

