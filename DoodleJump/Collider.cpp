#include "Collider.h"

void Collider::Initialization(std::shared_ptr<GameObject> parentGameObject,
        ColliderTag colliderTag, int priority, int xRelaitive, int yRelaitive, 
        bool isTrigger)
{
    this->ParentGameObject = parentGameObject;
    this->Tag = colliderTag;
    this->_priority = priority;
    this->_xRelaitive = xRelaitive;
    this->_yRelaitive = yRelaitive;
    this->IsTrigger = isTrigger;
}

bool Collider::CollisionHappened(std::shared_ptr<Collider> other)
{
    return this->ParentGameObject.lock()->CollisionHanler(
        std::make_shared<Collider>(*this), other);
}

int Collider::GetPriority()
{
    return this->_priority;
}

void Collider::GetCoordinates(int &xRelaitive, int &yRelaitive)
{
    int x, y;

    this->ParentGameObject.lock()->GetCoordinates(x, y);

    xRelaitive = this->_xRelaitive + x;
    yRelaitive = this->_yRelaitive + y;
}