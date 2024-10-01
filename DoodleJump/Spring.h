#pragma once

#include "GameObject.h"
#include "CollisionService.h"
#include "SpringService.h"

class Spring : public GameObject, public std::enable_shared_from_this<Spring>
{
public:
	virtual void Initialization(const char* path, int width, int height,
		std::shared_ptr<Collider> collider, float jumpModifier,
		int x = 0, int y = 0);
	~Spring();
	float JumpModifier;
private:
	std::shared_ptr<Collider> _collider;
};