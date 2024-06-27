// Fill out your copyright notice in the Description page of Project Settings.


#include "BigPipe.h"
#include "Components/BoxComponent.h"
// Sets default values
ABigPipe::ABigPipe()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	//RootComponent = boxComp;
	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	DefaultRoot->SetupAttachment(RootComponent);
	//RootComponent = DefaultRoot;
	//SetRootComponent(DefaultRoot);

	//pipeHeadMeshComp= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base mesh head"));
	//pipeHeadMeshComp->SetupAttachment(DefaultRoot); //set this as a child to capsule component
	
	/*
	pipeBodyMeshComp= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base mesh body"));
	pipeBodyMeshComp->SetupAttachment(boxComp); //set this as a child to capsule component

	MeshCollider = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshCollider"));
	MeshCollider->SetupAttachment(DefaultRoot);
	*/
	//MeshCollider->AttachToComponent(DefaultRoot, FAttachmentTransformRules::SnapToTargetIncludingScale);

}

// Called when the game starts or when spawned
void ABigPipe::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABigPipe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector move = FVector::ZeroVector;

	move.Y = moveSpeed * DeltaTime; 
	RootComponent->SetWorldLocation(RootComponent->GetComponentLocation() - move);


	if (RootComponent->GetComponentLocation().Y < -200 ) {
		Destroy();
	}
}

