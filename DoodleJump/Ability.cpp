#include "Ability.h"

void Ability::Initialization(const char* path, int width, int height,
	std::shared_ptr<Collider> collider, int timeOfWork, int x, int y)
{
	GameObject::Initialization(path, width, height, x, y);

	this->TimeOfWork = timeOfWork;
	this->_collider = collider;
	this->_collected = false;
}

void Ability::Update()
{
	if (this->_collected)
	{
		return;
	}

	GameObject::Update();
}

void Ability::Collect()
{
	this->_collected = true;

	CollisionService::GetInstance().RemoveCollider(this->_collider);
}

Ability::~Ability()
{
	if (_collected)
	{
		return;
	}

	Collect();
}