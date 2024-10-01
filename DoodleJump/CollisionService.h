#pragma once

#include <vector>
#include <memory>
#include <stdexcept>

#include "RectangleCollider.h"
#include "CircleCollider.h"

class CollisionService
{
public:
    static CollisionService& GetInstance() {
        static CollisionService instance;
        return instance;
    }

    void SearchingCollision();
    void AddCollider(std::shared_ptr<Collider> collider);
    void RemoveCollider(std::shared_ptr<Collider> collider);
    void ReInit();
    ~CollisionService();
private:
    CollisionService() {}
    CollisionService(const CollisionService&) = delete;
    void operator=(const CollisionService&) = delete;

    bool collisionCheck(SRC collider_a, SRC collider_b);
    bool collisionCheck(SRC collider_a, SCC collider_b);
    bool collisionCheck(SCC collider_a, SRC collider_b);
    bool collisionCheck(SCC collider_a, SCC collider_b);

    std::vector<std::shared_ptr<Collider>> _colliders;
};