#pragma once

#include "GameObject.h"

void GameObject::Initialization(const char *path, int width, int height,
                                int x, int y)
{
    if (_sprite.get() == nullptr)
    {
        _sprite = std::make_unique<CustomSprite>();
    }

    this->_sprite->SetSprite(path);
    this->_sprite->SetSpriteSize(width, height);

    this->_x = x;
    this->_y = y;
}

void GameObject::GetCoordinates(int &x, int &y)
{
    x = this->_x;
    y = this->_y;
}

void GameObject::SetCoordinates(int x, int y)
{
    this->_x = x;
    this->_y = y;
}

void GameObject::Update()
{
    SpriteDraw();
}

void GameObject::ReInit()
{
    return;
}

void GameObject::SpriteDraw()
{
    if (_sprite.get() == nullptr)
    {
        throw new std::runtime_error("Sprite does not exist");
    }

    this->_sprite->DrawSprite(this->_x, this->_y);
}

bool GameObject::CollisionHanler(std::shared_ptr<Collider> trigger,
    std::shared_ptr<Collider> other)
{
    return true;
}

void GameObject::ChangeSprite(const char *path, int width, int height)
{
    if (_sprite.get() == nullptr)
    {
        _sprite = std::make_unique<CustomSprite>();
    }

    this->_sprite->SetSprite(path);
    this->_sprite->SetSpriteSize(width, height);
}

void GameObject::SetSpriteSize(int width, int height)
{
    if (_sprite.get() == nullptr)
    {
        throw new std::runtime_error("Sprite does not exist");
    }

    this->_sprite->SetSpriteSize(width, height);
}

void GameObject::GetSpriteSize(int &width, int &height)
{
    if (_sprite.get() == nullptr)
    {
        throw new std::runtime_error("Sprite does not exist");
    }

    this->_sprite->GetSpriteSize(width, height);
}