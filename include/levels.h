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
    void LoadAsserts();
    int Run();
    void GameOver();

    ~
    BaseLevel();
protected:
    void damage();
    void heal();
    void UI();
    void reset();

public:
    std::chrono::high_resolution_clock Clock;
    std::vector<Rock> Rock;
    
};