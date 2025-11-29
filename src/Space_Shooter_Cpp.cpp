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
	std::vector<Vector2> bullets ;
	 
	//non loop starters
	PlayMusicStream(bgm);
	// SetTargetFPS(144);
	
	
	while (!WindowShouldClose()) {
		float dt = (float) GetFrameTime();
		UpdateMusicStream(bgm);
		BeginDrawing();

		ClearBackground(SKYBLUE);
		DrawTexture(background , 0 , 0 , WHITE);
		DrawTextureEx(ship.get_image() , ship.get_rect(),0,0.15f,WHITE);
		DrawFPS(20 , 20);
		
		for(auto bullet : bullets){
			DrawTextureEx(bullet_img, bullet , 0 , 0.1f , WHITE);
		}

		EndDrawing();

		ship.update(dt);

		for (auto & bullet : bullets){
			 bullet.y -= 1000.0f * dt;
		}

		if(IsKeyPressed(KEY_J)){ 
			bullets.push_back((Vector2){ship.get_rect().x + 58, ship.get_rect().y - 55});
			// std::cout << "bullet \n";
			// for (auto & bullet : bullets){
			// 	std::cout << "X=" << bullet.x << " Y=" << bullet.y << std::endl;
			// }
		}

		auto ne = remove_if(bullets.begin() , bullets.end() , [](Vector2 x){return x.y <= -80;});
		bullets.erase(ne,bullets.end());

	}
	UnloadMusicStream(bgm);
	return 0;
}
