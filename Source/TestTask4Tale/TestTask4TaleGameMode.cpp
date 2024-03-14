// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestTask4TaleGameMode.h"
#include "TestTask4TaleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestTask4TaleGameMode::ATestTask4TaleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
