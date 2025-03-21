// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP2_Dev_AvanceGameMode.h"
#include "TP2_Dev_AvanceCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATP2_Dev_AvanceGameMode::ATP2_Dev_AvanceGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
