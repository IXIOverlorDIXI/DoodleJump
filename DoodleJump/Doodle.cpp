#include "Doodle.h"

void Doodle::Update()
{
	ControlInput();

	HorisontalMovement();

	VerticalMovement();

	GameObject::Update();
}

void Doodle::Initialization(const char* path, int width, int height,
	int x, int y)
{
	GameObject::Initialization(path, width, height, 0, 0);

	SetCoordinates(DGV::Window::CurrentWidth / 2 - width / 2,
		DGV::Window::CurrentHeight - height - 10);

	this->_yMovingNormal = -1;
	this->_leftJumpDistance = DGV::Entity::Doodle::CurrentJumpDistance;
	this->_leftFlyTime = 0;

	this->_feetCollider = std::make_shared<RectangleCollider>();
	this->_feetCollider->Initialization(shared_from_this(),
		ColliderTag::DoodleFeet, DGV::Collider::Priority::DoodleFeet,
		DGV::Collider::DoodleFeet::CurrentXIndent,
		DGV::Collider::DoodleFeet::CurrentYIndent,
		DGV::Collider::DoodleFeet::CurrentWidth,
		DGV::Collider::DoodleFeet::CurrentHeight, true);

	this->_bodyCollider = std::make_shared<RectangleCollider>();
	this->_bodyCollider->Initialization(shared_from_this(),
		ColliderTag::DoodleBody, DGV::Collider::Priority::DoodleBody,
		DGV::Collider::DoodleBody::CurrentXIndent,
		DGV::Collider::DoodleBody::CurrentYIndent,
		DGV::Collider::DoodleBody::CurrentWidth,
		DGV::Collider::DoodleBody::CurrentHeight, true);
}

void Doodle::ReInit()
{
	int width, height;

	GetSpriteSize(width, height);

	SetCoordinates(DGV::Window::CurrentWidth / 2 - width / 2,
		DGV::Window::CurrentHeight - height - 10);

	this->_yMovingNormal = -1;
	this->_leftJumpDistance = DGV::Entity::Doodle::CurrentJumpDistance;
	this->_leftFlyTime = 0;
	this->_spriteDirection = SpriteDirection::Right;
	this->_jumpVelocityModifier = 100;

	CollisionService::GetInstance().AddCollider(this->_bodyCollider);
	CollisionService::GetInstance().AddCollider(this->_feetCollider);
}

void Doodle::ControlInput()
{
	if (RGV::IsLeftArrowPressed && !RGV::IsRightArrowPressed)
	{
		_xMovingNormal = -1;
	}
	else if (RGV::IsRightArrowPressed && !RGV::IsLeftArrowPressed)
	{
		_xMovingNormal = 1;
	}
	else if (!RGV::IsLeftArrowPressed && !RGV::IsRightArrowPressed)
	{
		_xMovingNormal = 0;
	}


	if (RGV::IsLeftMouseBottonPressed
		&& this->_spriteDirection != SpriteDirection::Up)
	{
		int w, h;
		this->GetSpriteSize(w, h);

		std::string spritePath = DGS::SpriteRelativePath;
		spritePath.append(DGS::DoodleUpSprite);

		ChangeSprite(spritePath.c_str(), w, h);

		this->_spriteDirection = SpriteDirection::Up;
	}
	else if (this->_xMovingNormal > 0
		&& this->_spriteDirection != SpriteDirection::Right
		&& !RGV::IsLeftMouseBottonPressed)
	{
		int w, h;
		this->GetSpriteSize(w, h);

		std::string spritePath = DGS::SpriteRelativePath;
		spritePath.append(DGS::DoodleRightSprite);

		ChangeSprite(spritePath.c_str(), w, h);

		this->_spriteDirection = SpriteDirection::Right;
	}
	else if (this->_xMovingNormal < 0
		&& this->_spriteDirection != SpriteDirection::Left
		&& !RGV::IsLeftMouseBottonPressed)
	{
		int w, h;
		this->GetSpriteSize(w, h);

		std::string spritePath = DGS::SpriteRelativePath;
		spritePath.append(DGS::DoodleLeftSprite);

		ChangeSprite(spritePath.c_str(), w, h);

		this->_spriteDirection = SpriteDirection::Left;
	}

	if (RGV::IsLeftMouseBottonReleased)
	{
		RGV::IsLeftMouseBottonReleased = false;
		RGV::IsLeftMouseBottonPressed = false;
		Shoot();
	}
}

void Doodle::HorisontalMovement()
{
	if (_xMovingNormal == 0)
	{
		return;
	}

	int x, y;
	GetCoordinates(x, y);

	x += _xMovingNormal * std::ceil(DGV::Entity::Doodle::CurrentHorisontalMoveSpeed
		* this->_jumpVelocityModifier / 100.0);

	SetCoordinates(x, y);
}

void Doodle::VerticalMovement()
{
	int deltaDistance = 0;

	if (this->_leftFlyTime > 0)
	{
		deltaDistance = std::ceil(DGV::Entity::Doodle::CurrentVerticalMoveSpeed
			* DGV::Entity::Ability::FlyVelocityModifier);

		_leftFlyTime -= RGV::LastTickDuration;
	}
	else
	{
		deltaDistance = std::ceil(DGV::Entity::Doodle::CurrentVerticalMoveSpeed
			* this->_jumpVelocityModifier / 100.0);

		if (this->_leftJumpDistance > 0)
		{
			if (_leftJumpDistance >= deltaDistance)
			{
				_leftJumpDistance -= deltaDistance;
			}
			else
			{
				deltaDistance = _leftJumpDistance;
				_leftJumpDistance = 0;
			}
		}
		else
		{
			this->_yMovingNormal = 1;
		}
	}

	int x, y;

	GetCoordinates(x, y);

	y += deltaDistance * _yMovingNormal;

	SetCoordinates(x, y);
}

