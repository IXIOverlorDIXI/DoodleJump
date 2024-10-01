#include "Bullet.h"

void Bullet::Initialization(const char* path, int diameter, 
	float xNormal, float yNormal, int x, int y)
{
	GameObject::Initialization(path, diameter, diameter, x, y);

	this->_xNormal = xNormal;
	this->_yNormal = yNormal;

	this->_bulletCollider = std::make_shared<CircleCollider>();
	this->_bulletCollider->Initialization(shared_from_this(),
		ColliderTag::DoodleBullet, DGV::Collider::Priority::DoodleBullet,
		DGV::Collider::DoodleBullet::CurrentXIndent,
		DGV::Collider::DoodleBullet::CurrentYIndent,
		DGV::Collider::DoodleBullet::CurrentRadius, true);
}

bool Bullet::CollisionHanler(std::shared_ptr<Collider> trigger,
	std::shared_ptr<Collider> other)
{
	if (trigger->Tag == ColliderTag::DoodleBullet
		&& other->Tag == ColliderTag::EnemyBody)
	{
		std::shared_ptr <Enemy> enemy =
			std::dynamic_pointer_cast<Enemy>(
				other->ParentGameObject.lock());

		enemy->TakeDamage(1);

		std::shared_ptr<Bullet> bullet = shared_from_this();

		BulletService::GetInstance().RemoveBullet(bullet);
	}

	return false;
}



void Bullet::Update(bool& isDeleted)
{
	int x, y;

	GetCoordinates(x, y);

	x += this->_xNormal * DGV::Entity::Bullet::CurrentVelocity;
	y += this->_yNormal * DGV::Entity::Bullet::CurrentVelocity;

	if (y < -DGV::Entity::Bullet::CurrentDestructionEdgeFromBorder
		|| y > DGV::Window::CurrentHeight
		+ DGV::Entity::Bullet::CurrentDestructionEdgeFromBorder
		|| x < -DGV::Entity::Bullet::CurrentDestructionEdgeFromBorder
		|| x > DGV::Window::CurrentWidth
		+ DGV::Entity::Bullet::CurrentDestructionEdgeFromBorder)
	{
		isDeleted = true;

		return;
	}

	SetCoordinates(x, y);

	GameObject::Update();

	isDeleted = false;
}

Bullet::~Bullet()
{
	CollisionService::GetInstance().RemoveCollider(this->_bulletCollider);
}

