#pragma once

#include "Ability.h"

class Jetpack : public Ability, public std::enable_shared_from_this<Jetpack>
{
public:
	void Initialization(const char* path, int width, int height,
		int x = 0, int y = 0) override;
	void Collect()
private:
};