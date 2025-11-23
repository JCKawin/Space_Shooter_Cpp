// Space_Shooter_Cpp.cpp : Defines the entry point for the application.
//

#include "Space_Shooter_Cpp.h"
#include "raylib.h"
#include "Ship.h"
#include "bullet.h"


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
	Bullet *bullets = new Bullet[10];
	for (int i ; i < 10 ; i ++){
		bullets[i].rect = (Vector2) {-100 , -100};
	}
	int bno = 0; 
	
	while (!WindowShouldClose()) {
		UpdateMusicStream(bgm);
		BeginDrawing();

		ClearBackground(SKYBLUE);
		DrawTexture(background , 0 , 0 , WHITE);
		DrawTextureEx(ship.get_image() , ship.get_rect(),0,0.15f,WHITE);
		DrawFPS(20 , 20);


		EndDrawing();

		ship.update();
		if(KEY_J){
			bullets[bno].set_pos(ship.get_rect());
			bno++;
			if (bno > 9) bno = 0;
		}
		for(int i ; i < 10 ; i++){
			DrawTextureEx(bullets[i].image , bullets[i].rect , 0 , 1 , WHITE);
		}
	}
	UnloadMusicStream(bgm);
	return 0;
}
