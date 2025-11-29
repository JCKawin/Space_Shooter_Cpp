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
}

void BaseLevel::damage(){
    for(int i = 0 ; i < Rocks.size() ; i ++) {
        if (CheckMaskCollision(ship.get_image() , ship.get_rect() , Rocks[i].get_image() , Rocks[i].get_rect())){
            ship.Hp -= 5;
            HealthBarCol = RED;
            startCol = std::chrono::high_resolution_clock::now();
            Rocks.erase(Rocks.begin() + i);
            i --;
        }
    }
    for(int i = 0 ; i < Rocks.size() ; i ++){
        for (int j = 0 ; j < Rocks.size() ; j++){
            if(CheckMaskCollision(bullets[i].get_image() , bullets[i].get_rect() , Rocks[j].get_image() , Rocks[j].get_rect())){

            }
        }
    }

}

bool CheckMaskCollision(Texture2D imgAt, Vector2 posA, Texture2D imgBt, Vector2 posB) {
    auto imgA = LoadImageFromTexture(imgAt);
    auto imgB = LoadImageFromTexture(imgBt);
    Rectangle rectA = { posA.x, posA.y, (float)imgA.width, (float)imgA.height };
    Rectangle rectB = { posB.x, posB.y, (float)imgB.width, (float)imgB.height };

    if (!CheckCollisionRecs(rectA, rectB)) return false;

    float overlapX = fmaxf(rectA.x, rectB.x);
    float overlapY = fmaxf(rectA.y, rectB.y);
    float overlapW = fminf(rectA.x + rectA.width, rectB.x + rectB.width) - overlapX;
    float overlapH = fminf(rectA.y + rectA.height, rectB.y + rectB.height) - overlapY;

    if (overlapW <= 0 || overlapH <= 0) return false;

    Color *pixelsA = LoadImageColors(imgA);
    Color *pixelsB = LoadImageColors(imgB);

    for (int y = 0; y < (int)overlapH; y++) {
        for (int x = 0; x < (int)overlapW; x++) {
            int ax = (int)(overlapX - rectA.x) + x;
            int ay = (int)(overlapY - rectA.y) + y;
            int bx = (int)(overlapX - rectB.x) + x;
            int by = (int)(overlapY - rectB.y) + y;

            Color ca = pixelsA[ay * imgA.width + ax];
            Color cb = pixelsB[by * imgB.width + bx];

            if (ca.a > 0 && cb.a > 0) {
                UnloadImageColors(pixelsA);
                UnloadImageColors(pixelsB);
                return true;
            }
        }
    }

    UnloadImageColors(pixelsA);
    UnloadImageColors(pixelsB);
    return false;
}






BaseLevel::~BaseLevel(){}