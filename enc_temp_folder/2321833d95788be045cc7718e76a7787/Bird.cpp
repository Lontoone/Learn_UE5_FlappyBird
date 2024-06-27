// Fill out your copyright notice in the Description page of Project Settings.


#include "Bird.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABird::ABird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = capsuleComp;

	baseMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base mesh"));
	baseMeshComp->SetupAttachment(capsuleComp); //set this as a child to capsule component
}

// Called when the ga#include "Components/CapsuleComponent.h"me starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();
	
	capsuleComp->OnComponentHit.AddDynamic(this , &ABird::OnHit);
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//	IE_Pressed : Every single time that this button is pressed 
	//	Bind this Jump() to this action
	// Action name must match the input setting
	PlayerInputComponent->BindAction(TEXT("Jump") , IE_Pressed , this , &ABird::Jump);
}

void ABird::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp , Warning , TEXT("Hit %s" ) ,*OtherActor->GetName());
}

void ABird::Jump()
{
	UE_LOG(LogTemp , Warning , TEXT("Hi- Jump2"));
	
	capsuleComp->AddImpulse(jumpStrength , NAME_None , true);// (jump strength , bone name)	
	UE_LOG(LogTemp, Warning, TEXT("MyVector: %s"), *capsuleComp->ComponentVelocity.ToString());
}

