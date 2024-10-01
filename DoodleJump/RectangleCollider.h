#pragma once

#include "Collider.h"

#define SRC std::shared_ptr<RectangleCollider>
#define RC RectangleCollider

class RectangleCollider : public Collider, public std::enable_shared_from_this<RectangleCollider>
{
public:
    RectangleCollider() : _width(0), _height(0), Collider() {};
    virtual void Initialization(std::shared_ptr<GameObject> parentGameObject,
        ColliderTag colliderTag, int priority, int xRelaitive, int yRelaitive,
        int width, int height, bool isTrigger);
    virtual void GetSize(int& widht, int& height);
private:
    int _width;
    int _height;
};