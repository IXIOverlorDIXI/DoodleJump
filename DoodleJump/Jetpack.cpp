#include "Jetpack.h"

void Jetpack::Initialization(const char* path, int width, int height, 
	int x, int y)
{
	GameObject::Initialization(path, width, height, x, y);

	this->_collider = std::make_shared<RectangleCollider>();
	this->_collider->Initialization(shared_from_this(),
		ColliderTag::Ability, DGV::EnemyBodyColliderPriority,
		DGV::Collider::Ability::CurrentXIndent,
		DGV::Collider::Ability::CurrentYIndent,
		DGV::Collider::Ability::CurrentWidth,
		DGV::Collider::Ability::CurrentHeight, true);
}