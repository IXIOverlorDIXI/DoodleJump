#include "GameController.h"

void GameController::Initialize()
{
	setGlobalParameters();
	setBackground();
	setDoodle();

	ScoreService::GetInstance().Initialize();
	PlatformService::GetInstance().Initialization();
}

void GameController::Update()
{
	if (!RGV::IsAlive)
	{
		Restart();

		return;
	}

	CollisionService::GetInstance().SearchingCollision();

	this->_background->Update();

	PlatformService::GetInstance().Update();
	AbilityService::GetInstance().Update();
	SpringService::GetInstance().Update();
	EnemyService::GetInstance().Update();
	BulletService::GetInstance().Update();

	this->_doodle->Update();

	ScoreService::GetInstance().Update();

	std::cout << "Score: " << std::ceil(RGV::PlayerOverallScore)
		<< "\tJumped on platforms amount: " << RGV::PlayerPlatformJumpedOnCounter
		<< "\tJumped over platforms amount: " << RGV::PlayerPlatformJumpedOverCounter << std::endl;
}

void GameController::Restart()
{
	RGV::IsAlive = false;

	ScoreService::GetInstance().ReInit();
	CollisionService::GetInstance().ReInit();
	AbilityService::GetInstance().ReInit();
	SpringService::GetInstance().ReInit();
	EnemyService::GetInstance().ReInit();
	BulletService::GetInstance().ReInit();
	PlatformService::GetInstance().ReInit();
	this->_doodle->ReInit();

	RGV::IsAlive = true;

	std::system("clear || cls");
}

void GameController::setBackground()
{
	std::string spritePath = DGS::SpriteRelativePath;
	spritePath.append(DGS::BackgroundSprite);

	this->_background = std::make_unique<GameObject>();
	this->_background->Initialization(spritePath.c_str(),
		DGV::Window::CurrentWidth,
		DGV::Window::CurrentHeight);
}

void GameController::setDoodle()
{
	this->_doodle = std::make_shared<Doodle>();

	std::string spritePath = DGS::SpriteRelativePath;
	spritePath.append(DGS::DoodleRightSprite);

	_doodle->Initialization(spritePath.c_str(),
		DGV::Entity::Doodle::CurrentWidth,
		DGV::Entity::Doodle::CurrentHeight);
}

