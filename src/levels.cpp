#include "levels.h"
#include "stdbool.h"
#include "stdlib.h"
#include "math.h"

BaseLevel::BaseLevel(){
    running = true;
    HealthBarCol = WHITE;
    score = 0;
    loadAsserts();
    startCol = std::chrono::high_resolution_clock::now();
}

 void BaseLevel::loadAsserts(){
    background = LoadTexture("../media/img/proto#background.bmp");
    bulletImg = LoadTexture("../media/img/proto#bullet.png");
    rockImg = LoadTexture("../media/img/proto#astroid.png");
    Fuwl30 = LoadFont("../media/font/UnwaveLover-PV9AZ.otf");
    Fuwl360 = LoadFont("../media/font/Unwavelover-PV9AZ.oft");
    bgm = LoadMusicStream("../media/audio/Project_Space Shooter_Final_Loop.mp3");
    shootEff = LoadSound("../media/audio/Space Shooter_Fire.mp3");
    rockExpEff = LoadSound("../media/audio/Space Shooter_Explosion.mp3");
    rockImpact = LoadSound("../media/audio/Space Shooter_Asteroid Impact.mp3");
    shipHealEff = LoadSound("../media/audio/Space Shooter_Healing.mp3");
}

int BaseLevel::run(){
    while (!WindowShouldClose() && running)
    {   BeginDrawing();
        ClearBackground(Game::BgCol);
        DrawTexture(background , 0 , 0 , WHITE);
        ship.draw();
        for(auto & bullet : bullets) bullet.draw();
        for(auto & rock : Rocks) rock.draw();
        EndDrawing();
        float dt = GetFrameTime();
        for(auto & bullet : bullets) bullet.update(dt);
        for(auto & rock : Rocks) rock.update(dt);
        damage();
    }

    return 0;
}

void BaseLevel::damage(){
    for(int i = 0 ; i < Rocks.size() ; i ++) {
        if (Game::CheckMaskCollision(ship.get_image() , ship.get_rect() , Rocks[i].get_image() , Rocks[i].get_rect())){
            ship.Hp -= 5;
            HealthBarCol = RED;
            startCol = std::chrono::high_resolution_clock::now();
            Rocks.erase(Rocks.begin() + i);
            i --;
        }
    }
    for(int i = 0 ; i < Rocks.size() ; i ++){
        for (int j = 0 ; j < Rocks.size() ; j++){
            if(Game::CheckMaskCollision(bullets[i].get_image() , bullets[i].get_rect() , Rocks[j].get_image() , Rocks[j].get_rect())){

            }
        }
    }

}







BaseLevel::~BaseLevel(){}