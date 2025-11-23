// Space_Shooter_Cpp.cpp : Defines the entry point for the application.
//

#include "Space_Shooter_Cpp.h"
#include "raylib.h"
#include "Ship.h"

int main()
{
	InitWindow(1280, 720, "Space Shooter");
	auto ship = BaseShip();
	InitAudioDevice();
	Music bgm  = LoadMusicStream("../media/audio/Project_Space Shooter_Final_Loop.mp3");
	PlayMusicStream(bgm);
	Texture2D background = LoadTexture("/home/jckawin/Space_Shooter_Cpp/media/img/proto#background.bmp");

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(SKYBLUE);
		DrawTexture(background , 0 , 0 , WHITE);
		DrawTextureEx(ship.get_image() , ship.get_rect(),0,0.15f,WHITE);


		EndDrawing();

		ship.update();
	}
	UnloadMusicStream(bgm);
	return 0;
}
