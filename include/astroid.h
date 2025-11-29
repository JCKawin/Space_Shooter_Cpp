#pragma once 
#include <iostream>
#include <raylib.h>
#include "settings.h"

class Rock{
public:
    Rock();
    void update();
    ~
    Rock();
protected:
    Texture2D *image;
    Vector2 rect;
    Vector2 direction;
    float angle;
};