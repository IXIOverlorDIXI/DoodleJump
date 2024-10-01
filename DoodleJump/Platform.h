#pragma once

#include "GameObject.h"
#include "CollisionService.h"

class Platform : public GameObject, public std::enable_shared_from_this<Platform>
{
public:
    Platform() : IsJumpedOn(false), IsJumpedOver(false), 
        _leftTimeBeforeBlindMode(0){};
    virtual void Initialization(const char* path, int width, int height,
        int x = 0, int y = 0, std::shared_ptr<GameObject> entity = nullptr);
    virtual void Update() override;
    bool WithEntity();
    void EntityParameters(int &x, int &y, int &width, int &height);
    ~Platform();

    bool IsJumpedOn;
    bool IsJumpedOver;
private:
    int _leftTimeBeforeBlindMode;
    std::weak_ptr<GameObject> _entityOnPlatform;
	std::shared_ptr<RectangleCollider> _platformCollider;
};