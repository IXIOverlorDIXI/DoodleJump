#pragma once

#include "GameObject.h"
#include "CollisionService.h"
#include "Doodle.h"

class Enemy : public GameObject, public std::enable_shared_from_this<Enemy>
{
public:
	virtual void Initialization(const char* path, int width, int height,
		int x = 0, int y = 0) override;
	virtual void Update() override;
	virtual bool CollisionHanler(std::shared_ptr<Collider> trigger,
		std::shared_ptr<Collider> other) override;
	virtual void TakeDamage(int damage);
	~Enemy();
protected:
	virtual void Death();
private:
	int _health;
	std::shared_ptr<RectangleCollider> _headCollider;
	std::shared_ptr<RectangleCollider> _bodyCollider;
};