#pragma once

#include <random>

#include "Ability.h"

class Ability;

class AbilityService 
{
public:
	static AbilityService& GetInstance() {
		static AbilityService instance;
		return instance;
	}

	void RegisterAbility(std::shared_ptr<Ability> ability);
	void RegisterJetpack(int x, int y,
		std::shared_ptr<GameObject>& entity);
	void RegisterHat(int x, int y,
		std::shared_ptr<GameObject>& entity);
	bool RegisterRandomAbility(int x, int y,
		std::shared_ptr<GameObject>& entity);
	void RemoveAbility(std::shared_ptr<Ability> ability);
	void Update();
	void ReInit();

	~AbilityService();
private:
	AbilityService() {}
	AbilityService(const AbilityService&) = delete;
	void operator=(const AbilityService&) = delete;

	void updatePositions(int distance);

	std::vector<std::shared_ptr<Ability>> _abilities;
};