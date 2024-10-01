#pragma once

#include <random>

#include "Platform.h"
#include "Enemy.h"
#include "EnemyService.h"
#include "AbilityService.h"
#include "SpringService.h"

class PlatformService
{
public:
	static PlatformService& GetInstance() {
		static PlatformService instance;
		return instance;
	}
	void Initialization();
	void RemovePlatform(std::shared_ptr<Platform> platform);
	void Update();
	void UpdateScore(std::shared_ptr<Platform> platformJumpedOn);
	void ReInit();
	~PlatformService();
private:
	PlatformService() {}
	PlatformService(const PlatformService&) = delete;
	void operator=(const PlatformService&) = delete;

	void updatePositions(int distance);
	void addPlatforms();
	void xPlatformPositionVerification(int &x);

	int _enemySpawnedAmount;
	int _jetpackAbilitySpawnedAmount;
	int _abilitySpawnedAmount;
	std::vector<std::shared_ptr<Platform>> _platforms;
};