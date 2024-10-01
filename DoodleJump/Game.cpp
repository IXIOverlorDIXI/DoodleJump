#include <iostream>
#include <cmath>

#include "Game.h"
#include "Doodle.h"

#include "EnemyService.h"
#include "BulletService.h"
#include "AbilityService.h"

#include "DefaultGameValues.h"
#include "DefaultGameSprites.h"
#include "RuntimeGameValues.h"

void Game::PreInit(int &width, int &height, bool &fullscreen)
{
	width = DGV::Window::CurrentWidth;
	height = DGV::Window::CurrentHeight;

	RGV::VerticalScale = (float)DGV::Window::CurrentHeight 
		/ DGV::Window::DefaultHeight;
	RGV::HorisontalScale = (float)DGV::Window::CurrentWidth
		/ DGV::Window::DefaultWidth;

	fullscreen = false;
}

bool Game::Init()
{
	this->_gameController = std::make_unique<GameController>();
	this->_gameController->Initialize();

	this->_tickDuration = std::chrono::milliseconds(1000 
		/ DGV::Game::DefaultTickAmount);
	this->_lastTickTime = std::chrono::steady_clock::now();

	return true;
}

void Game::Close()
{
}

bool Game::Tick()
{
	std::this_thread::sleep_until(_lastTickTime + _tickDuration);

	this->_gameController->Update();

	RGV::LastTickDuration = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::steady_clock::now() - _lastTickTime).count();

	_lastTickTime = std::chrono::steady_clock::now();

	return false();
}

void Game::onMouseMove(int x, int y, int xrelative, int yrelative)
{
	RGV::MouseXPosition = x;
	RGV::MouseYPosition = y;
}

void Game::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	switch (button)
	{
	case FRMouseButton::LEFT:
		RGV::IsLeftMouseBottonPressed = true;
		break;
	default:
		break;
	}

	RGV::IsLeftMouseBottonReleased = isReleased;
}

void Game::onKeyPressed(FRKey k)
{
	switch (k)
	{
	case FRKey::LEFT:
		RGV::IsLeftArrowPressed = true;
		break;
	case FRKey::RIGHT:
		RGV::IsRightArrowPressed = true;
		break;
	case FRKey::DOWN:
		RGV::BlindMode = !RGV::BlindMode;
		break;
	default:
		break;
	}
}

void Game::onKeyReleased(FRKey k)
{
	switch (k)
	{
	case FRKey::LEFT:
		RGV::IsLeftArrowPressed = false;
		break;
	case FRKey::RIGHT:
		RGV::IsRightArrowPressed = false;
		break;
	case FRKey::UP:
		this->_gameController->Restart();
		break;
	default:
		break;
	}
}

const char *Game::GetTitle()
{
	return "Doodle Jump";
}