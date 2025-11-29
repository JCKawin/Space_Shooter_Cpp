// 
// This is the file for the bullet class implementation.
//


#include "bullet.h"
#include <iostream>

Bullet::Bullet(Vector2 pos , Texture2D &img)
{
    set_pos(pos);
    image = &img;
}

Bullet::~Bullet()
{
}

void Bullet::set_pos(Vector2 position)
{
    rect.x = position.x + 58;
    rect.y = position.y - 55;
}

Texture2D Bullet::get_image(){
    return *image;
}

void Bullet::draw(){
    DrawTextureEx(*image , rect , 0 , 0.1f , WHITE);
}

Vector2 Bullet::get_rect(){
    return rect;
}




void Bullet::update(float dt){
    
   rect.y -= Game::BulletSpeed * dt * 10;

}