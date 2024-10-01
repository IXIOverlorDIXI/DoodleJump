#include "CollisionService.h"

void CollisionService::ReInit()
{
    this->_colliders.clear();
}

void CollisionService::SearchingCollision()
{
    auto outerCycle = this->_colliders.begin();

    while (outerCycle != this->_colliders.end())
    {
        auto innerCycle = this->_colliders.begin();
        if (!(*outerCycle)->IsTrigger)
        {
            ++outerCycle;

            continue;
        }
        bool collisionResult = false;

        while (innerCycle != this->_colliders.end())
        {
            if ((*outerCycle).get() == (*innerCycle).get())
            {
                ++innerCycle;

                    continue;
            }

            auto colliderA = std::dynamic_pointer_cast<RC>(*outerCycle);
            auto colliderB = std::dynamic_pointer_cast<RC>(*innerCycle);
            if (colliderA && colliderB)
            {
                collisionResult = collisionCheck(colliderA, colliderB);
            }
            else
            {
                auto circleColliderA = std::dynamic_pointer_cast<CC>(*outerCycle);
                auto circleColliderB = std::dynamic_pointer_cast<CC>(*innerCycle);

                if (circleColliderA && circleColliderB)
                {
                    collisionResult = collisionCheck(circleColliderA, circleColliderB);
                }
                else
                {
                    auto rectangleColliderA = std::dynamic_pointer_cast<RC>(*outerCycle);
                    auto circleColliderB = std::dynamic_pointer_cast<CC>(*innerCycle);

                    if (rectangleColliderA && circleColliderB)
                    {
                        collisionResult = collisionCheck(rectangleColliderA, circleColliderB);
                    }
                    else
                    {
                        auto circleColliderA = std::dynamic_pointer_cast<CC>(*outerCycle);
                        auto rectangleColliderB = std::dynamic_pointer_cast<RC>(*innerCycle);

                        if (circleColliderA && rectangleColliderB)
                        {
                            collisionResult = collisionCheck(circleColliderA, rectangleColliderB);
                        }
                        else
                        {
                            throw std::exception("Unknown collider type");
                        }
                    }
                }
            }

            if (collisionResult)
            {
                collisionResult = (*outerCycle)->CollisionHappened(*innerCycle);

                if (collisionResult)
                {
                    innerCycle = this->_colliders.erase(innerCycle);
                    outerCycle = innerCycle;
                }
            }

            if (!collisionResult)
            {
                ++innerCycle;
            }
        }
        ++outerCycle;
    }
}

void CollisionService::AddCollider(std::shared_ptr<Collider> collider)
{
    auto insertPosition = std::upper_bound(
        this->_colliders.begin(),
        this->_colliders.end(), collider,
        [](const std::shared_ptr<Collider> &lhs,
           const std::shared_ptr<Collider> &rhs)
        {
            return lhs->GetPriority() < rhs->GetPriority();
        });

    this->_colliders.insert(insertPosition, collider);
}

void CollisionService::RemoveCollider(std::shared_ptr<Collider> collider)
{
    if (this->_colliders.empty())
    {
        return;
    }

    this->_colliders.erase(std::remove_if(
        this->_colliders.begin(),
        this->_colliders.end(),
        [&collider](const std::shared_ptr<Collider>& ptr) {
            return ptr == collider;
        }), this->_colliders.end());
}

bool CollisionService::collisionCheck(SRC collider_a, SRC collider_b)
{
    int xA, yA, wA, hA, xB, yB, wB, hB;

    collider_a->GetCoordinates(xA, yA);
    collider_a->GetSize(wA, hA);

    collider_b->GetCoordinates(xB, yB);
    collider_b->GetSize(wB, hB);

    return xA + wA >= xB &&
             xA <= xB + wB &&
             yA + hA >= yB &&
             yA <= yB + hB;
}

bool CollisionService::collisionCheck(SRC collider_a, SCC collider_b)
{
    int xA, yA, wA, hA, xB, yB, rB;

    collider_a->GetCoordinates(xA, yA);
    collider_a->GetSize(wA, hA);

    collider_b->GetCoordinates(xB, yB);
    collider_b->GetRadius(rB);

    float testPointX = xB;
    float testPointY = yB;

    if (xB < xA)
    {
        testPointX = xA;
    }
    else if (xB > xA + wA)
    {
        testPointX = xA + wA;
    }

    if (yB < yA)
    {
        testPointY = yA;
    }
    else if (yB > yA + hA)
    {
        testPointY = yA + hA;
    }

    float distanceX = xB - testPointX;
    float distanceY = yB - testPointY;
    float distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));

    return distance <= rB;
}

bool CollisionService::collisionCheck(SCC collider_a, SRC collider_b)
{
    return collisionCheck(collider_b, collider_a);
}

bool CollisionService::collisionCheck(SCC collider_a, SCC collider_b)
{
    int xA, yA, rA, xB, yB, rB;

    collider_a->GetCoordinates(xA, yA);
    collider_a->GetRadius(rA);

    collider_a->GetCoordinates(xB, yB);
    collider_a->GetRadius(rB);

    float distanceX = xA - xB;
    float distanceY = yA - yB;
    float distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));

    return distance <= rA + rB;
}

CollisionService::~CollisionService()
{
    this->_colliders.clear();
}