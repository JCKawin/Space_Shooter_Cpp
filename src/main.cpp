//
// Created by KAWIN on 11/7/2025.
//

#include <iostream>
#include "raylib.h"
#include "constants.cpp"

class Game
{

public:
 Game()
 {
    InitWindow(RES[0] , RES[1] , "Space_Shooter");

 }

 void run(){
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(SKYBLUE);

        EndDrawing();
    }
    


 }

 ~Game()
 {
    CloseWindow();
 }
  
};




int main() {
    Game* player = new Game();
    player->run();
    delete player; 
    return 0;

}