#pragma once

#include <stdexcept>

#include "Framework.h"
#include "DefaultGameSprites.h"

class CustomSprite
{
public:
    CustomSprite() : _sprite (nullptr), _width(0), _height(0) {};
    bool SetSprite(const char *path);
    void DrawSprite(int x, int y);
    void GetSpriteSize(int& w, int &h);
    void SetSpriteSize(int w, int h);
    ~CustomSprite();

private:
    Sprite *_sprite;
    int _width;
    int _height;
};