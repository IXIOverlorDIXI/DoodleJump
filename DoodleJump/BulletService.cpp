#include "BulletService.h"

void BulletService::ReInit()
{
	this->_bullets.clear();
}

void BulletService::RegisterBullet(std::shared_ptr<Bullet> bullet)
{
	this->_bullets.insert(this->_bullets.begin(), bullet);
}

void BulletService::RemoveBullet(std::shared_ptr<Bullet> bullet)
{
	if (this->_bullets.empty())
	{
		return;
	}

	this->_bullets.erase(std::remove_if(
		this->_bullets.begin(),
		this->_bullets.end(),
		[&bullet](const std::shared_ptr<Bullet>& ptr) {
			return ptr == bullet;
		}), this->_bullets.end());
}

void BulletService::RemoveBullet(std::shared_ptr<Bullet> bullet,
	std::vector<std::shared_ptr<Bullet>>::iterator& iterator)
{
	if (this->_bullets.empty())
	{
		return;
	}

	iterator = this->_bullets.erase(std::remove_if(
		this->_bullets.begin(),
		this->_bullets.end(),
		[&bullet](const std::shared_ptr<Bullet>& ptr) {
			return ptr == bullet;
		}), this->_bullets.end());
}

void BulletService::Update()
{
	auto iterator = this->_bullets.begin();

	while (iterator != this->_bullets.end())
	{
		bool isDeleted = false;
		(*iterator)->Update(isDeleted);

		if (isDeleted)
		{
			RemoveBullet(*iterator, iterator);
		}
		else
		{
			++iterator;
		}
	}
}

BulletService::~BulletService()
{
	this->_bullets.clear();
}