#include "PlatformService.h"

void PlatformService::ReInit()
{
	this->_platforms.clear();

	Initialization();
}

void PlatformService::Initialization()
{
	this->_enemySpawnedAmount = 0;
	this->_jetpackAbilitySpawnedAmount = 0;
	this->_abilitySpawnedAmount = 0;

	std::string spritePath = DGS::SpriteRelativePath;
	spritePath.append(DGS::DefaultPlatformSprite);

	int x, y;
	std::uniform_int_distribution<int> xLimitations, yLimitations;

	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());

	xLimitations = std::uniform_int_distribution<int>(
		DGV::Entity::Platform::CurrentBorderIndent,
		DGV::Window::CurrentWidth
		- DGV::Entity::Platform::CurrentBorderIndent);

	x = xLimitations(generator);
	y = DGV::Window::CurrentHeight -
		DGV::Entity::Platform::CurrentBottomCreationEdge;

	xPlatformPositionVerification(x);

	std::shared_ptr<Platform> platform = std::make_shared<Platform>();

	platform->Initialization(spritePath.c_str(),
		DGV::Entity::Platform::CurrentWidth,
		DGV::Entity::Platform::CurrentHeight, x, y);

	this->_platforms.insert(this->_platforms.begin(), platform);

	addPlatforms();
}

void PlatformService::RemovePlatform(std::shared_ptr<Platform> platform)
{
	this->_platforms.erase(std::remove_if(
		this->_platforms.begin(),
		this->_platforms.end(),
		[&platform](const std::shared_ptr<Platform>& ptr) {
			return ptr == platform;
		}), this->_platforms.end());
}

void PlatformService::updatePositions(int distance)
{
	if (this->_platforms.empty())
	{
		Initialization();
		updatePositions(distance);

		return;
	}

	if (distance == 0)
	{
		return;
	}

	auto iterator = this->_platforms.begin();

	int x, y;

	while (iterator != this->_platforms.end())
	{
		(*iterator)->GetCoordinates(x, y);

		if (y > DGV::Window::CurrentHeight
			+ DGV::Entity::Platform::CurrentDestructionEdgeFromBottom)
		{
			iterator = this->_platforms.erase(iterator);
		}
		else
		{
			(*iterator)->SetCoordinates(x, y + distance);

			++iterator;
		}
	}

	(*this->_platforms.begin())->GetCoordinates(x, y);

	if (y > -DGV::Entity::Platform::CurrentCreationEdgeFromTop)
	{
		addPlatforms();
	}

	RGV::PlayerOverallScore += distance * RGV::VerticalScale
		/ DGV::Game::ScoreModifier;
}

void PlatformService::UpdateScore(std::shared_ptr<Platform> platformJumpedOn)
{
	if (platformJumpedOn->IsJumpedOn)
	{
		return;
	}

	auto iterator = std::find(this->_platforms.begin(),
		this->_platforms.end(), platformJumpedOn);

	if (iterator == _platforms.end()) {
		return;
	}

	RGV::PlayerPlatformJumpedOnCounter++;
	platformJumpedOn->IsJumpedOn = true;

	if (!platformJumpedOn->IsJumpedOver)
	{
		RGV::PlayerPlatformJumpedOverCounter++;
		platformJumpedOn->IsJumpedOver = true;
	}

	for (auto innerIterator = iterator + 1; innerIterator != _platforms.end();)
	{
		if (!(*innerIterator)->IsJumpedOver)
		{
			RGV::PlayerPlatformJumpedOverCounter++;
			(*innerIterator)->IsJumpedOver = true;
		}

		++innerIterator;
	}
}

