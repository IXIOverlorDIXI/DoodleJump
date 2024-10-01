#pragma once

#include <memory>
#include <chrono>
#include <thread>

#include "Framework.h"
#include "GameController.h"

class Game : public Framework
{
public:
	void PreInit(int &width, int &height, bool &fullscreen) override;

	bool Init() override;

	void Close() override;

	bool Tick() override;

	void onMouseMove(int x, int y, int xrelative, int yrelative) override;

	void onMouseButtonClick(FRMouseButton button, bool isReleased) override;

	void onKeyPressed(FRKey k) override;

	void onKeyReleased(FRKey k) override;

	const char *GetTitle() override;

private:
	void setGlobalParameters();

	std::unique_ptr<GameController> _gameController;
	std::chrono::milliseconds _tickDuration;
	std::chrono::steady_clock::time_point _lastTickTime;
};