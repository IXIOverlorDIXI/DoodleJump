#pragma once

#include "GameObject.h"
#include "CollisionService.h"
#include "AbilityService.h"

class Ability : public GameObject, public std::enable_shared_from_this<Ability>
{
public:
	virtual void Initialization(const char* path, int width, int height,
		std::shared_ptr<Collider> collider, int timeOfWork,
		int x = 0, int y = 0);
	virtual void Update() override;
	virtual void Collect();
	~Ability();
	int TimeOfWork;
private:
	bool _collected;
	std::shared_ptr<Collider> _collider;
};