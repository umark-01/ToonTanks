// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
public:
	ATank();
	void HandleDestruction();
	bool bAlive = true;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(VisibleAnyWhere, 
			//BlueprintReadOnly, 
			Category = "Components",
			meta=(AllowPrivateAccess="true"));
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnyWhere, 
			//BlueprintReadOnly, 
			Category = "Components",
			meta=(AllowPrivateAccess="true"));
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 200.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 45.f;

	void Move(float Value);
	void Turn(float Value);

	APlayerController* TankPlayerController;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	APlayerController* GetTankPlayerController() const { return TankPlayerController; }
	
};
