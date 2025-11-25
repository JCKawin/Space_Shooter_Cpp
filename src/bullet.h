#pragma once
#include <raylib.h>

class Bullet
{
private:
Vector2 velocity;

public:
    Vector2 rect;
    Texture2D image;
    bool active = 0;
    Bullet(Vector2 pos , Texture2D image);
    void update();
    void set_pos(Vector2 position);
    ~
    Bullet();
};


