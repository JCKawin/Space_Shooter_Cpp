#include "bullet.h"

Bullet::Bullet(Vector2 pos , Texture2D img)
{
    set_pos(pos);
    image = img;
    active = true;
}

Bullet::~Bullet()
{
}

void Bullet::set_pos(Vector2 position)
{
    rect.x = position.x + 64;
    rect.y = position.y;
}





void Bullet::update(float dt){
    
    rect.y -= velocity.y * dt;
    if (rect.y < -50){
        active = false;
    }

}