void PlatformService::addPlatforms()
{
	std::string spritePath = DGS::SpriteRelativePath;
	spritePath.append(DGS::DefaultPlatformSprite);

	int x, y;
	std::uniform_int_distribution<int> xLimitations, yLimitations;
	std::uniform_int_distribution<int> signCondition(0, 1);
	std::uniform_real_distribution<double> chanceLimitations(0.0, 1.0);

	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());

	do
	{
		if (this->_platforms.empty())
		{
			Initialization();

			continue;
		}
		else
		{
			(*this->_platforms.begin())->GetCoordinates(x, y);
		}

		xLimitations = std::uniform_int_distribution<int>(
			DGV::Entity::Platform::CurrentMinSideIndentFromPrevious,
			DGV::Entity::Platform::CurrentMaxSideIndentFromPrevious);

		yLimitations = std::uniform_int_distribution<int>(
			DGV::Entity::Platform::CurrentMinTopIndentFromPrevious,
			DGV::Entity::Platform::CurrentMaxTopIndentFromPrevious);

		x += signCondition(generator) == 0
			? -xLimitations(generator)
			: xLimitations(generator);

		y -= yLimitations(generator);

		auto checkIterator = this->_platforms.begin();
		bool checkEntity = false;

		while (checkIterator != this->_platforms.end())
		{
			if ((*checkIterator)->WithEntity())
			{
				checkEntity = true;

				break;
			}

			++checkIterator;
		}

		if (checkEntity)
		{
			int xE, yE, wE, hE;

			(*checkIterator)->EntityParameters(xE, yE, wE, hE);

			checkIterator = this->_platforms.begin();

			yE -= DGV::Entity::Platform::CurrentMinTopIndentFromPrevious;

			if (yE < y)
			{
				if (x < xE && xE < x + DGV::Entity::Platform::CurrentWidth)
				{
					int leftX = xE
						- DGV::Entity::Platform::CurrentMinSideIndentFromPrevious
						- DGV::Entity::Platform::CurrentWidth;
					int rightX = xE + wE
						+ DGV::Entity::Platform::CurrentMinSideIndentFromPrevious;

					if (leftX > DGV::Entity::Platform::CurrentBorderIndent)
					{
						x = leftX;
					}
					else if (rightX + DGV::Entity::Platform::CurrentWidth
						< DGV::Window::CurrentWidth
						- DGV::Entity::Platform::CurrentBorderIndent)
					{
						x = rightX;
					}
					else
					{
						y = yE;
					}
				}
				else if (x < xE + wE && xE + wE < x
					+ DGV::Entity::Platform::CurrentWidth)
				{
					int leftX = xE
						- DGV::Entity::Platform::CurrentMinSideIndentFromPrevious
						- DGV::Entity::Platform::CurrentWidth;
					int rightX = xE + wE
						+ DGV::Entity::Platform::CurrentMinSideIndentFromPrevious;

					if (rightX + DGV::Entity::Platform::CurrentWidth
						< DGV::Window::CurrentWidth
						- DGV::Entity::Platform::CurrentBorderIndent)
					{
						x = rightX;
					}
					else if (leftX > DGV::Entity::Platform::CurrentBorderIndent)
					{
						x = leftX;
					}
					else
					{
						y = yE;
					}
				}
			}
		}

		xPlatformPositionVerification(x);

		std::shared_ptr<Platform> platform = std::make_shared<Platform>();

		std::shared_ptr<GameObject> entity;

		if ((int)RGV::PlayerOverallScore / DGV::Game::ScoreAmountToSpawnEnemy
				> this->_enemySpawnedAmount)
		{
			if (chanceLimitations(generator) <= DGV::Entity::Enemy::SpawnChance)
			{
				this->_enemySpawnedAmount++;

				EnemyService::GetInstance().RegisterEnemy(x, y, entity);
			}
		}
		else if ((int)RGV::PlayerOverallScore
			/ DGV::Game::ScoreAmountToSpawnJetpack
				> this->_jetpackAbilitySpawnedAmount)
		{
			this->_jetpackAbilitySpawnedAmount++;

			AbilityService::GetInstance().RegisterJetpack(x, y, entity);
		}
		else if ((int)RGV::PlayerOverallScore / DGV::Game::
			ScoreAmountToSpawnRandomAbility > this->_abilitySpawnedAmount)
		{
			this->_abilitySpawnedAmount += AbilityService::GetInstance()
				.RegisterRandomAbility(x, y, entity);
		}

		if (!entity
			&& chanceLimitations(generator) < DGV::Entity::Spring::SpawnChance)
		{
			SpringService::GetInstance().RegisterRandomSpring(x, y, entity);
		}

		platform->Initialization(spritePath.c_str(),
			DGV::Entity::Platform::CurrentWidth,
			DGV::Entity::Platform::CurrentHeight, x, y, entity);

		this->_platforms.insert(this->_platforms.begin(), platform);
	} while (y > -DGV::Entity::Platform::CurrentCreationEdgeFromTop);
}

void PlatformService::xPlatformPositionVerification(int& x)
{
	if (x < DGV::Entity::Platform::CurrentBorderIndent)
	{
		x = DGV::Window::CurrentWidth
			- DGV::Entity::Platform::CurrentBorderIndent
			- DGV::Entity::Platform::CurrentWidth - abs(x)
			% (DGV::Window::CurrentWidth - DGV::Entity::Platform::CurrentWidth
				- 2 * DGV::Entity::Platform::CurrentBorderIndent);
	}
	else if (x > DGV::Window::CurrentWidth
		- DGV::Entity::Platform::CurrentWidth
		- DGV::Entity::Platform::CurrentBorderIndent)
	{
		x = DGV::Entity::Platform::CurrentBorderIndent + x
			% (DGV::Window::CurrentWidth
				- DGV::Entity::Platform::CurrentWidth
				- 2 * DGV::Entity::Platform::CurrentBorderIndent);
	}
}

void PlatformService::Update()
{
	updatePositions(RGV::LastTickDistance);

	auto iterator = this->_platforms.begin();

	while (iterator != this->_platforms.end())
	{
		(*iterator)->Update();

		++iterator;
	}
}

PlatformService::~PlatformService()
{
	this->_platforms.clear();
}