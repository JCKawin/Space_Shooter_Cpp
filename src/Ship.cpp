#include "Ship.h"

BaseShip::BaseShip(){

    image = LoadTexture("/home/jckawin/Space_Shooter_Cpp/media/img/proto#ship.png");
    rect.x = 640;
    rect.y = 360;
    velocity = 1000.0f;
    Hp = 100;
}

Texture2D BaseShip::get_image(){
    return image;
}

Vector2 BaseShip::get_rect(){
    return rect;
}

void BaseShip::update(float dt){
    Vector2 direction;
    direction.x = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * velocity;
    direction.y = (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * velocity;
    
    rect.x += direction.x * dt;rect.y += direction.y * dt;

    if(rect.x < -128) rect.x =  1280;
    if(rect.y > 720)  rect.y = -128;
    if(rect.x > 1280) rect.x = -128;
    if(rect.y < -128) rect.y =  720;
    

}

void BaseShip::draw(){
    DrawTextureEx(image , rect , 0 , 0.15f , WHITE);
}

BaseShip::~BaseShip(){
    UnloadTexture(BaseShip::image);
}



