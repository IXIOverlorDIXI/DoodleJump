#include "CollisionService.h"

void CircleCollider::Initialization(
    std::shared_ptr<GameObject> parentGameObject,
    ColliderTag colliderTag, int priority, int xRelaitive, int yRelaitive, 
    int radius, bool isTrigger
)
{
    Collider::Initialization(parentGameObject, colliderTag, priority, 
        xRelaitive,yRelaitive, isTrigger);
    
    this->_radius = radius;

    std::shared_ptr<Collider> ptr = shared_from_this();

    CollisionService::GetInstance().AddCollider(ptr);
}

void CircleCollider::GetRadius(int &radius)
{
    radius = this->_radius;
}