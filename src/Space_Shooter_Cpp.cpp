// Space_Shooter_Cpp.cpp : Defines the entry point for the application.
//

#include "Space_Shooter_Cpp.h"
#include "raylib.h"
#include "Ship.h"
#include "bullet.h"
#include <vector>
#include <algorithm>

void SpawnBullet(std::vector<Bullet> &bullets ,Texture2D &img ,  Vector2 pos){
	const Bullet bullet = Bullet(pos , img);
	bullets.push_back(bullet);
	
}

int main()
{
	// Initialize
	InitWindow(1280, 720, "Space Shooter");
	InitAudioDevice();

	//global stuffs
	Music bgm  = LoadMusicStream("/home/jckawin/Space_Shooter_Cpp/media/audio/Project_Space Shooter_Final_Loop.mp3");
	Texture2D background = LoadTexture("/home/jckawin/Space_Shooter_Cpp/media/img/proto#background.bmp");
	Texture2D bullet_img = LoadTexture("/home/jckawin/Space_Shooter_Cpp/media/img/proto#bullet.png");
	auto ship = BaseShip();
	std::vector<Bullet> bullets ;
	 
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
		if(KEY_J){
			SpawnBullet(bullets , bullet_img ,  ship.get_rect());
		}

		for(auto & bullet : bullets){
			DrawTextureEx(bullet.image, bullet.rect , 0 , 1 , WHITE);
			bullet.update();
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
