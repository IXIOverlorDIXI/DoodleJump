#include "DefaultGameValues.h"

int DGV::Window::CurrentWidth = 640;
int DGV::Window::CurrentHeight = 480;

float DGV::Game::ScoreModifier = 5.0;

float DGV::Entity::Ability::FlyVelocityModifier = 1.5f;

float DGV::Entity::Spring::Trampoline::JumpModifier = 3.0f;
float DGV::Entity::Spring::DefaultSpring::JumpModifier = 2.0f;

float DGV::Entity::Spring::SpawnChance = 0.1f;
float DGV::Entity::Enemy::SpawnChance = 0.1f;
float DGV::Entity::Ability::Jetpack::SpawnChance = 0.01f;
float DGV::Entity::Ability::Hat::SpawnChance = 0.1f;

int DGV::UI::Score::CurrentRowIndent = 0;
int DGV::UI::Score::CurrentOverallScoreCaptionWidth = 0;
int DGV::UI::Score::CurrentOverallScoreCaptionHeight = 0;
int DGV::UI::Score::CurrentJumpedOnCaptionWidth = 0;
int DGV::UI::Score::CurrentJumpedOnCaptionHeight = 0;
int DGV::UI::Score::CurrentJumpedOverCaptionWidth = 0;
int DGV::UI::Score::CurrentJumpedOverCaptionHeight = 0;
int DGV::UI::Score::CurrentNumberWidth = 0;
int DGV::UI::Score::CurrentNumberHeight = 0;

int DGV::Entity::Doodle::CurrentWidth = 0;
int DGV::Entity::Doodle::CurrentHeight = 0;

int DGV::Entity::Doodle::CurrentJumpDistance = 0;
int DGV::Entity::Doodle::CurrentHorisontalMoveSpeed = 0;
int DGV::Entity::Doodle::CurrentVerticalMoveSpeed = 0;

int DGV::Entity::Platform::CurrentWidth = 0;
int DGV::Entity::Platform::CurrentHeight = 0;
int DGV::Entity::Platform::CurrentCreationEdgeFromTop = 0;
int DGV::Entity::Platform::CurrentDestructionEdgeFromBottom = 0;
int DGV::Entity::Platform::CurrentMinSideIndentFromPrevious = 0;
int DGV::Entity::Platform::CurrentMinTopIndentFromPrevious = 0;
int DGV::Entity::Platform::CurrentMaxSideIndentFromPrevious = 0;
int DGV::Entity::Platform::CurrentMaxTopIndentFromPrevious = 0;
int DGV::Entity::Platform::CurrentBottomCreationEdge = 0;
int DGV::Entity::Platform::CurrentBorderIndent = 0;

int DGV::Entity::Ability::CurrentDestructionEdgeFromBottom = 0;

int DGV::Entity::Enemy::CurrentWidth = 0;
int DGV::Entity::Enemy::CurrentHeight = 0;
int DGV::Entity::Enemy::CurrentIndentFromPlatform = 0;
int DGV::Entity::Enemy::CurrentDestructionEdgeFromBottom = 0;

int DGV::Entity::Bullet::CurrentDiameter = 0;
int DGV::Entity::Bullet::CurrentDestructionEdgeFromBorder = 0;
int DGV::Entity::Bullet::CurrentVelocity = 0;

int DGV::Entity::Ability::Jetpack::CurrentWidth = 0;
int DGV::Entity::Ability::Jetpack::CurrentHeight = 0;

int DGV::Entity::Spring::CurrentDestructionEdgeFromBottom = 0;

int DGV::Entity::Spring::DefaultSpring::CurrentWidth = 0;
int DGV::Entity::Spring::DefaultSpring::CurrentHeight = 0;

int DGV::Entity::Spring::Trampoline::CurrentWidth = 0;
int DGV::Entity::Spring::Trampoline::CurrentHeight = 0;

int DGV::Entity::Ability::Hat::CurrentWidth = 0;
int DGV::Entity::Ability::Hat::CurrentHeight = 0;

int DGV::Collider::DoodleBullet::CurrentXIndent = 0;
int DGV::Collider::DoodleBullet::CurrentYIndent = 0;
int DGV::Collider::DoodleBullet::CurrentRadius = 0;

int DGV::Collider::DoodleFeet::CurrentXIndent = 0;
int DGV::Collider::DoodleFeet::CurrentYIndent = 0;
int DGV::Collider::DoodleFeet::CurrentWidth = 0;
int DGV::Collider::DoodleFeet::CurrentHeight = 0;

int DGV::Collider::DoodleBody::CurrentXIndent = 0;
int DGV::Collider::DoodleBody::CurrentYIndent = 0;
int DGV::Collider::DoodleBody::CurrentWidth = 0;
int DGV::Collider::DoodleBody::CurrentHeight = 0;

int DGV::Collider::Platform::CurrentXIndent = 0;
int DGV::Collider::Platform::CurrentYIndent = 0;
int DGV::Collider::Platform::CurrentWidth = 0;
int DGV::Collider::Platform::CurrentHeight = 0;

int DGV::Collider::EnemyHead::CurrentXIndent = 0;
int DGV::Collider::EnemyHead::CurrentYIndent = 0;
int DGV::Collider::EnemyHead::CurrentWidth = 0;
int DGV::Collider::EnemyHead::CurrentHeight = 0;

int DGV::Collider::EnemyBody::CurrentXIndent = 0;
int DGV::Collider::EnemyBody::CurrentYIndent = 0;
int DGV::Collider::EnemyBody::CurrentWidth = 0;
int DGV::Collider::EnemyBody::CurrentHeight = 0;

int DGV::Collider::Ability::Jetpack::CurrentXIndent = 0;
int DGV::Collider::Ability::Jetpack::CurrentYIndent = 0;
int DGV::Collider::Ability::Jetpack::CurrentWidth = 0;
int DGV::Collider::Ability::Jetpack::CurrentHeight = 0;

int DGV::Collider::Spring::Trampoline::CurrentXIndent = 0;
int DGV::Collider::Spring::Trampoline::CurrentYIndent = 0;
int DGV::Collider::Spring::Trampoline::CurrentWidth = 0;
int DGV::Collider::Spring::Trampoline::CurrentHeight = 0;

int DGV::Collider::Spring::DefaultSpring::CurrentXIndent = 0;
int DGV::Collider::Spring::DefaultSpring::CurrentYIndent = 0;
int DGV::Collider::Spring::DefaultSpring::CurrentWidth = 0;
int DGV::Collider::Spring::DefaultSpring::CurrentHeight = 0;

int DGV::Collider::Ability::Hat::CurrentXIndent = 0;
int DGV::Collider::Ability::Hat::CurrentYIndent = 0;
int DGV::Collider::Ability::Hat::CurrentWidth = 0;
int DGV::Collider::Ability::Hat::CurrentHeight = 0;