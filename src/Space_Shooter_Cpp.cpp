// Space_Shooter_Cpp.cpp : Defines the entry point for the application.
//

#include "Space_Shooter_Cpp.h"
#include "raylib.h"
#include "Ship.h"
#include "bullet.h"
#include <vector>
#include <algorithm>
#include "settings.h"
#include "levels.h"


int main()
{
	// Initialize
	InitWindow(Game::ScreenWidth , Game::ScreenHeight, "Space Shooter");
	InitAudioDevice();
	BaseLevel level1;
	int gameState = 0;
	
	while(!WindowShouldClose()){
		switch (gameState)
		{
		case 0:
			gameState = level1.run();
			break;
		
		default:
			break;
		}

	}
	
	return 0;
}
