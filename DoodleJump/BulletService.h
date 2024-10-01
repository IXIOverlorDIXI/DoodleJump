#pragma once

#include "Bullet.h"

class Bullet;

class BulletService
{
public:
	static BulletService& GetInstance() {
		static BulletService instance;
		return instance;
	}

	void RegisterBullet(std::shared_ptr<Bullet> bullet);
	void RemoveBullet(std::shared_ptr<Bullet> bullet);
	void RemoveBullet(std::shared_ptr<Bullet> bullet,
		std::vector<std::shared_ptr<Bullet>>::iterator& iterator);
	void Update();
	void ReInit();

	~BulletService();
private:
	BulletService() {}
	BulletService(const BulletService&) = delete;
	void operator=(const BulletService&) = delete;

	std::vector<std::shared_ptr<Bullet>> _bullets;
};