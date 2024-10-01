#pragma once

#include <memory>
#include <algorithm>
#include <cmath>
#include <iostream>

#include "GameObject.h"
#include "CollisionService.h"
#include "Platform.h"
#include "PlatformService.h"
#include "EnemyService.h"
#include "BulletService.h"
#include "AbilityService.h"

class Doodle : public GameObject, public std::enable_shared_from_this<Doodle>
{
public:
    Doodle() : _xMovingNormal(0), _yMovingNormal(0),
        _jumpVelocityModifier(100), _leftJumpDistance(0),
        _spriteDirection(SpriteDirection::Right), _leftFlyTime(0){};
    void Initialization(const char* path, int width, int height,
        int x = 0, int y = 0) override;
    void Update() override;
    virtual void ReInit() override;
    void SetCoordinates(int x, int y) override;
    bool CollisionHanler(std::shared_ptr<Collider> trigger,
        std::shared_ptr<Collider> other) override;
    void Death();
protected:
    void ControlInput();
    void HorisontalMovement();
    void VerticalMovement();
    void Shoot();
private:
    SpriteDirection _spriteDirection;
    float _xMovingNormal;
    float _yMovingNormal;
    int _jumpVelocityModifier;
    int _leftJumpDistance;
    int _leftFlyTime;
    std::weak_ptr<Platform> _lastJumpedOnPlatform;
    std::shared_ptr<RectangleCollider> _feetCollider;
    std::shared_ptr<RectangleCollider> _bodyCollider;
};