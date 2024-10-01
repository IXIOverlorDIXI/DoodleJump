#pragma once

#include "Collider.h"

#define SCC std::shared_ptr<CircleCollider>
#define CC CircleCollider

class CircleCollider : public Collider, public std::enable_shared_from_this<CircleCollider>
{
public:
    CircleCollider() : _radius(0), Collider() {};
    virtual void Initialization(std::shared_ptr<GameObject> parentGameObject,
        ColliderTag colliderTag, int priority, int xRelaitive, int yRelaitive,
        int radius, bool isTrigger);
    virtual void GetRadius(int& radius);
private:
    int _radius;
};