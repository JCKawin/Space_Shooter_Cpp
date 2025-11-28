// Space_Shooter_Cpp.cpp : Defines the entry point for the application.
//

#include "Space_Shooter_Cpp.h"
#include "raylib.h"
#include "Ship.h"
#include "bullet.h"
#include <vector>
#include <algorithm>


int main()
{
	// Initialize
	InitWindow(1280, 720, "Space Shooter");
	InitAudioDevice();

	//global stuffs
	Music bgm  = LoadMusicStream("../media/audio/Project_Space Shooter_Final_Loop.mp3");
	Texture2D background = LoadTexture("../media/img/proto#background.bmp");
	Texture2D bullet_img = LoadTexture("../media/img/proto#bullet.png");
	auto ship = BaseShip();
	std::vector<Bullet> bullets ;
	 
	//non loop starters
	PlayMusicStream(bgm);
	
	
	while (!WindowShouldClose()) {
		float dt = (float) GetFrameTime();
		UpdateMusicStream(bgm);
		BeginDrawing();

		ClearBackground(SKYBLUE);
		DrawTexture(background , 0 , 0 , WHITE);
		DrawTextureEx(ship.get_image() , ship.get_rect(),0,0.15f,WHITE);
		DrawFPS(20 , 20);
		
		for(int i ; i < bullets.size() ; i ++){
			DrawTextureEx(bullets[i].image, (Vector2) {800 , 200} , 0 , 1 , WHITE);
			// bullets[i].update(dt);
		}


		EndDrawing();

		ship.update(dt);
		if(IsKeyDown(KEY_J)){
			Bullet bullet(ship.get_rect() , bullet_img); 
			bullets.push_back(bullet);
		}

		bullets.erase(
            std::remove_if(bullets.begin(), bullets.end(),
                [](const Bullet& b) { return !b.active; }),
            bullets.end()
        );

	}
	UnloadMusicStream(bgm);
	return 0;
}
