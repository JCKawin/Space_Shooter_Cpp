// 
// This is the file for the bullet class implementation.
//


#include "bullet.h"
#include <iostream>

Bullet::Bullet(Vector2 pos , Texture2D img)
{
    set_pos(pos);
    image = LoadTexture("../media/img/proto#bullet.png");
    active = true;
    std::cout << "Bullet";
}

Bullet::~Bullet()
{
}

void Bullet::set_pos(Vector2 position)
{
    // rect.x = position.x + 64;
    // rect.y = position.y;

    rect.x = 300 ; rect.y = 300;
}

Texture2D Bullet::get_image(){
    return image;
}





void Bullet::update(float dt){
    
    rect.y -= velocity.y * dt;
    if (rect.y < -50){
        active = false;
    }

}