#include "bullet.h"

Bullet::Bullet()
{
    image = LoadTexture("/home/jckawin/Space_Shooter_Cpp/media/img/proto#bullet.png");
}

Bullet::~Bullet()
{
    UnloadTexture(image);
}

void Bullet::set_pos(Vector2 position)
{
    rect.x = position.x + 64;
    rect.y = position.y;
}





void Bullet::update(){
    
    rect.y -= velocity.y;

}