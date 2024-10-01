#pragma once

#include <random>
#include <sstream>

#include "Spring.h"

class Spring;

class SpringService
{
public:
	static SpringService& GetInstance() {
		static SpringService instance;
		return instance;
	}

	void RegisterSpring(std::shared_ptr<Spring> spring);
	void RegisterRandomSpring(int x, int y,
		std::shared_ptr<GameObject>& entity);
	void RemoveSpring(std::shared_ptr<Spring> spring);
	void Update();
	void ReInit();

	~SpringService();
private:
	SpringService() {}
	SpringService(const SpringService&) = delete;
	void operator=(const SpringService&) = delete;

	void updatePositions(int distance);
	void registerTrampoline(int x, int y,
		std::shared_ptr<GameObject>& entity);
	void registerDefaultSpring(int x, int y,
		std::shared_ptr<GameObject>& entity);

	std::vector<std::shared_ptr<Spring>> _springs;
};