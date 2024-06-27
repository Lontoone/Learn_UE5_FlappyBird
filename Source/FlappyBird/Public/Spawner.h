// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class FLAPPYBIRD_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();
	UPROPERTY( EditAnywhere)	 float spawnInteral = 2;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:

	UPROPERTY(EditDefaultsOnly, Category = "Components")  class UBoxComponent* boxComp;
	UPROPERTY(EditDefaultsOnly, Category = "Components") TSubclassOf<class ABigPipe>  pipe;

	UFUNCTION(BlueprintCallable) void SpawnPipe();
	FTimerHandle spawnTimer;
};