void Doodle::Shoot()
{
	int x, y;

	GetCoordinates(x, y);

	x += DGV::Entity::Doodle::CurrentWidth / 2.0 
		- DGV::Entity::Bullet::CurrentDiameter / 2.0;
	y -= DGV::Entity::Bullet::CurrentDiameter;

	int vX = RGV::MouseXPosition - x;
	int vY = RGV::MouseYPosition - y;

	if (vX == 0 && vY == 0)
	{
		vY = 1;
	}

	double v = sqrt(pow(vX, 2) + pow(vY, 2));

	std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>();
	
	std::string spritePath = DGS::SpriteRelativePath;
	spritePath.append(DGS::DoodleBulletSprite);
	
	bullet->Initialization(spritePath.c_str(),
		DGV::Entity::Bullet::CurrentDiameter, vX / v, vY / v, x, y);

	BulletService::GetInstance().RegisterBullet(bullet);
}

void Doodle::SetCoordinates(int x, int y)
{
	int width, height;

	GetSpriteSize(width, height);

	float halfWidth = width / 2.0;
	float halfWindowHeight = DGV::Window::CurrentHeight / 2.0;

	int distance = 0;

	if (x < -halfWidth)
	{
		x = DGV::Window::CurrentWidth - halfWidth;
	}
	else if (x > DGV::Window::CurrentWidth - halfWidth)
	{
		x = -halfWidth;
	}

	if (y > DGV::Window::CurrentHeight)
	{
		RGV::IsAlive = false;
	}
	else if (y < halfWindowHeight - height)
	{
		distance = halfWindowHeight - height - y;

		y = halfWindowHeight - height;
	}

	RGV::LastTickDistance = distance;

	GameObject::SetCoordinates(x, y);
}

void Doodle::Death()
{
	if (this->_leftFlyTime > 0)
	{
		return;
	}

	CollisionService::GetInstance().RemoveCollider(this->_feetCollider);
	CollisionService::GetInstance().RemoveCollider(this->_bodyCollider);

	this->_yMovingNormal = 1;
	this->_jumpVelocityModifier = 100;
}

bool Doodle::CollisionHanler(std::shared_ptr<Collider> trigger,
	std::shared_ptr<Collider> other)
{
	if (this->_leftFlyTime > 0)
	{
		return false;
	}

	if (trigger->Tag == ColliderTag::DoodleFeet
		&& other->Tag == ColliderTag::Platform
		&& this->_yMovingNormal >= 0)
	{
		this->_yMovingNormal = -1;
		this->_leftJumpDistance = DGV::Entity::Doodle::CurrentJumpDistance;

		std::shared_ptr <Platform> platform =
			std::dynamic_pointer_cast<Platform>(
				other->ParentGameObject.lock());

		if (this->_lastJumpedOnPlatform.lock() == platform)
		{
			this->_jumpVelocityModifier += DGV::Game::IncreaseJumpSpeedModifier;
			this->_jumpVelocityModifier = std::min(this->_jumpVelocityModifier,
				DGV::Game::MaxJumpSpeedModifier);
		}
		else
		{
			this->_jumpVelocityModifier -= DGV::Game::DecreaseJumpSpeedModifier;
			this->_jumpVelocityModifier = std::max(this->_jumpVelocityModifier,
				DGV::Game::MinJumpSpeedModifier);

			this->_lastJumpedOnPlatform = platform;
		}

		int x, y, w, h, xP, yP;

		GetCoordinates(x, y);
		GetSpriteSize(w, h);

		platform->GetCoordinates(xP, yP);

		SetCoordinates(x, yP - h);


		PlatformService::GetInstance().UpdateScore(platform);
	}
	
	else if (trigger->Tag == ColliderTag::DoodleFeet
		&& other->Tag == ColliderTag::Spring
		&& this->_yMovingNormal >= 0)
	{
		this->_yMovingNormal = -1;
		

		std::shared_ptr <Spring> spring =
			std::dynamic_pointer_cast<Spring>(
				other->ParentGameObject.lock());

		this->_leftJumpDistance = std::ceil(
			DGV::Entity::Doodle::CurrentJumpDistance * spring->JumpModifier);

		int x, y, w, h, xP, yP;

		GetCoordinates(x, y);
		GetSpriteSize(w, h);

		spring->GetCoordinates(xP, yP);

		SetCoordinates(x, yP - h);
	}
	
	else if (trigger->Tag == ColliderTag::DoodleFeet
		&& other->Tag == ColliderTag::EnemyHead
		&& this->_yMovingNormal >= 0)
	{
		this->_yMovingNormal = -1;
		this->_leftJumpDistance = DGV::Entity::Doodle::CurrentJumpDistance;

		std::shared_ptr <Enemy> enemy =
			std::dynamic_pointer_cast<Enemy>(
				other->ParentGameObject.lock());

		int x, y, w, h, xP, yP;

		GetCoordinates(x, y);
		GetSpriteSize(w, h);

		enemy->GetCoordinates(xP, yP);

		SetCoordinates(x, yP - h);

		enemy->TakeDamage(100000);
	}
	
	else if (trigger->Tag == ColliderTag::DoodleBody
		&& other->Tag == ColliderTag::Ability)
	{
		this->_yMovingNormal = -1;
		this->_leftJumpDistance = 0;

		std::shared_ptr<Ability> ability =
			std::dynamic_pointer_cast<Ability>(
				other->ParentGameObject.lock());

		this->_leftFlyTime = ability->TimeOfWork;

		ability->Collect();
	}

	return false;
}