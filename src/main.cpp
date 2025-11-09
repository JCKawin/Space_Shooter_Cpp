//
// Created by KAWIN on 11/7/2025.
//

#include <iostream>
#include <raylib.h>
#include "constants.cpp"
int RES_w = 1920;
int RES_h = 1080;
class Game
{

public:
 Game()
 {
    InitWindow(RES_w , RES_h , "Space_Shooter");

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
    Game player = Game();
    player.run();
 
    return 0;

}