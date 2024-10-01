#pragma once

#include <vector>
#include <cmath>

#include "GameObject.h"

class ScoreService
{
public:
	static ScoreService& GetInstance() {
		static ScoreService instance;
		return instance;
	}

	void Initialize();
	void Update();
	void ReInit();

	~ScoreService();
private:
	ScoreService() {}
	ScoreService(const ScoreService&) = delete;
	void operator=(const ScoreService&) = delete;

	void renderScore(int x, int y, int score);

	std::unique_ptr<GameObject> _overallScoreCaption;
	std::unique_ptr<GameObject> _jumpedOnScoreCaption;
	std::unique_ptr<GameObject> _jumpedOverScoreCaption;
	std::vector<std::unique_ptr<GameObject>> _numbers;
};