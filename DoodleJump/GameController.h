#pragma once

#include <memory>
#include <iostream>
#include <cstdlib>

#include "GameObject.h"
#include "Doodle.h"
#include "PlatformService.h"
#include "ScoreService.h"

class GameController
{
public:
	void Initialize();
	void Update();
	void Restart();
private: 
	void setBackground();
	void setDoodle();
	void setGlobalParameters();

	std::unique_ptr<GameObject> _background;
	std::shared_ptr<GameObject> _doodle;
};