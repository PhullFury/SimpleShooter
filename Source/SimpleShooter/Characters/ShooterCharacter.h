// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	void PullTrigger();

	UFUNCTION(BlueprintPure)
		bool IsDead() const;
	UFUNCTION(BlueprintPure)
		float GetCurrentHealth() const;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	void MoveForward(float AxisValue);
	void MoveSideways(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookSidewaysRate(float AxisValue);
	void Sprint();
	void StopSprint();


	UPROPERTY()
		AGun* Gun;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float RotationRate = 10;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float SprintModifier = 1.75;
	UPROPERTY(EditDefaultsOnly, Category = "Weapons")
		TSubclassOf<AGun> GunClass;
	UPROPERTY(EditDefaultsOnly, Category = "Health")
		float MaxHealth = 100;
	UPROPERTY(VisibleAnywhere, Category = "Health")
		float Health;
};