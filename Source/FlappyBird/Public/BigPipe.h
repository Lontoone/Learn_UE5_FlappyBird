// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

#include "BigPipe.generated.h"


UCLASS()
class FLAPPYBIRD_API ABigPipe : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABigPipe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	//UPROPERTY(EditDefaultsOnly, Category = "Components")  class UBoxComponent* boxComp;
	//UPROPERTY(EditDefaultsOnly, Category = "Components")  class UStaticMeshComponent* pipeHeadMeshComp;
	//UPROPERTY(EditDefaultsOnly, Category = "Components")  class UStaticMeshComponent* pipeBodyMeshComp;
	//UPROPERTY(EditDefaultsOnly, Category = "Components")  class UStaticMeshComponent* MeshCollider = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Components")  class USceneComponent* DefaultRoot = nullptr;


	float moveSpeed = 100.f;

};
