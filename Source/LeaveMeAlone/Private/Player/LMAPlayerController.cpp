// LeaveMeAlone Game By Netologiya. All Rights Reserved.


#include "Player/LMAPlayerController.h"

ALMAPlayerController::ALMAPlayerController() {}

void ALMAPlayerController::BeginPlay() 
{
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}
