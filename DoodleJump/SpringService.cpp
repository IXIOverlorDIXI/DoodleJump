#include "SpringService.h"

void SpringService::ReInit()
{
	this->_springs.clear();
}

void SpringService::RegisterSpring(std::shared_ptr<Spring> spring)
{
	this->_springs.insert(this->_springs.begin(), spring);
}

void SpringService::registerTrampoline(int x, int y,
	std::shared_ptr<GameObject>& entity)
{
	std::string springSpritePath = DGS::SpriteRelativePath;
	springSpritePath.append(DGS::TrampolineSprite);

	std::shared_ptr<Spring> spring = std::make_shared<Spring>();

	int platformCenter = DGV::Entity::Platform::CurrentWidth / 2;
	int springCenter = DGV::Entity::Spring::Trampoline::CurrentWidth / 2;

	int entityX = x + platformCenter - springCenter,
		entityY = y - DGV::Entity::Spring::Trampoline::CurrentHeight;

	std::shared_ptr<RectangleCollider> collider =
		std::make_shared<RectangleCollider>();

	collider->Initialization(spring, ColliderTag::Spring,
		DGV::Collider::Priority::Spring,
		DGV::Collider::Spring::Trampoline::CurrentXIndent,
		DGV::Collider::Spring::Trampoline::CurrentYIndent,
		DGV::Collider::Spring::Trampoline::CurrentWidth,
		DGV::Collider::Spring::Trampoline::CurrentHeight, false);

	spring->Initialization(springSpritePath.c_str(),
		DGV::Entity::Spring::Trampoline::CurrentWidth,
		DGV::Entity::Spring::Trampoline::CurrentHeight, collider,
		DGV::Entity::Spring::Trampoline::JumpModifier, entityX, entityY);

	RegisterSpring(spring);

	entity = spring;
}

void SpringService::registerDefaultSpring(int x, int y,
	std::shared_ptr<GameObject>& entity)
{
	std::string springSpritePath = DGS::SpriteRelativePath;
	springSpritePath.append(DGS::DefaultSpringSprite);

	std::shared_ptr<Spring> spring = std::make_shared<Spring>();

	int platformCenter = DGV::Entity::Platform::CurrentWidth / 2;
	int springCenter = DGV::Entity::Spring::DefaultSpring::CurrentWidth / 2;

	int entityX = x + platformCenter - springCenter,
		entityY = y - DGV::Entity::Spring::DefaultSpring::CurrentHeight;

	std::shared_ptr<RectangleCollider> collider =
		std::make_shared<RectangleCollider>();

	collider->Initialization(spring, ColliderTag::Spring,
		DGV::Collider::Priority::Spring,
		DGV::Collider::Spring::DefaultSpring::CurrentXIndent,
		DGV::Collider::Spring::DefaultSpring::CurrentYIndent,
		DGV::Collider::Spring::DefaultSpring::CurrentWidth,
		DGV::Collider::Spring::DefaultSpring::CurrentHeight, false);

	spring->Initialization(springSpritePath.c_str(),
		DGV::Entity::Spring::DefaultSpring::CurrentWidth,
		DGV::Entity::Spring::DefaultSpring::CurrentHeight, collider,
		DGV::Entity::Spring::DefaultSpring::JumpModifier, entityX, entityY);

	RegisterSpring(spring);

	entity = spring;
}

void SpringService::RegisterRandomSpring(int x, int y,
	std::shared_ptr<GameObject>& entity)
{
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());

	std::uniform_int_distribution<int> limitations(0, 1);

	int springTypeNumber = limitations(generator);

	switch (springTypeNumber)
	{
	case 0:
		registerDefaultSpring(x, y, entity);
		break;
	case 1:
		registerTrampoline(x, y, entity);
		break;
	default:
		std::ostringstream errorMessage;
		errorMessage << "Chosen spring type: " << springTypeNumber << "does not support.";

		throw new std::runtime_error(errorMessage.str());
		break;
	}
}

void SpringService::RemoveSpring(std::shared_ptr<Spring> spring)
{
	if (this->_springs.empty())
	{
		return;
	}

	this->_springs.erase(std::remove_if(
		this->_springs.begin(),
		this->_springs.end(),
		[&spring](const std::shared_ptr<Spring>& ptr) {
			return ptr == spring;
		}), this->_springs.end());
}

void SpringService::Update()
{
	updatePositions(RGV::LastTickDistance);

	auto iterator = this->_springs.begin();

	while (iterator != this->_springs.end())
	{
		(*iterator)->Update();

		++iterator;
	}
}

void SpringService::updatePositions(int distance)
{
	if (this->_springs.empty() || distance == 0)
	{
		return;
	}

	auto iterator = this->_springs.begin();

	int x, y;

	while (iterator != this->_springs.end())
	{
		(*iterator)->GetCoordinates(x, y);

		if (y > DGV::Window::CurrentHeight
			+ DGV::Entity::Spring::CurrentDestructionEdgeFromBottom)
		{
			iterator = this->_springs.erase(iterator);
		}
		else
		{
			(*iterator)->SetCoordinates(x, y + distance);

			++iterator;
		}
	}
}

SpringService::~SpringService()
{
	this->_springs.clear();
}