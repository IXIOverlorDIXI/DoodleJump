#include "AbilityService.h"

void AbilityService::ReInit()
{
	this->_abilities.clear();
}

void AbilityService::RegisterAbility(std::shared_ptr<Ability> ability)
{
	this->_abilities.insert(this->_abilities.begin(), ability);
}

void AbilityService::RegisterJetpack(int x, int y,
	std::shared_ptr<GameObject>& entity)
{
	std::string abilitySpritePath = DGS::SpriteRelativePath;
	abilitySpritePath.append(DGS::JetpackSprite);

	std::shared_ptr<Ability> ability = std::make_shared<Ability>();

	int platformCenter = DGV::Entity::Platform::CurrentWidth / 2;
	int abilityCenter = DGV::Entity::Ability::Jetpack::CurrentWidth / 2;

	int entityX = x + platformCenter - abilityCenter,
		entityY = y - DGV::Entity::Ability::Jetpack::CurrentHeight;

	std::shared_ptr<RectangleCollider> collider =
		std::make_shared<RectangleCollider>();

	collider->Initialization(ability, ColliderTag::Ability, 
		DGV::Collider::Priority::Ability,
		DGV::Collider::Ability::Jetpack::CurrentXIndent,
		DGV::Collider::Ability::Jetpack::CurrentYIndent,
		DGV::Collider::Ability::Jetpack::CurrentWidth,
		DGV::Collider::Ability::Jetpack::CurrentHeight, false);

	ability->Initialization(abilitySpritePath.c_str(),
		DGV::Entity::Ability::Jetpack::CurrentWidth,
		DGV::Entity::Ability::Jetpack::CurrentHeight, collider,
		DGV::Entity::Ability::Jetpack::FlyTime, entityX, entityY);

	RegisterAbility(ability);

	entity = ability;
}

void AbilityService::RegisterHat(int x, int y,
	std::shared_ptr<GameObject>& entity)
{
	std::string abilitySpritePath = DGS::SpriteRelativePath;
	abilitySpritePath.append(DGS::HatSprite);

	std::shared_ptr<Ability> ability = std::make_shared<Ability>();

	int platformCenter = DGV::Entity::Platform::CurrentWidth / 2;
	int abilityCenter = DGV::Entity::Ability::Hat::CurrentWidth / 2;

	int entityX = x + platformCenter - abilityCenter,
		entityY = y - DGV::Entity::Ability::Hat::CurrentHeight;

	std::shared_ptr<RectangleCollider> collider =
		std::make_shared<RectangleCollider>();

	collider->Initialization(ability, ColliderTag::Ability,
		DGV::Collider::Priority::Ability,
		DGV::Collider::Ability::Hat::CurrentXIndent,
		DGV::Collider::Ability::Hat::CurrentYIndent,
		DGV::Collider::Ability::Hat::CurrentWidth,
		DGV::Collider::Ability::Hat::CurrentHeight, false);

	ability->Initialization(abilitySpritePath.c_str(),
		DGV::Entity::Ability::Hat::CurrentWidth,
		DGV::Entity::Ability::Hat::CurrentHeight, collider,
		DGV::Entity::Ability::Hat::FlyTime, entityX, entityY);

	RegisterAbility(ability);

	entity = ability;
}

bool AbilityService::RegisterRandomAbility(int x, int y,
	std::shared_ptr<GameObject>& entity)
{
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());

	std::uniform_real_distribution<double> limitations(0.0, 1.0);

	if (limitations(generator) <= DGV::Entity::Ability::Jetpack::SpawnChance)
	{
		RegisterJetpack(x, y, entity);

		return true;
	}
	else if (limitations(generator) <= DGV::Entity::Ability::Hat::SpawnChance)
	{
		RegisterHat(x, y, entity);

		return true;
	}

	return false;
}

void AbilityService::RemoveAbility(std::shared_ptr<Ability> ability)
{
	if (this->_abilities.empty())
	{
		return;
	}

	this->_abilities.erase(std::remove_if(
		this->_abilities.begin(),
		this->_abilities.end(),
		[&ability](const std::shared_ptr<Ability>& ptr) {
			return ptr == ability;
		}), this->_abilities.end());
}

void AbilityService::Update()
{
	updatePositions(RGV::LastTickDistance);

	auto iterator = this->_abilities.begin();

	while (iterator != this->_abilities.end())
	{
		(*iterator)->Update();

		++iterator;
	}
}

void AbilityService::updatePositions(int distance)
{
	if (this->_abilities.empty() || distance == 0)
	{
		return;
	}

	auto iterator = this->_abilities.begin();

	int x, y;

	while (iterator != this->_abilities.end())
	{
		(*iterator)->GetCoordinates(x, y);

		if (y > DGV::Window::CurrentHeight
			+ DGV::Entity::Ability::CurrentDestructionEdgeFromBottom)
		{
			iterator = this->_abilities.erase(iterator);
		}
		else
		{
			(*iterator)->SetCoordinates(x, y + distance);

			++iterator;
		}
	}
}

AbilityService::~AbilityService()
{
	this->_abilities.clear();
}