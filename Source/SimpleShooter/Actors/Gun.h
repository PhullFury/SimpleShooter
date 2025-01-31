// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PullTrigger();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:	
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;
	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Effects")
		UParticleSystem* MuzzleFlash;
	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase* MuzzleSound;
	UPROPERTY(EditAnywhere, Category = "Effects")
		UParticleSystem* ImpactEffect;
	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase* ImpactSound;
	UPROPERTY(EditAnywhere, Category = "Combat")
		float MaxRange = 1000;
	UPROPERTY(EditAnywhere, Category = "Combat")
		float Damage = 10;

	void LineTrace();
	bool GunTrace(FHitResult &Hit, FVector &ShotDirection);
};