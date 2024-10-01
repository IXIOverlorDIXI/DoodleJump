#pragma once

#include "GameObject.h"
#include "CollisionService.h"
#include "Enemy.h"
#include "BulletService.h"

class Bullet : public GameObject, public std::enable_shared_from_this<Bullet>
{
public:
	virtual void Initialization(const char* path, int diameter,
		float xNormal, float yNormal, int x = 0, int y = 0);
	virtual void Update(bool &isDeleted);
	virtual bool CollisionHanler(std::shared_ptr<Collider> trigger,
		std::shared_ptr<Collider> other) override; 
	~Bullet();
private:
	float _xNormal;
	float _yNormal;
	std::shared_ptr<CircleCollider> _bulletCollider;
};
