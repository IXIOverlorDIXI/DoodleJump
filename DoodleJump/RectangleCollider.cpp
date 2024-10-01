#include "CollisionService.h"

void RectangleCollider::Initialization(
    std::shared_ptr<GameObject> parentGameObject,
    ColliderTag colliderTag, int priority, int xRelaitive, int yRelaitive, 
    int width, int height, bool isTrigger)
{
    Collider::Initialization(parentGameObject, colliderTag, priority,
        xRelaitive, yRelaitive, isTrigger);

    this->_width = width;
    this->_height = height;        

    std::shared_ptr<Collider> ptr = shared_from_this();

    CollisionService::GetInstance().AddCollider(ptr);
}

void RectangleCollider::GetSize(int &widht, int &height)
{
    widht = this->_width;
    height = this->_height;
}