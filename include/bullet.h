#pragma once
#include <raylib.h>
#include "settings.h"

class Bullet
{
private:
    Vector2 velocity;
    Texture2D *image;
    Vector2 rect;
public:
    Bullet(Vector2 pos , Texture2D &img);
    void update(float dt);
    void set_pos(Vector2 position);
    Texture2D get_image();
    Vector2 get_rect();
    void draw();
    ~
    Bullet();
};


