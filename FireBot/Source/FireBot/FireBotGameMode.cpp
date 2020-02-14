// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#include "FireBotGameMode.h"
#include "FireBotCharacter.h"

AFireBotGameMode::AFireBotGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
