#pragma once

#include <memory>

#include "GameObject.h"
#include "ColliderTag.h"

class Collider
{
public:
    Collider() : _xRelaitive(0), _yRelaitive(0), IsTrigger(false), 
        Tag(ColliderTag::Unknown), _priority(10) {};
    virtual void Initialization(std::shared_ptr<GameObject> parentGameObject,
        ColliderTag colliderTag, int priority, int xRelaitive, int yRelaitive, 
        bool isTrigger);
    //true for deleting other and false if not
    virtual bool CollisionHappened(std::shared_ptr<Collider> other) final;
    virtual int GetPriority() final;
    virtual void GetCoordinates(int &xRelaitive, int &yRelaitive) final;

    std::weak_ptr<GameObject> ParentGameObject;
    ColliderTag Tag;
    bool IsTrigger;
private:
    int _priority;
    int _xRelaitive;
    int _yRelaitive;
};