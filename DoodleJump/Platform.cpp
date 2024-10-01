#include "Platform.h"

void Platform::Initialization(const char* path, int width, int height,
    int x, int y, std::shared_ptr<GameObject> entity)
{
    GameObject::Initialization(path, width, height, x, y);

    this->_entityOnPlatform = entity;
    this->_leftTimeBeforeBlindMode = DGV::Game::BlindModeTimer;

    this->_platformCollider = std::make_shared<RectangleCollider>();
    this->_platformCollider->Initialization(shared_from_this(), ColliderTag::Platform,
        DGV::Collider::Priority::Platform, 
        DGV::Collider::Platform::CurrentXIndent, 
        DGV::Collider::Platform::CurrentYIndent,
        DGV::Collider::Platform::CurrentWidth, 
        DGV::Collider::Platform::CurrentHeight, false);
}

void Platform::Update()
{
    if (RGV::BlindMode)
    {
        int x, y, w, h;

        GetCoordinates(x, y);
        GetSpriteSize(w, h);

        if (y + h < 0 || y > DGV::Window::CurrentHeight)
        {
            return;
        }

        if (this->_leftTimeBeforeBlindMode > 0)
        {
            this->_leftTimeBeforeBlindMode -= RGV::LastTickDuration;
        }
        else
        {
            return;
        }
    }

    GameObject::Update();
}

bool Platform::WithEntity()
{
    return this->_entityOnPlatform.lock() != nullptr;
}

void Platform::EntityParameters(int &x, int &y, int &width, int &height)
{
    std::shared_ptr<GameObject> entity = this->_entityOnPlatform.lock();

    if (entity)
    {
        entity->GetCoordinates(x, y);
        entity->GetSpriteSize(width, height);
    }
}

Platform::~Platform()
{
    if (!IsJumpedOver && RGV::IsAlive)
    {
        RGV::PlayerPlatformJumpedOverCounter++;
    }

    CollisionService::GetInstance().RemoveCollider(this->_platformCollider);
}