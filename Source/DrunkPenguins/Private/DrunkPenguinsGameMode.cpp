// Copyright Epic Games, Inc. All Rights Reserved.

#include "DrunkPenguinsGameMode.h"
#include "DrunkPenguinsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADrunkPenguinsGameMode::ADrunkPenguinsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_DrunkPenguin"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
