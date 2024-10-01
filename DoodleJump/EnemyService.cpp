#include "EnemyService.h"

void EnemyService::ReInit()
{
	this->_enemies.clear();
}

void EnemyService::RegisterEnemy(std::shared_ptr<Enemy> enemy)
{
	this->_enemies.insert(this->_enemies.begin(), enemy);
}

void EnemyService::RegisterEnemy(int x, int y, 
	std::shared_ptr<GameObject> &entity)
{
	std::string enemySpritePath = DGS::SpriteRelativePath;
	enemySpritePath.append(DGS::DefaultEnemySprite);

	std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();

	int platformCenter = DGV::Entity::Platform::CurrentWidth / 2;
	int enemyCenter = DGV::Entity::Enemy::CurrentWidth / 2;

	int entityX = x + platformCenter - enemyCenter,
		entityY = y - DGV::Entity::Enemy::CurrentHeight
		- DGV::Entity::Enemy::CurrentIndentFromPlatform;

	enemy->Initialization(enemySpritePath.c_str(),
		DGV::Entity::Enemy::CurrentWidth,
		DGV::Entity::Enemy::CurrentHeight, entityX, entityY);

	RegisterEnemy(enemy);

	entity = enemy;
}

void EnemyService::RemoveEnemy(std::shared_ptr<Enemy> enemy)
{
	if (this->_enemies.empty())
	{
		return;
	}

	this->_enemies.erase(std::remove_if(
		this->_enemies.begin(),
		this->_enemies.end(),
		[&enemy](const std::shared_ptr<Enemy>& ptr) {
			return ptr == enemy;
		}), this->_enemies.end());
}

void EnemyService::Update()
{
	updatePositions(RGV::LastTickDistance);

	auto iterator = this->_enemies.begin();

	while (iterator != this->_enemies.end())
	{
		(*iterator)->Update();

		++iterator;
	}
}

void EnemyService::updatePositions(int distance)
{
	if (this->_enemies.empty() || distance == 0)
	{
		return;
	}

	auto iterator = this->_enemies.begin();

	int x, y;

	while (iterator != this->_enemies.end())
	{
		(*iterator)->GetCoordinates(x, y);

		if (y > DGV::Window::CurrentHeight
			+ DGV::Entity::Enemy::CurrentDestructionEdgeFromBottom)
		{
			iterator = this->_enemies.erase(iterator);
		}
		else
		{
			(*iterator)->SetCoordinates(x, y + distance);

			++iterator;
		}
	}
}

EnemyService::~EnemyService()
{
	this->_enemies.clear();
}