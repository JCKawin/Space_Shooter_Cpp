#pragma once

#include <stdlib.h>
#include "astroid.h"
#include "Ship.h"
#include "bullet.h"
#include <chrono>
#include "settings.h"
#include <vector>

class BaseLevel{
public:
    BaseLevel();
    void loadAsserts();
    int run();
    void gameOver();

    ~
    BaseLevel();
protected:
    void damage();
    void heal();
    void UI();
    void reset();

public:
    std::chrono::high_resolution_clock Clock;
    std::vector<Rock> Rocks;
    std::vector<Bullet> bullets;
    bool running;
    int score ;
    Color HealthBarCol;
    std::chrono::_V2::system_clock::time_point startCol;

protected:
    Texture2D background;
    Texture2D bulletImg;
    Texture2D rockImg;
    Sound shootEff;
    Sound rockExpEff;
    Sound rockImpact;
    Sound shipHealEff;
    Font Fuwl360;
    Font Fuwl30;
    Music bgm;
    BaseShip ship;
};