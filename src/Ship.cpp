#include "Ship.h"

BaseShip::BaseShip(){

    image = LoadTexture("/home/jckawin/Space_Shooter_Cpp/media/img/proto#ship.png");
    rect.x = 640;
    rect.y = 360;
    velocity = 0.1f;
}

Texture2D BaseShip::get_image(){
    return image;
}

Vector2 BaseShip::get_rect(){
    return rect;
}

void BaseShip::update(){
    Vector2 direction;
    direction.x = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * velocity;
    direction.y = (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * velocity;
    
    rect.x += direction.x;rect.y += direction.y;
    

}

BaseShip::~BaseShip(){
    UnloadTexture(BaseShip::image);
}



