// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Bird.generated.h"

UCLASS()
class FLAPPYBIRD_API ABird : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABird();

	// Because of "BlueprintImplementableEvent", don't need to declaer in .cpp file
	UFUNCTION(BlueprintImplementableEvent) void HandleReset();

	int GetScore();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:	
	//FComponentBeginOverlapSignature
private:
	// EditeDefaultsOnly = read-only in blue print
	UPROPERTY(EditDefaultsOnly, Category = "Components")  class UCapsuleComponent* capsuleComp;
	UPROPERTY(EditDefaultsOnly, Category = "Components")  class UStaticMeshComponent* baseMeshComp;

	UPROPERTY(EditAnywhere, Category = "Jump Components") FVector jumpStrength = FVector(0.0f,0.0f,10000.0f);  // z-up

	UFUNCTION() void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION() void OnOverlapStart( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void Jump();

	APlayerController* birdPlayerController;
	int score = 0;

};
