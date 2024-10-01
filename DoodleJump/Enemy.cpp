#include "Enemy.h"

void Enemy::Initialization(const char* path, int width, int height,
	int x, int y) 
{
	GameObject::Initialization(path, width, height, x, y);

	this->_health = 1;

	this->_bodyCollider = std::make_shared<RectangleCollider>();
	this->_bodyCollider->Initialization(shared_from_this(),
		ColliderTag::EnemyBody, DGV::Collider::Priority::EnemyBody,
		DGV::Collider::EnemyBody::CurrentXIndent,
		DGV::Collider::EnemyBody::CurrentYIndent,
		DGV::Collider::EnemyBody::CurrentWidth,
		DGV::Collider::EnemyBody::CurrentHeight, true);

	this->_headCollider = std::make_shared<RectangleCollider>();
	this->_headCollider->Initialization(shared_from_this(),
		ColliderTag::EnemyHead, DGV::Collider::Priority::EnemyHead,
		DGV::Collider::EnemyHead::CurrentXIndent,
		DGV::Collider::EnemyHead::CurrentYIndent,
		DGV::Collider::EnemyHead::CurrentWidth,
		DGV::Collider::EnemyHead::CurrentHeight, false);
}

bool Enemy::CollisionHanler(std::shared_ptr<Collider> trigger,
	std::shared_ptr<Collider> other)
{
	if (this->_health <= 0)
	{
		Death();

		return false;
	}

	if (trigger->Tag == ColliderTag::EnemyBody
		&& other->Tag == ColliderTag::DoodleBody)
	{
		std::shared_ptr <Doodle> doodle =
			std::dynamic_pointer_cast<Doodle>(
				other->ParentGameObject.lock());

		doodle->Death();
	}

	return false();
}

void Enemy::Update() 
{
	if (this->_health <= 0)
	{
		return;
	}

	GameObject::Update();
}

void Enemy::TakeDamage(int damage) 
{
	this->_health -= damage;

	if (this->_health <= 0)
	{
		Death();
	}
}

void Enemy::Death() 
{
	CollisionService::GetInstance().RemoveCollider(this->_headCollider);
	CollisionService::GetInstance().RemoveCollider(this->_bodyCollider);
}

Enemy::~Enemy()
{
	Death();
}