// Copyright Epic Games, Inc. All Rights Reserved.

#include "CXXAIGameMode.h"
#include "CXXAICharacter.h"
#include "UObject/ConstructorHelpers.h"

ACXXAIGameMode::ACXXAIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
