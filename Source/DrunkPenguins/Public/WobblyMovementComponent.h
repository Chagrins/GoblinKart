// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "WobblyMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class UWobblyMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float SprintMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float WalkMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Wobbly, meta = (AllowPrivateAccess = "true"))
	float IdleRotationRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Wobbly, meta = (AllowPrivateAccess = "true"))
	float WalkMaxRotationRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Wobbly, meta = (AllowPrivateAccess = "true"))
	float SprintMaxRotationRate;

private:

	bool bIsSprinting;

	void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;

public:

	UFUNCTION(BlueprintCallable)
	void ToggleSprint(bool bSprint);
};
