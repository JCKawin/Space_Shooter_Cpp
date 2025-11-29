#pragma once
#include <raylib.h>


class BaseShip
{
private:
    Texture2D image;
    Vector2 rect;
    float velocity;
public:
    BaseShip();
    Texture2D get_image();
    Vector2 get_rect();
    void update(float dt);
    void draw();
    ~
    BaseShip();

public:
    int Hp;
};
