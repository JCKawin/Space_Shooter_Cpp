#pragma once 
#include <iostream>
#include <raylib.h>
#include "settings.h"

class Rock{
public:
    Rock(Vector2 location , Texture2D &image);
    void update(float dt);
    void draw();
    Texture2D get_image();
    Vector2 get_rect();
    ~
    Rock();
protected:
    Texture2D *image;
    Vector2 rect;
    Vector2 direction;
    float angle;
};