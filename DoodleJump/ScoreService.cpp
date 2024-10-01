#include "ScoreService.h"

void ScoreService::Initialize()
{
	this->_overallScoreCaption = std::make_unique<GameObject>();
	this->_overallScoreCaption->Initialization(
		(DGS::SpriteRelativePath + DGS::UI::OverallScoreSprite).c_str(),
		DGV::UI::Score::CurrentOverallScoreCaptionWidth,
		DGV::UI::Score::CurrentOverallScoreCaptionHeight);

	int scoreCaptionCenter = std::ceil(
		DGV::UI::Score::CurrentOverallScoreCaptionWidth / 2.0);

	this->_jumpedOverScoreCaption = std::make_unique<GameObject>();
	this->_jumpedOverScoreCaption->Initialization(
		(DGS::SpriteRelativePath + DGS::UI::JumpedOverScoreSprite).c_str(),
		DGV::UI::Score::CurrentJumpedOverCaptionWidth,
		DGV::UI::Score::CurrentJumpedOverCaptionHeight,
		scoreCaptionCenter
		- DGV::UI::Score::CurrentJumpedOverCaptionWidth / 2,
		DGV::UI::Score::CurrentOverallScoreCaptionHeight
		+ DGV::UI::Score::CurrentRowIndent);

	this->_jumpedOnScoreCaption = std::make_unique<GameObject>();
	this->_jumpedOnScoreCaption->Initialization(
		(DGS::SpriteRelativePath + DGS::UI::JumpedOnScoreSprite).c_str(),
		DGV::UI::Score::CurrentJumpedOnCaptionWidth,
		DGV::UI::Score::CurrentJumpedOnCaptionHeight,
		scoreCaptionCenter
		- DGV::UI::Score::CurrentJumpedOnCaptionWidth / 2,
		DGV::UI::Score::CurrentOverallScoreCaptionHeight
		+ DGV::UI::Score::CurrentJumpedOverCaptionHeight
		+ DGV::UI::Score::CurrentRowIndent * 2);



	/*Numbers*/

	std::unique_ptr<GameObject> number;

	auto iterator = DGS::UI::NumbersSprites.begin();

	while (iterator != DGS::UI::NumbersSprites.end())
	{
		number = std::make_unique<GameObject>();
		number->Initialization(
			(DGS::SpriteRelativePath + *iterator).c_str(),
			DGV::UI::Score::CurrentNumberWidth,
			DGV::UI::Score::CurrentNumberHeight);

		this->_numbers.push_back(std::move(number));

		++iterator;
	}
}

void ScoreService::Update()
{
	this->_overallScoreCaption->Update();
	renderScore(DGV::UI::Score::CurrentOverallScoreCaptionWidth,
		0, RGV::PlayerOverallScore);

	this->_jumpedOverScoreCaption->Update();
	renderScore(DGV::UI::Score::CurrentOverallScoreCaptionWidth,
		DGV::UI::Score::CurrentOverallScoreCaptionHeight
		+ DGV::UI::Score::CurrentRowIndent,
		RGV::PlayerPlatformJumpedOverCounter);

	this->_jumpedOnScoreCaption->Update();
	renderScore(DGV::UI::Score::CurrentOverallScoreCaptionWidth,
		DGV::UI::Score::CurrentOverallScoreCaptionHeight
		+ DGV::UI::Score::CurrentJumpedOverCaptionHeight
		+ DGV::UI::Score::CurrentRowIndent * 2,
		RGV::PlayerPlatformJumpedOnCounter);
}

void ScoreService::renderScore(int x, int y, int score)
{
	std::vector<int> numbers;

	if (score == 0)
	{
		numbers.push_back(0);
	}

	while (score != 0)
	{
		numbers.insert(numbers.begin(), score % 10);
		score /= 10;
	}

	auto iterator = numbers.begin();
	int index = 0;

	while (iterator != numbers.end())
	{
		this->_numbers.at(*iterator)->SetCoordinates(x + index 
			* DGV::UI::Score::CurrentNumberWidth, y);
		this->_numbers.at(*iterator)->Update();

		++index;
		++iterator;
	}
}

void ScoreService::ReInit()
{
	RGV::PlayerOverallScore = 0;
	RGV::PlayerPlatformJumpedOnCounter = 0;
	RGV::PlayerPlatformJumpedOverCounter = 0;
}

ScoreService::~ScoreService()
{
	this->_numbers.clear();
}