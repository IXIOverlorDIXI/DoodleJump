#pragma once

#include "Enemy.h"

class Enemy;

class EnemyService
{
public:
	static EnemyService& GetInstance() {
		static EnemyService instance;
		return instance;
	}

	void RegisterEnemy(std::shared_ptr<Enemy> enemy);
	void RegisterEnemy(int x, int y, 
		std::shared_ptr<GameObject>& entity);
	void RemoveEnemy(std::shared_ptr<Enemy> enemy);
	void Update();
	void ReInit();

	~EnemyService();
private:
	EnemyService() {}
	EnemyService(const EnemyService&) = delete;
	void operator=(const EnemyService&) = delete;

	void updatePositions(int distance);

	std::vector<std::shared_ptr<Enemy>> _enemies;
};