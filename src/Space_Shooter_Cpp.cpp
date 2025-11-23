// Space_Shooter_Cpp.cpp : Defines the entry point for the application.
//

#include "Space_Shooter_Cpp.h"
#include "raylib.h"
#include "Ship.h"

int main()
{
	// Initialize
	InitWindow(1280, 720, "Space Shooter");
	InitAudioDevice();

	//global stuffs
	Music bgm  = LoadMusicStream("/home/jckawin/Space_Shooter_Cpp/media/audio/Project_Space Shooter_Final_Loop.mp3");
	Texture2D background = LoadTexture("/home/jckawin/Space_Shooter_Cpp/media/img/proto#background.bmp");
	auto ship = BaseShip();
	
	//non loop starters
	PlayMusicStream(bgm);
	
	while (!WindowShouldClose()) {
		UpdateMusicStream(bgm);
		BeginDrawing();

		ClearBackground(SKYBLUE);
		DrawTexture(background , 0 , 0 , WHITE);
		DrawTextureEx(ship.get_image() , ship.get_rect(),0,0.15f,WHITE);
		DrawFPS(20 , 20);


		EndDrawing();

		ship.update();
	}
	UnloadMusicStream(bgm);
	return 0;
}