void GameController::setGlobalParameters()
{
	/*UI*/

	DGV::UI::Score::CurrentRowIndent = std::ceil((float)RGV::VerticalScale
		* DGV::UI::Score::DefaultRowIndent);
	DGV::UI::Score::CurrentOverallScoreCaptionWidth = std::ceil(
		(float)RGV::HorisontalScale 
		* DGV::UI::Score::DefaultOverallScoreCaptionWidth);
	DGV::UI::Score::CurrentOverallScoreCaptionHeight = std::ceil(
		(float)RGV::VerticalScale 
		* DGV::UI::Score::DefaultOverallScoreCaptionHeight);
	DGV::UI::Score::CurrentJumpedOnCaptionWidth = std::ceil(
		(float)RGV::HorisontalScale 
		* DGV::UI::Score::DefaultJumpedOnCaptionWidth);
	DGV::UI::Score::CurrentJumpedOnCaptionHeight = std::ceil(
		(float)RGV::VerticalScale
		* DGV::UI::Score::DefaultJumpedOnCaptionHeight);
	DGV::UI::Score::CurrentJumpedOverCaptionWidth = std::ceil(
		(float)RGV::HorisontalScale 
		* DGV::UI::Score::DefaultJumpedOverCaptionWidth);
	DGV::UI::Score::CurrentJumpedOverCaptionHeight = std::ceil(
		(float)RGV::VerticalScale
		* DGV::UI::Score::DefaultJumpedOverCaptionHeight);
	DGV::UI::Score::CurrentNumberWidth = std::ceil((float)RGV::HorisontalScale
		* DGV::UI::Score::DefaultNumberWidth);
	DGV::UI::Score::CurrentNumberHeight = std::ceil((float)RGV::VerticalScale
		* DGV::UI::Score::DefaultNumberHeight);

	/*Entities:*/

	DGV::Entity::Doodle::CurrentWidth = std::ceil((float)RGV::HorisontalScale
		* DGV::Entity::Doodle::DefaultWidth);
	DGV::Entity::Doodle::CurrentHeight = std::ceil((float)RGV::VerticalScale
		* DGV::Entity::Doodle::DefaultHeight);
	DGV::Entity::Doodle::CurrentHorisontalMoveSpeed = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Entity::Doodle::DefaultHorisontalMoveSpeed);
	DGV::Entity::Doodle::CurrentVerticalMoveSpeed = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Entity::Doodle::DefaultVerticalMoveSpeed);
	DGV::Entity::Doodle::CurrentJumpDistance = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Entity::Doodle::DefaultJumpDistance);

	DGV::Entity::Platform::CurrentWidth = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Entity::Platform::DefaultWidth);
	DGV::Entity::Platform::CurrentHeight = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Entity::Platform::DefaultHeight);
	DGV::Entity::Platform::CurrentCreationEdgeFromTop = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Entity::Platform::DefaultCreationEdgeFromTop);
	DGV::Entity::Platform::CurrentDestructionEdgeFromBottom = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Entity::Platform::DefaultDestructionEdgeFromBottom);
	DGV::Entity::Platform::CurrentMinSideIndentFromPrevious = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Entity::Platform::DefaultMinSideIndentFromPrevious);
	DGV::Entity::Platform::CurrentMinTopIndentFromPrevious = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Entity::Platform::DefaultMinTopIndentFromPrevious);
	DGV::Entity::Platform::CurrentMaxSideIndentFromPrevious = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Entity::Platform::DefaultMaxSideIndentFromPrevious);
	DGV::Entity::Platform::CurrentMaxTopIndentFromPrevious = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Entity::Platform::DefaultMaxTopIndentFromPrevious);
	DGV::Entity::Platform::CurrentBorderIndent = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Entity::Platform::DefaultBorderIndent);
	DGV::Entity::Platform::CurrentBottomCreationEdge = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Entity::Platform::DefaultBottomCreationEdge);

	DGV::Entity::Ability::CurrentDestructionEdgeFromBottom =
		std::ceil((float)RGV::VerticalScale
			* DGV::Entity::Ability::DefaultDestructionEdgeFromBottom);

	DGV::Entity::Ability::Hat::CurrentWidth =
		std::ceil((float)RGV::HorisontalScale
			* DGV::Entity::Ability::Hat::DefaultWidth);
	DGV::Entity::Ability::Hat::CurrentHeight =
		std::ceil((float)RGV::VerticalScale
			* DGV::Entity::Ability::Hat::DefaultHeight);

	DGV::Entity::Ability::Jetpack::CurrentWidth =
		std::ceil((float)RGV::HorisontalScale
			* DGV::Entity::Ability::Jetpack::DefaultWidth);
	DGV::Entity::Ability::Jetpack::CurrentHeight =
		std::ceil((float)RGV::VerticalScale
			* DGV::Entity::Ability::Jetpack::DefaultHeight);

	DGV::Entity::Bullet::CurrentDiameter = std::ceil(
		(float)(RGV::HorisontalScale + RGV::VerticalScale) / 2.0
		* DGV::Entity::Bullet::DefaultDiameter);
	DGV::Entity::Bullet::CurrentDestructionEdgeFromBorder = std::ceil(
		(float)(RGV::HorisontalScale
			+ RGV::VerticalScale) / 2.0
		* DGV::Entity::Bullet::DefaultDestructionEdgeFromBorder);
	DGV::Entity::Bullet::CurrentVelocity = std::ceil(
		(float)(RGV::HorisontalScale + RGV::VerticalScale) / 2.0
		* DGV::Entity::Bullet::DefaultVelocity);

	DGV::Entity::Enemy::CurrentWidth = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Entity::Enemy::DefaultWidth);
	DGV::Entity::Enemy::CurrentHeight = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Entity::Enemy::DefaultHeight);
	DGV::Entity::Enemy::CurrentIndentFromPlatform = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Entity::Enemy::DefaultIndentFromPlatform);
	DGV::Entity::Enemy::CurrentDestructionEdgeFromBottom = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Entity::Enemy::DefaultDestructionEdgeFromBottom);
	
	DGV::Entity::Spring::CurrentDestructionEdgeFromBottom = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Entity::Spring::DefaultDestructionEdgeFromBottom);

	DGV::Entity::Spring::DefaultSpring::CurrentWidth =
		std::ceil((float)RGV::HorisontalScale
			* DGV::Entity::Spring::DefaultSpring::DefaultWidth);
	DGV::Entity::Spring::DefaultSpring::CurrentHeight =
		std::ceil((float)RGV::VerticalScale
			* DGV::Entity::Spring::DefaultSpring::DefaultHeight);

	DGV::Entity::Spring::Trampoline::CurrentWidth =
		std::ceil((float)RGV::HorisontalScale
			* DGV::Entity::Spring::Trampoline::DefaultWidth);
	DGV::Entity::Spring::Trampoline::CurrentHeight =
		std::ceil((float)RGV::VerticalScale
			* DGV::Entity::Spring::Trampoline::DefaultHeight);

	/*Colliders:*/

	DGV::Collider::DoodleBullet::CurrentXIndent = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Collider::DoodleFeet::DefaultXIndent);
	DGV::Collider::DoodleBullet::CurrentYIndent = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Collider::DoodleBullet::DefaultYIndent);
	DGV::Collider::DoodleBullet::CurrentRadius = std::ceil(
		(float)(RGV::HorisontalScale + RGV::VerticalScale) / 2.0
		* DGV::Collider::DoodleBullet::DefaultRadius);

	DGV::Collider::DoodleFeet::CurrentXIndent = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Collider::DoodleFeet::DefaultXIndent);
	DGV::Collider::DoodleFeet::CurrentYIndent = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Collider::DoodleFeet::DefaultYIndent);
	DGV::Collider::DoodleFeet::CurrentWidth = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Collider::DoodleFeet::DefaultWidth);
	DGV::Collider::DoodleFeet::CurrentHeight = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Collider::DoodleFeet::DefaultHeight);

	DGV::Collider::DoodleBody::CurrentXIndent = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Collider::DoodleBody::DefaultXIndent);
	DGV::Collider::DoodleBody::CurrentYIndent = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Collider::DoodleBody::DefaultYIndent);
	DGV::Collider::DoodleBody::CurrentWidth = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Collider::DoodleBody::DefaultWidth);
	DGV::Collider::DoodleBody::CurrentHeight = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Collider::DoodleBody::DefaultHeight);

	DGV::Collider::Platform::CurrentXIndent = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Collider::Platform::DefaultXIndent);
	DGV::Collider::Platform::CurrentYIndent = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Collider::Platform::DefaultYIndent);
	DGV::Collider::Platform::CurrentWidth = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Collider::Platform::DefaultWidth);
	DGV::Collider::Platform::CurrentHeight = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Collider::Platform::DefaultHeight);

	DGV::Collider::EnemyHead::CurrentXIndent = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Collider::EnemyHead::DefaultXIndent);
	DGV::Collider::EnemyHead::CurrentYIndent = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Collider::EnemyHead::DefaultYIndent);
	DGV::Collider::EnemyHead::CurrentWidth = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Collider::EnemyHead::DefaultWidth);
	DGV::Collider::EnemyHead::CurrentHeight = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Collider::EnemyHead::DefaultHeight);

	DGV::Collider::EnemyBody::CurrentXIndent = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Collider::EnemyBody::DefaultXIndent);
	DGV::Collider::EnemyBody::CurrentYIndent = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Collider::EnemyBody::DefaultYIndent);
	DGV::Collider::EnemyBody::CurrentWidth = std::ceil(
		(float)RGV::HorisontalScale
		* DGV::Collider::EnemyBody::DefaultWidth);
	DGV::Collider::EnemyBody::CurrentHeight = std::ceil(
		(float)RGV::VerticalScale
		* DGV::Collider::EnemyBody::DefaultHeight);

	DGV::Collider::Ability::Jetpack::CurrentXIndent =
		std::ceil((float)RGV::HorisontalScale
			* DGV::Collider::Ability::Jetpack::DefaultXIndent);
	DGV::Collider::Ability::Jetpack::CurrentYIndent =
		std::ceil((float)RGV::VerticalScale
			* DGV::Collider::Ability::Jetpack::DefaultYIndent);
	DGV::Collider::Ability::Jetpack::CurrentWidth =
		std::ceil((float)RGV::HorisontalScale
			* DGV::Collider::Ability::Jetpack::DefaultWidth);
	DGV::Collider::Ability::Jetpack::CurrentHeight =
		std::ceil((float)RGV::VerticalScale
			* DGV::Collider::Ability::Jetpack::DefaultHeight);

	DGV::Collider::Ability::Hat::CurrentXIndent =
		std::ceil((float)RGV::HorisontalScale
			* DGV::Collider::Ability::Hat::DefaultXIndent);
	DGV::Collider::Ability::Hat::CurrentYIndent =
		std::ceil((float)RGV::VerticalScale
			* DGV::Collider::Ability::Hat::DefaultYIndent);
	DGV::Collider::Ability::Hat::CurrentWidth =
		std::ceil((float)RGV::HorisontalScale
			* DGV::Collider::Ability::Hat::DefaultWidth);
	DGV::Collider::Ability::Hat::CurrentHeight =
		std::ceil((float)RGV::VerticalScale
			* DGV::Collider::Ability::Hat::DefaultHeight);

	DGV::Collider::Spring::Trampoline::CurrentXIndent =
		std::ceil((float)RGV::HorisontalScale
			* DGV::Collider::Spring::Trampoline::DefaultXIndent);
	DGV::Collider::Spring::Trampoline::CurrentYIndent =
		std::ceil((float)RGV::VerticalScale
			* DGV::Collider::Spring::Trampoline::DefaultYIndent);
	DGV::Collider::Spring::Trampoline::CurrentWidth =
		std::ceil((float)RGV::HorisontalScale
			* DGV::Collider::Spring::Trampoline::DefaultWidth);
	DGV::Collider::Spring::Trampoline::CurrentHeight =
		std::ceil((float)RGV::VerticalScale
			* DGV::Collider::Spring::Trampoline::DefaultHeight);

	DGV::Collider::Spring::DefaultSpring::CurrentXIndent =
		std::ceil((float)RGV::HorisontalScale
			* DGV::Collider::Spring::DefaultSpring::DefaultXIndent);
	DGV::Collider::Spring::DefaultSpring::CurrentYIndent =
		std::ceil((float)RGV::VerticalScale
			* DGV::Collider::Spring::DefaultSpring::DefaultYIndent);
	DGV::Collider::Spring::DefaultSpring::CurrentWidth =
		std::ceil((float)RGV::HorisontalScale
			* DGV::Collider::Spring::DefaultSpring::DefaultWidth);
	DGV::Collider::Spring::DefaultSpring::CurrentHeight =
		std::ceil((float)RGV::VerticalScale
			* DGV::Collider::Spring::DefaultSpring::DefaultHeight);
}