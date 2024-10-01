#pragma once

#include <memory>
#include <stdexcept>

#include "Framework.h"
#include "CustomSprite.h"
#include "RuntimeGameValues.h"
#include "DefaultGameValues.h"

class Collider;

enum class SpriteDirection
{
    Up,
    Right,
    Down,
    Left
};

class GameObject
{
public:
    GameObject() : _x(0), _y(0){};
    virtual void Initialization(const char *path, int width, int height,
        int x = 0, int y = 0);
    virtual void GetCoordinates(int &x, int &y);
    virtual void SetCoordinates(int x, int y);
    virtual void Update();
    virtual bool CollisionHanler(std::shared_ptr<Collider> trigger, 
        std::shared_ptr<Collider> other);
    virtual void ReInit();
    virtual void GetSpriteSize(int& width, int& height) final;
protected:
    virtual void SpriteDraw() final;
    virtual void ChangeSprite(const char *path, int width = 0, 
        int height = 0) final;
    virtual void SetSpriteSize(int width, int height) final;
private:
    std::unique_ptr<CustomSprite> _sprite;
    int _x;
    int _y;
};