#include "astroid.h"
#include "raymath.h"

Rock::Rock(Vector2 location , Texture2D &img){
    image = &img;
    rect = location;
    direction = (Vector2) {(float)(std::rand()%2) + 1.0f , 1.0f};
    direction = Vector2Normalize(direction);
    angle = 0.0f;
}

void Rock::update(float dt){
    angle += 0.5 * dt;
    rect.x += direction.x * Game::AstroidSpeed * dt;
    rect.y += direction.y * Game::AstroidSpeed * dt;
}

void Rock::draw(){
    DrawTextureEx(*image , rect , angle , 0.15f , WHITE );
}

Texture2D Rock::get_image(){
    return *image;
}

Vector2 Rock::get_rect(){
    return rect;
}


Rock::~Rock(){}
