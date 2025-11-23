#pragma once
#include <raylib.h>

class Bullet
{
private:
Vector2 velocity;

public:
    Vector2 rect;
    Texture2D image;
    Bullet();
    void update();
    void set_pos(Vector2 position);
    ~
    Bullet();
};


