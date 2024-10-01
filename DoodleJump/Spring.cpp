#include "Spring.h"

void Spring::Initialization(const char* path, int width, int height,
	std::shared_ptr<Collider> collider, float jumpModifier, int x, int y)
{
	GameObject::Initialization(path, width, height, x, y);

	this->JumpModifier = jumpModifier;
	this->_collider = collider;
}

Spring::~Spring()
{
	CollisionService::GetInstance().RemoveCollider(this->_collider);
}