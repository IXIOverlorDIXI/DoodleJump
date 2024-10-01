#include "CustomSprite.h"

bool CustomSprite::SetSprite(const char *path)
{
    if(this->_sprite != nullptr)
    {
        destroySprite(this->_sprite);
    }

    this->_sprite = createSprite(path);

    return this->_sprite != nullptr;
}

void CustomSprite::DrawSprite(int x, int y)
{
    if(this->_sprite == nullptr)
    {
        throw new std::runtime_error("Sprite does not exist");
    }

    drawSprite(this->_sprite, x, y);
}

void CustomSprite::GetSpriteSize(int& w, int &h)
{
    w = this->_width;
    h = this->_height;
}

void CustomSprite::SetSpriteSize(int w, int h)
{
    this->_width = w;
    this->_height = h;

    setSpriteSize(this->_sprite, this->_width, this->_height);
}



CustomSprite::~CustomSprite()
{
    if(this->_sprite != nullptr)
    {
        destroySprite(this->_sprite);
    }
}