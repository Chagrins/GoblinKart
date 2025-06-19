// Fill out your copyright notice in the Description page of Project Settings.


#include "WobblyMovementComponent.h"

void UWobblyMovementComponent::ToggleSprint(bool bSprint)
{
    bIsSprinting = bSprint;
}

void UWobblyMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
    Super::OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity);

    if (MovementMode == MOVE_Walking)
    {
        if (bIsSprinting)
        {
            MaxWalkSpeed = SprintMaxSpeed;
        }
        else
        {
            MaxWalkSpeed = WalkMaxSpeed;
        }

        FVector ForwardVelocity = FVector(Velocity.X, Velocity.Y, 0.f);
        float ForwardSpeed = FMath::Abs(ForwardVelocity.Length());
        if (!FMath::IsNearlyZero(ForwardSpeed))
        {
            float StartSpeed = ForwardSpeed;
            float EndSpeed = MaxWalkSpeed;
            float StartRotationRate = IdleRotationRate;
            float EndRotationRate = WalkMaxRotationRate;
            // We're either going up to or coming back down from the sprinting speed.
            if (ForwardSpeed > WalkMaxSpeed)
            {
                StartSpeed -= WalkMaxSpeed;
                EndSpeed -= WalkMaxSpeed;
                StartRotationRate = WalkMaxRotationRate;
                EndRotationRate = SprintMaxRotationRate;
            }
            float MaxSpeedDelta = ForwardSpeed / MaxWalkSpeed;
            float RotationRateDelta = EndRotationRate - StartRotationRate;
            float AdjustedRotationRate = StartRotationRate + (RotationRateDelta * MaxSpeedDelta);
            RotationRate = FRotator(0.f, AdjustedRotationRate, 0.f);
        }
        else
        {
            RotationRate = FRotator(0.f, IdleRotationRate, 0.f);
        }
    }
}